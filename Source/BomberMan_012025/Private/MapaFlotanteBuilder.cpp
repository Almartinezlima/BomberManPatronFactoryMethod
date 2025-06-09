// MapaFlotanteBuilder.cpp - Implementación del Builder concreto para mapa flotante
#include "MapaFlotanteBuilder.h"

AMapaFlotanteBuilder::AMapaFlotanteBuilder()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AMapaFlotanteBuilder::BuildBordes()
{
    // Asegurarnos de que el tablero exista
    if (!TableroActual) return;

    // Construir los bordes superior e inferior
    for (int32 j = 0; j < TableroActual->Ancho; j++)
    {
        TableroActual->MapaBloques[0][j] = ATablero::ACERO;
        TableroActual->MapaBloques[1][j] = ATablero::ACERO;
        TableroActual->MapaBloques[2][j] = ATablero::ACERO;

        TableroActual->MapaBloques[TableroActual->Alto - 1][j] = ATablero::ACERO;
        TableroActual->MapaBloques[TableroActual->Alto - 2][j] = ATablero::ACERO;
        TableroActual->MapaBloques[TableroActual->Alto - 3][j] = ATablero::ACERO;
    }

    // Construir los bordes laterales
    for (int32 i = 3; i < TableroActual->Alto - 3; i++)
    {
        TableroActual->MapaBloques[i][0] = ATablero::ACERO;
        TableroActual->MapaBloques[i][1] = ATablero::ACERO;
        TableroActual->MapaBloques[i][2] = ATablero::ACERO;

        TableroActual->MapaBloques[i][TableroActual->Ancho - 1] = ATablero::ACERO;
        TableroActual->MapaBloques[i][TableroActual->Ancho - 2] = ATablero::ACERO;
        TableroActual->MapaBloques[i][TableroActual->Ancho - 3] = ATablero::ACERO;
    }
}

void AMapaFlotanteBuilder::BuildEstructuraInterna()
{
    // Asegurarnos de que el tablero exista
    if (!TableroActual) return;

    // Crear un patrón de rejilla con pasillos de al menos 3 bloques de ancho
    int32 grosorBorde = TableroActual->ANCHO_PASILLO + 2; // Considera el grosor del borde

    // Construir una rejilla con pasillos anchos
    for (int32 i = grosorBorde; i < TableroActual->Alto - grosorBorde; i++)
    {
        for (int32 j = grosorBorde; j < TableroActual->Ancho - grosorBorde; j++)
        {
            // Determinar si estamos en un pasillo horizontal o vertical
            bool esPasilloHorizontal = (i % 6 < TableroActual->ANCHO_PASILLO);
            bool esPasilloVertical = (j % 6 < TableroActual->ANCHO_PASILLO);

            if (esPasilloHorizontal || esPasilloVertical)
            {
                // Dejar espacio para el pasillo
                TableroActual->MapaBloques[i][j] = ATablero::VACIO;
            }
            else
            {
                // Crear un patrón alternado entre bloques de madera y ladrillo
                if ((i / 6 + j / 6) % 2 == 0)
                {
                    TableroActual->MapaBloques[i][j] = ATablero::LADRILLO;
                }
                else
                {
                    TableroActual->MapaBloques[i][j] = ATablero::MADERA;
                }
            }
        }
    }

    // Añadir algunas estructuras de concreto como obstáculos
    // Estos serán bloques de concreto 3x3 en algunas intersecciones de la rejilla
    for (int32 i = 0; i < 5; i++)
    {
        // Elegir una intersección aleatoria
        int32 interseccionX = FMath::RandRange(2, 6) * 6 + TableroActual->ANCHO_PASILLO / 2;
        int32 interseccionY = FMath::RandRange(2, 6) * 6 + TableroActual->ANCHO_PASILLO / 2;

        // Asegurarse de que no excede los límites
        if (interseccionX + 1 < TableroActual->Ancho - grosorBorde && interseccionY + 1 < TableroActual->Alto - grosorBorde)
        {
            // Crear un bloque de concreto 3x3
            for (int32 y = -1; y <= 1; y++)
            {
                for (int32 x = -1; x <= 1; x++)
                {
                    TableroActual->MapaBloques[interseccionY + y][interseccionX + x] = ATablero::CONCRETO;
                }
            }
        }
    }

    // Dejar espacios para que el jugador pueda moverse en las esquinas
    // Esquina superior izquierda
    for (int32 i = grosorBorde; i < grosorBorde + TableroActual->ANCHO_PASILLO; i++)
    {
        for (int32 j = grosorBorde; j < grosorBorde + TableroActual->ANCHO_PASILLO; j++)
        {
            TableroActual->MapaBloques[i][j] = ATablero::VACIO;
        }
    }

    // Esquina superior derecha
    for (int32 i = grosorBorde; i < grosorBorde + TableroActual->ANCHO_PASILLO; i++)
    {
        for (int32 j = TableroActual->Ancho - grosorBorde - TableroActual->ANCHO_PASILLO; j < TableroActual->Ancho - grosorBorde; j++)
        {
            TableroActual->MapaBloques[i][j] = ATablero::VACIO;
        }
    }

    // Esquina inferior izquierda
    for (int32 i = TableroActual->Alto - grosorBorde - TableroActual->ANCHO_PASILLO; i < TableroActual->Alto - grosorBorde; i++)
    {
        for (int32 j = grosorBorde; j < grosorBorde + TableroActual->ANCHO_PASILLO; j++)
        {
            TableroActual->MapaBloques[i][j] = ATablero::VACIO;
        }
    }

    // Esquina inferior derecha
    for (int32 i = TableroActual->Alto - grosorBorde - TableroActual->ANCHO_PASILLO; i < TableroActual->Alto - grosorBorde; i++)
    {
        for (int32 j = TableroActual->Ancho - grosorBorde - TableroActual->ANCHO_PASILLO; j < TableroActual->Ancho - grosorBorde; j++)
        {
            TableroActual->MapaBloques[i][j] = ATablero::VACIO;
        }
    }
}

void AMapaFlotanteBuilder::BuildPowerUps()
{
    // Asegurarnos de que el tablero exista
    if (!TableroActual) return;

    // Colocar vidrios en puntos estratégicos
    int32 grosorBorde = TableroActual->ANCHO_PASILLO + 2;
    int32 centroX = TableroActual->Ancho / 2;
    int32 centroY = TableroActual->Alto / 2;

    // PowerUp central
    TableroActual->MapaBloques[centroY][centroX] = ATablero::VIDRIO;

    // PowerUps en las cuatro esquinas interiores
    TableroActual->MapaBloques[grosorBorde + TableroActual->ANCHO_PASILLO][grosorBorde + TableroActual->ANCHO_PASILLO] = ATablero::VIDRIO;
    TableroActual->MapaBloques[grosorBorde + TableroActual->ANCHO_PASILLO][TableroActual->Ancho - grosorBorde - TableroActual->ANCHO_PASILLO - 1] = ATablero::VIDRIO;
    TableroActual->MapaBloques[TableroActual->Alto - grosorBorde - TableroActual->ANCHO_PASILLO - 1][grosorBorde + TableroActual->ANCHO_PASILLO] = ATablero::VIDRIO;
    TableroActual->MapaBloques[TableroActual->Alto - grosorBorde - TableroActual->ANCHO_PASILLO - 1][TableroActual->Ancho - grosorBorde - TableroActual->ANCHO_PASILLO - 1] = ATablero::VIDRIO;

    // PowerUps a lo largo de los pasillos principales
    // Horizontal central
    TableroActual->MapaBloques[centroY][centroX - 12] = ATablero::VIDRIO;
    TableroActual->MapaBloques[centroY][centroX + 12] = ATablero::VIDRIO;

    // Vertical central
    TableroActual->MapaBloques[centroY - 12][centroX] = ATablero::VIDRIO;
    TableroActual->MapaBloques[centroY + 12][centroX] = ATablero::VIDRIO;

    // Algunos PowerUps adicionales aleatorios
    for (int32 i = 0; i < 10; i++)
    {
        int32 randomX = FMath::RandRange(grosorBorde + 5, TableroActual->Ancho - grosorBorde - 5);
        int32 randomY = FMath::RandRange(grosorBorde + 5, TableroActual->Alto - grosorBorde - 5);

        // Colocar solo si hay un bloque (no en espacio vacío)
        if (TableroActual->MapaBloques[randomY][randomX] != ATablero::VACIO)
        {
            TableroActual->MapaBloques[randomY][randomX] = ATablero::VIDRIO;
        }
    }
}
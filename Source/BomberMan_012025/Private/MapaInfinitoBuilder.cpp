// MapaInfinitoBuilder.cpp - Implementación del Builder concreto para mapa infinito
#include "MapaInfinitoBuilder.h"

AMapaInfinitoBuilder::AMapaInfinitoBuilder()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AMapaInfinitoBuilder::BuildBordes()
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

void AMapaInfinitoBuilder::BuildEstructuraInterna()
{
    // Asegurarnos de que el tablero exista
    if (!TableroActual) return;

    // Crear una estructura interna en forma de "8"
    // Tendremos dos círculos conectados
    int32 mitad = TableroActual->Alto / 2;
    int32 grosorBorde = TableroActual->ANCHO_PASILLO + 2; // Los bordes externos más el pasillo

    // Sección central horizontal para dividir en dos círculos
    int32 anchoSeccionCentral = 6; // 6 bloques de grosor para la sección central

    // Crear la sección horizontal central
    for (int32 i = mitad - anchoSeccionCentral / 2; i < mitad + anchoSeccionCentral / 2; i++)
    {
        for (int32 j = grosorBorde + TableroActual->ANCHO_PASILLO; j < TableroActual->Ancho - grosorBorde - TableroActual->ANCHO_PASILLO; j++)
        {
            // Dejar pasillos a los lados
            if (j % 9 < TableroActual->ANCHO_PASILLO)
            {
                TableroActual->MapaBloques[i][j] = ATablero::VACIO;
            }
            else
            {
                TableroActual->MapaBloques[i][j] = ATablero::CONCRETO;
            }
        }
    }

    // Crear círculos concéntricos en los dos hemisferios
    int32 radioExterior = (mitad - anchoSeccionCentral / 2 - grosorBorde) / 2;
    int32 radioInterior = radioExterior - TableroActual->ANCHO_PASILLO;

    // Centro del círculo superior e inferior
    int32 centroXSuperior = TableroActual->Ancho / 2;
    int32 centroYSuperior = grosorBorde + radioExterior;

    int32 centroXInferior = TableroActual->Ancho / 2;
    int32 centroYInferior = TableroActual->Alto - grosorBorde - radioExterior;

    // Dibujar los círculos internos del 8
    for (int32 i = grosorBorde; i < mitad - anchoSeccionCentral / 2; i++)
    {
        for (int32 j = grosorBorde; j < TableroActual->Ancho - grosorBorde; j++)
        {
            // Calcular distancia al centro del círculo superior
            float distanciaSuperior = FMath::Sqrt(FMath::Square((float)(i - centroYSuperior)) + FMath::Square((float)(j - centroXSuperior)));

            // Crear anillo en el círculo superior
            if (distanciaSuperior <= radioExterior && distanciaSuperior >= radioInterior)
            {
                TableroActual->MapaBloques[i][j] = ATablero::LADRILLO;
            }
        }
    }

    for (int32 i = mitad + anchoSeccionCentral / 2; i < TableroActual->Alto - grosorBorde; i++)
    {
        for (int32 j = grosorBorde; j < TableroActual->Ancho - grosorBorde; j++)
        {
            // Calcular distancia al centro del círculo inferior
            float distanciaInferior = FMath::Sqrt(FMath::Square((float)(i - centroYInferior)) + FMath::Square((float)(j - centroXInferior)));

            // Crear anillo en el círculo inferior
            if (distanciaInferior <= radioExterior && distanciaInferior >= radioInterior)
            {
                TableroActual->MapaBloques[i][j] = ATablero::LADRILLO;
            }
        }
    }

    // Agregar bloques de madera aleatorios en las zonas interiores de los círculos
    // Círculo superior interior
    for (int32 i = grosorBorde; i < mitad - anchoSeccionCentral / 2; i++)
    {
        for (int32 j = grosorBorde; j < TableroActual->Ancho - grosorBorde; j++)
        {
            float distancia = FMath::Sqrt(FMath::Square((float)(i - centroYSuperior)) + FMath::Square((float)(j - centroXSuperior)));

            // Interior del círculo
            if (distancia < radioInterior)
            {
                // Asegurar que dejamos grupos de 3x3 vacíos para pasillos
                if (i % 6 < 3 && j % 6 < 3)
                {
                    TableroActual->MapaBloques[i][j] = ATablero::VACIO; // Garantizar pasillos
                }
                else if (FMath::RandRange(0, 10) > 6)
                {
                    TableroActual->MapaBloques[i][j] = ATablero::MADERA;
                }
            }
        }
    }

    // Círculo inferior interior
    for (int32 i = mitad + anchoSeccionCentral / 2; i < TableroActual->Alto - grosorBorde; i++)
    {
        for (int32 j = grosorBorde; j < TableroActual->Ancho - grosorBorde; j++)
        {
            float distancia = FMath::Sqrt(FMath::Square((float)(i - centroYInferior)) + FMath::Square((float)(j - centroXInferior)));

            // Interior del círculo
            if (distancia < radioInterior)
            {
                // Asegurar que dejamos grupos de 3x3 vacíos para pasillos
                if (i % 6 < 3 && j % 6 < 3)
                {
                    TableroActual->MapaBloques[i][j] = ATablero::VACIO; // Garantizar pasillos
                }
                else if (FMath::RandRange(0, 10) > 6)
                {
                    TableroActual->MapaBloques[i][j] = ATablero::MADERA;
                }
            }
        }
    }
}

void AMapaInfinitoBuilder::BuildPowerUps()
{
    // Asegurarnos de que el tablero exista
    if (!TableroActual) return;

    // Colocar vidrios en puntos estratégicos
    int32 mitad = TableroActual->Alto / 2;
    int32 grosorBorde = TableroActual->ANCHO_PASILLO + 2;

    // En el círculo superior
    TableroActual->MapaBloques[grosorBorde + 5][grosorBorde + 5] = ATablero::VIDRIO;
    TableroActual->MapaBloques[grosorBorde + 5][TableroActual->Ancho - grosorBorde - 5] = ATablero::VIDRIO;

    // En el círculo inferior
    TableroActual->MapaBloques[TableroActual->Alto - grosorBorde - 5][grosorBorde + 5] = ATablero::VIDRIO;
    TableroActual->MapaBloques[TableroActual->Alto - grosorBorde - 5][TableroActual->Ancho - grosorBorde - 5] = ATablero::VIDRIO;

    // En el centro del 8 (cruce)
    TableroActual->MapaBloques[mitad][TableroActual->Ancho / 2] = ATablero::VIDRIO;

    // Algunos PowerUps adicionales aleatorios
    for (int32 i = 0; i < 8; i++)
    {
        int32 randomX = FMath::RandRange(grosorBorde + 5, TableroActual->Ancho - grosorBorde - 5);
        int32 randomY = FMath::RandRange(grosorBorde + 5, TableroActual->Alto - grosorBorde - 5);

        // Solo colocar si hay un bloque (no en espacio vacío)
        if (TableroActual->MapaBloques[randomY][randomX] != ATablero::VACIO)
        {
            TableroActual->MapaBloques[randomY][randomX] = ATablero::VIDRIO;
        }
    }
}

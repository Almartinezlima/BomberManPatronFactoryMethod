// MapaBuilder.cpp - Implementaci?n de la clase Builder abstracta
#include "MapaBuilder.h"

AMapaBuilder::AMapaBuilder()
{
    PrimaryActorTick.bCanEverTick = false;
    TableroActual = nullptr;
}

void AMapaBuilder::Reset()
{
    // Destruir el tablero anterior si existe
    if (TableroActual)
    {
        TableroActual->Destroy();
        TableroActual = nullptr;
    }

    // Crear un nuevo tablero
    TableroActual = GetWorld()->SpawnActor<ATablero>(ATablero::StaticClass());

    if (TableroActual)
    {
        // Inicializar la matriz del tablero
        TableroActual->IniciarMatriz();
    }
}

TArray<TArray<int32>> AMapaBuilder::GetResultado()
{
    if (TableroActual)
    {
        return TableroActual->MapaBloques;
    }

    // Devuelve la matriz de bloques del tablero construido, Si no hay tablero, devuelve una matriz vacía.
    return TArray<TArray<int32>>();
}
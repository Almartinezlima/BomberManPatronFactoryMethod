// DirectorMapa.cpp - Implementaci�n del Director
#include "DirectorMapa.h"

ADirectorMapa::ADirectorMapa()
{
    PrimaryActorTick.bCanEverTick = false;
    BuilderActual = nullptr;
}

//Asigna el builder concreto que se va a utilizar para construir el tablero.
void ADirectorMapa::SetBuilder(AMapaBuilder* NuevoBuilder)
{
    BuilderActual = NuevoBuilder;
}

//Reinicia el builder y crea un nuevo tablero
void ADirectorMapa::ConstruirMapa()
{
    if (BuilderActual)
    {
        BuilderActual->Reset();
        BuilderActual->BuildBordes();
        BuilderActual->BuildEstructuraInterna();
    }
}

void ADirectorMapa::ConstruirMapaConPowerUps()
{
    if (BuilderActual)
    {
        BuilderActual->Reset();
        BuilderActual->BuildBordes();
        BuilderActual->BuildEstructuraInterna();
        BuilderActual->BuildPowerUps();
    }
}

TArray<TArray<int32>> ADirectorMapa::ObtenerMapa()
{
    if (BuilderActual)
    {
        return BuilderActual->GetResultado();
    }

    // Devolver una matriz vac�a si no hay builder
    return TArray<TArray<int32>>();
}

//•	El director no construye el tablero directamente, sino que llama a los métodos 
// del builder en el orden correcto
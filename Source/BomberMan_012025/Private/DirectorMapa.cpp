// DirectorMapa.cpp - Implementaci�n del Director
#include "DirectorMapa.h"

ADirectorMapa::ADirectorMapa()
{
    PrimaryActorTick.bCanEverTick = false;
    BuilderActual = nullptr;
}

void ADirectorMapa::SetBuilder(AMapaBuilder* NuevoBuilder)
{
    BuilderActual = NuevoBuilder;
}

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
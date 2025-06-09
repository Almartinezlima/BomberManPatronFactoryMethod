#include "Tablero.h"

ATablero::ATablero()
{
    PrimaryActorTick.bCanEverTick = false;
}

void ATablero::IniciarMatriz()
{
    // Redimensionar la matriz nativa
    MapaBloques.SetNum(Alto);
    for (int32 i = 0; i < Alto; ++i)
    {
        MapaBloques[i].SetNum(Ancho);
        for (int32 j = 0; j < Ancho; ++j)
        {
            MapaBloques[i][j] = VACIO;
        }
    }
}

void ATablero::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    IniciarMatriz();
}
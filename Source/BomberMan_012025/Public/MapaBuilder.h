// MapaBuilder.h - Definici?n de la clase Builder abstracta
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tablero.h"
#include "MapaBuilder.generated.h"

UCLASS(Abstract)
class BOMBERMAN_012025_API AMapaBuilder : public AActor
{
    GENERATED_BODY()

public:
    // Constructor
    AMapaBuilder();

    // El producto que estamos construyendo
    UPROPERTY(VisibleAnywhere, Category = "Builder")
    ATablero* TableroActual;

    // M?todos para la construcci?n por pasos del mapa
    virtual void BuildBordes() PURE_VIRTUAL(AMapaBuilder::BuildBordes, );
    virtual void BuildEstructuraInterna() PURE_VIRTUAL(AMapaBuilder::BuildEstructuraInterna, );
    virtual void BuildPowerUps() PURE_VIRTUAL(AMapaBuilder::BuildPowerUps, );

    // M?todo para reiniciar el builder y crear un nuevo tablero
    virtual void Reset();

    // M?todo para obtener el producto final (matriz de bloques)
    TArray<TArray<int32>> GetResultado();

    // M?todo para obtener la referencia al tablero completo
    ATablero* GetTablero() const { return TableroActual; }
};
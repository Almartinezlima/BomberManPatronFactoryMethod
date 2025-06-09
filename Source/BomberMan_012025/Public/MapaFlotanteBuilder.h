// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MapaBuilder.h"
#include "MapaFlotanteBuilder.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AMapaFlotanteBuilder : public AMapaBuilder
{
	GENERATED_BODY()
	
public:
    AMapaFlotanteBuilder();

    // Implementaciones espec?ficas para el mapa plano
    virtual void BuildBordes() override;
    virtual void BuildEstructuraInterna() override;
    virtual void BuildPowerUps() override;
};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MapaBuilder.h"
#include "MapaInfinitoBuilder.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AMapaInfinitoBuilder : public AMapaBuilder
{
	GENERATED_BODY()

public:
    AMapaInfinitoBuilder();

    virtual void BuildBordes() override;
    virtual void BuildEstructuraInterna() override;
    virtual void BuildPowerUps() override;
	
};

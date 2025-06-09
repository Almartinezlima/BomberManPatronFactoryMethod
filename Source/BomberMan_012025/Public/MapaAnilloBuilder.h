// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MapaBuilder.h"
#include "MapaAnilloBuilder.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AMapaAnilloBuilder : public AMapaBuilder
{
	GENERATED_BODY()

public:
    AMapaAnilloBuilder();

    virtual void BuildBordes() override;
    virtual void BuildEstructuraInterna() override;
    virtual void BuildPowerUps() override;
	
};

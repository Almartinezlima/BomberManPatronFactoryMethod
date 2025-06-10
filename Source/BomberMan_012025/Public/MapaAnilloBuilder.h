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
    AMapaAnilloBuilder();//declaran la clase concreta que implementa los métodos virtuales del builder base para crear un mapa 

    virtual void BuildBordes() override;
    virtual void BuildEstructuraInterna() override;
    virtual void BuildPowerUps() override;
	
};

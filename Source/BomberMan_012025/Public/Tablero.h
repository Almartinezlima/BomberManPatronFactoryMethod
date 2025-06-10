// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tablero.generated.h"

UCLASS()
class BOMBERMAN_012025_API ATablero : public AActor
{
	GENERATED_BODY()
	
public:	
public:
    ATablero();

    // Matriz bidimensional nativa de C++ (no expuesta a Blueprints)
    TArray<TArray<int32>> MapaBloques;

    // Dimensiones del tablero
    int32 Ancho = 50;
    int32 Alto = 50;

    // Constantes de tipos de bloques
    static const int32 VACIO = 0;
    static const int32 MADERA = 1;
    static const int32 LADRILLO = 2;
    static const int32 CONCRETO = 3;
    static const int32 ACERO = 4;
    static const int32 VIDRIO = 5;

    static const int32 ANCHO_PASILLO = 3;

    void IniciarMatriz();

protected:
    virtual void OnConstruction(const FTransform& Transform) override;
};

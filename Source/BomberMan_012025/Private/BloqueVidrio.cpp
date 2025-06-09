// Fill out your copyright notice in the Description page of Project Settings.

#include "BloqueVidrio.h"
#include "UObject/ConstructorHelpers.h"

ABloqueVidrio::ABloqueVidrio()
{
    if (MallaBloque)
    {
        static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Basic_Floor.M_Basic_Floor'"));

        if (MaterialBase.Succeeded())
        {
            MallaBloque->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
        }
    }
}
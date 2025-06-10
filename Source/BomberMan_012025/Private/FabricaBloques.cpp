// FabricaBloques.cpp - Versión corregida
#include "FabricaBloques.h"
#include "BloqueAcero.h"
#include "BloqueVidrio.h"
#include "BloqueConcreto.h"
#include "BloqueLadrillo.h"
#include "BloqueMadera.h"

// Sets default values
AFabricaBloques::AFabricaBloques()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFabricaBloques::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AFabricaBloques::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

ABloque* AFabricaBloques::CrearBloque(FString tipoBloque, FVector posicion)
{
    if (tipoBloque.Equals("Acero")) {
        return GetWorld()->SpawnActor<ABloqueAcero>
            (ABloqueAcero::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
    }
    else if (tipoBloque.Equals("Concreto")) {
        return GetWorld()->SpawnActor<ABloqueConcreto>
            (ABloqueConcreto::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
    }
    else if (tipoBloque.Equals("Ladrillo")) {
        return GetWorld()->SpawnActor<ABloqueLadrillo>
            (ABloqueLadrillo::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
    }
    else if (tipoBloque.Equals("Madera")) {
        return GetWorld()->SpawnActor<ABloqueMadera>
            (ABloqueMadera::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
    }
    else if (tipoBloque.Equals("Vidrio")) {
        return GetWorld()->SpawnActor<ABloqueVidrio>
            (ABloqueVidrio::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
    }
    else return nullptr;
}

//Instancia y retorna un actor de bloque del tipo especificado en la posición indicada.
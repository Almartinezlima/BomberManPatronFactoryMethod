// DirectorMapa.h - Director
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapaBuilder.h"
#include "DirectorMapa.generated.h"

UCLASS()
class BOMBERMAN_012025_API ADirectorMapa : public AActor
{
    GENERATED_BODY()

public:
    ADirectorMapa();

    // M�todos para configurar el builder a utilizar
    void SetBuilder(AMapaBuilder* NuevoBuilder);

    // M�todo para construir el mapa completo
    void ConstruirMapa();

    // M�todo para construir mapa con powerups espec�ficos
    void ConstruirMapaConPowerUps();

    // Obtener el resultado del builder actual
    TArray<TArray<int32>> ObtenerMapa();

private:
    // Builder actual
    AMapaBuilder* BuilderActual;
};
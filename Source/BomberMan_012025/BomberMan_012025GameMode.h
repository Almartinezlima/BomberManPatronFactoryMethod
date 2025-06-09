#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BomberMan_012025GameMode.generated.h"
class ABloque;
class AFabricaBloques;
class ADirectorMapa;
class ATablero;
UCLASS(minimalapi)
class ABomberMan_012025GameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ABomberMan_012025GameMode();

    virtual void BeginPlay() override;

    // F?brica para crear los diferentes tipos de bloques (sin UPROPERTY)
    AFabricaBloques* FabricaDeBloques;

    // Director del patr?n Builder (sin UPROPERTY)
    ADirectorMapa* DirectorMapa;

    // Tablero actual del juego (sin UPROPERTY)
    ATablero* TableroJuego;

    // Array con todos los bloques creados (se mantiene UPROPERTY por ser contenedor de UObjects)
    UPROPERTY(VisibleAnywhere, Category = "Bloques")
    TArray<ABloque*> aBloques;

    // Matriz nativa C++ (sin UPROPERTY)
    TArray<TArray<int32>> aMapaBloques;
    // Posici?n inicial de los bloques
    UPROPERTY(EditAnywhere, Category = "Spawns")
    float XInicial = 0.0f;

    UPROPERTY(EditAnywhere, Category = "Spawns")
    float YInicial = 0.0f;

    // Tama?o de los bloques
    UPROPERTY(EditAnywhere, Category = "Spawns")
    float AnchoBloque = 100.0f;

    UPROPERTY(EditAnywhere, Category = "Spawns")
    float LargoBloque = 100.0f;

    // M?todos para la gesti?n de bloques
    UFUNCTION(BlueprintCallable, Category = "GamePlay")
    void SpawnBloque(FVector posicion, int32 tipoBloque);

    UFUNCTION(BlueprintCallable, Category = "GamePlay")
    void DestruirBloque();

    // Referencia al bloque que se va a destruir
    UPROPERTY(VisibleAnywhere)
    ABloque* BloqueActual;

    // M?todo para construir un mapa seg?n el tipo especificado
    ATablero* ConstruirMapa(FString TipoMapa);
};
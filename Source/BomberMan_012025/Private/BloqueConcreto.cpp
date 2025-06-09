#include "BloqueConcreto.h"
#include "UObject/ConstructorHelpers.h"

ABloqueConcreto::ABloqueConcreto()
{
    if (MallaBloque)
    {
        // Cargar el material de ladrillo beveled
        static ConstructorHelpers::FObjectFinder<UMaterial> MaterialConcreto(
            TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Brick_Clay_Beveled.M_Brick_Clay_Beveled'")
        );

        if (MaterialConcreto.Succeeded())
        {
            MallaBloque->SetMaterial(0, MaterialConcreto.Object); // Asignar el material al slot 0
        }
    }
}
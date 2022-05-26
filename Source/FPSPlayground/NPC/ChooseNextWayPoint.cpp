// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextWayPoint.h"
#include "AIController.h"
#include "PatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get Patrol Points
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();
	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }
	auto PatrolPoints = PatrolRoute->GetPatrolPoints();

	// Warn about empty patrol routes
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("A Guard is missing patrol points."));
		return EBTNodeResult::Failed;
	}
	
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexSelector.SelectedKeyName);
	BlackboardComp->SetValueAsObject(NextWaypointSelector.SelectedKeyName, PatrolPoints[Index]);

	// Cycle the index
	Index += 1;
	if (Index == PatrolPoints.Num())
	{
		Index = 0;
	}
	BlackboardComp->SetValueAsInt(IndexSelector.SelectedKeyName, Index);
	return EBTNodeResult::Succeeded;
}

#include "World.h"
#include "Actor.h"

World::World()
{
}

World::~World()
{
	//for (int i = 0; i < ActorList.size(); ++i)
	//{
	//	delete ActorList[i];
	//	ActorList[i] = nullptr;
	//}

	//for (auto iter = ActorList.begin(); iter != ActorList.end(); ++iter)
	////for (std::vector<Actor*>::iterator iter = ActorList.begin(); iter != ActorList.end(); ++iter)
	//{
	//	delete *iter;
	//	*iter = nullptr;
	//}

	for (auto CurrentActor : ActorList)
	{
		delete CurrentActor;
		CurrentActor = nullptr;
	}

	ActorList.clear();
}

void World::SpawnActor(Actor* NewActor)
{
	ActorList.push_back(NewActor);
}

void World::DestroyActor(Actor* DestroyActor)
{
	//for (auto iter = ActorList.begin(); iter != ActorList.end(); ++iter)
	//{
	//	if (*iter == DestroyActor)
	//	{
	//		delete *iter;
	//		*iter = nullptr;
	//		//important 
	//		iter = ActorList.erase(iter);
	//		break;
	//	}
	//}

	//auto DestroyIter = find(ActorList.begin(), ActorList.end(), DestroyActor);
	//ActorList.erase(DestroyIter);

	ActorList.erase(find(ActorList.begin(), ActorList.end(), DestroyActor));
	delete DestroyActor;
	DestroyActor = nullptr;
}

void World::Tick()
{
	for (auto SelectedActor : ActorList)
	{
		SelectedActor->Tick();
	}
}

void World::Render()
{
	for (auto SelectedActor : ActorList)
	{
		SelectedActor->Render();
	}
}

void World::Input()
{
}

void World::BeginPlay()
{
	for (auto SelectedActor : ActorList)
	{
		SelectedActor->BeginPlay();
	}
}

#pragma once
#include "Application.h"


Application::Application()
{
	
	ModuleWindow* pWindow = new ModuleWindow();
	ModuleRender* pRender = new ModuleRender();
	AddModule(pWindow);
	AddModule(pRender);
}

bool Application::Init()
{
	bool ret = true;
	DList<Module*>* item = list_modules.getStart();

	while(item != NULL && ret == true)
	{
		ret = item->data->Init();
		item = item->next;
	}

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;
	DList<Module*>* node = list_modules.getStart();

	while(node != NULL && ret == UPDATE_CONTINUE)
	{
		ret = node->data->Update();
		node = item->next;
	}

	// TODO: fer que torni false si algun Init torna false
	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;
	DList<Module*>* item = list_modules.getEnd();

	while(item != NULL && ret == true)
	{
		ret = item->data->CleanUp();
		item = item->previous;
	}
	return ret;
}

void Application::AddModule(Module* mod)
{
	list_modules.Add(mod);
}
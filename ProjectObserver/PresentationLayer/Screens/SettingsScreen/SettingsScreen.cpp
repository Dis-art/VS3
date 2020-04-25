#include <iostream>
#include <string>
#include <vector>
#include "SettingsScreen.h"
#include "../../Localization/Localizable/Localizable.h"
#include "../../Localization/Localizer/Localizer.h"

using namespace std;

SettingsScreen::SettingsScreen()
{
	screenTable = new Table();//"Settings"

	Cell* languagesCell = new Cell();//"Languages"
	
	languagesCell->buttons.push_back(new Button());//"Follow"
	screenTable->cells.push_back(languagesCell);

	Cell* screenCell = new Cell();//"Screen"
	screenCell->buttons.push_back(new Button());//"Follow"
	screenTable->cells.push_back(screenCell);

	Cell* securityCell = new Cell();//"Security"
	securityCell->buttons.push_back(new Button());//"Follow"
	screenTable->cells.push_back(securityCell);

	screenButtons.push_back(new Button());//"Exit"

	this->localizer->subscribe(this);
}

SettingsScreen::~SettingsScreen()
{
	this->localizer->unsubscribe(this);
}

void SettingsScreen::localize(Language lang)
{
	switch (lang)
	{
	case Language::English:
		screenTable->title = "Settings";
		screenTable->cells[0]->title = "Languages";
		screenTable->cells[0]->buttons[0]->title = "Follow";
		screenTable->cells[1]->title = "Screen";
		screenTable->cells[1]->buttons[0]->title = "Follow";
		screenTable->cells[2]->title = "Security";
		screenTable->cells[2]->buttons[0]->title = "Follow";
		screenButtons[0]->title = "Exit";
		break;
	case Language::Russian:
		screenTable->title = "���������";
		screenTable->cells[0]->title = "�����";
		screenTable->cells[0]->buttons[0]->title = "�������";
		screenTable->cells[1]->title = "�����";
		screenTable->cells[1]->buttons[0]->title = "�������";
		screenTable->cells[2]->title = "������������";
		screenTable->cells[2]->buttons[0]->title = "�������";
		screenButtons[0]->title = "�����";
		break;
	}
}

string SettingsScreen::getDescription()
{
	return " SettingsScreen\n" + Screen::getDescription();
}

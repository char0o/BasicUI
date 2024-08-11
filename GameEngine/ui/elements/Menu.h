#pragma once
#include "BasePanel.h"
class Menu : public BasePanel
{
public:
	Menu();
	~Menu();
	void OnMouseOver() override;
	void OnMouseExit() override;
	void OnMouseClick() override;
private:
};
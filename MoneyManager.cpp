using namespace std;

#include "MoneyManager.h"

#include<iostream>
#include<fstream>


	int MoneyManager::totalMoney = 50; 
	int MoneyManager::rodPrice = 2; 
	int MoneyManager::gunPrice = 10; 
	int MoneyManager::netPrice = 30; 
	int MoneyManager::lightningPrice = 50;
	int MoneyManager::bpPrice =	80; 
	int MoneyManager::goldfishPrice	= 5; 
	int MoneyManager::seahorsePrice	= 8;
	int MoneyManager::sharkPrice = 12; 
	int MoneyManager::octopusPrice = 16; 
	int MoneyManager::tritonPrice =	20; 
	int MoneyManager::totalPoints = 0;

bool MoneyManager::hasMoney(Tower * tow) {
	int towPrice;
	
	//These next lines check what type of Tower tow is then set the correct price.
	if (tow->type=="Gun") towPrice=gunPrice;
	else if (tow->type=="Rod") towPrice=rodPrice;
	else if (tow->type=="Net") towPrice=netPrice;
	else if (tow->type=="BP") towPrice=bpPrice;
	else if (tow->type=="Lightning") towPrice=lightningPrice;

	cout << "Money: " << totalMoney << ". Buying:" << towPrice << endl;

	if (totalMoney >= towPrice) return true;
	else return false;
}

void MoneyManager::takeMoney(Tower * tow) {
	
	int towPrice;
	//These next lines check what type of Tower tow is then take the amount away
	if (tow->type=="Gun") towPrice =gunPrice;
	else if (tow->type=="Rod") towPrice =rodPrice;
	else if (tow->type=="Net") towPrice =netPrice;
	else if (tow->type=="BP") towPrice =bpPrice;
	else if (tow->type=="Lightning") towPrice =lightningPrice;

	cout << "Money:" << totalMoney << ". Bought:" << towPrice << endl;

	MoneyManager::totalMoney -= towPrice;
	
}

void MoneyManager::addMoney(Enemy * en) {
	
	int enAdd;
	//These next lines check what type of Tower tow is then take the amount away
	if (en->type=="Octopus") enAdd =octopusPrice;
	else if (en->type=="Shark") enAdd =sharkPrice;
	else if (en->type=="Goldfish") enAdd =goldfishPrice;
	else if (en->type=="Triton") enAdd =tritonPrice;
	else if (en->type=="Seahorse") enAdd =seahorsePrice;

	cout << "Money:" << totalMoney << ". Earned:" << enAdd << endl;

	MoneyManager::totalMoney += enAdd;
	MoneyManager::totalPoints += enAdd*10;
}


void MoneyManager::addMoney(int reward) {
	totalMoney+=reward;
}

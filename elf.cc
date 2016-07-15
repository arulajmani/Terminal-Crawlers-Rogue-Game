#include "elf.h"
using namespace std;
const int defaultHP = 140;
const int defaultAtk = 30;
const int defaultDef = 10;

Elf::Elf(): Player{"Elf", defaultHP, defaultDef, defaultAtk} {}
Elf::~Elf() {}

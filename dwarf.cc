#include "dwarf.h"

const int defaultHP = 100;
const int defaultAtk = 20;
const int defaultDef = 30;

Dwarf::Dwarf(): Player{"Dwarf", defaultHP, defaultDef, defaultAtk} {}
Dwarf::~Dwarf() {}
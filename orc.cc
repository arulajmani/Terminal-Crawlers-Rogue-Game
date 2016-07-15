#include "orc.h"

const int defaultHP = 180;
const int defaultAtk = 30;
const int defaultDef = 25;

Orc::Orc(): Player{"Orc", defaultHP, defaultDef, defaultAtk} {}
Orc::~Orc() {}
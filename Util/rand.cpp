unsigned int seed = 2023; // this year
short rand_short_15bit() {
    seed = seed * 214013 + 2531011;
    return (seed >> 16) & 0x7FFF;
}

int rand_int_30bit() {
    return (rand_short_15bit() << 15) | rand_short_15bit();
}

float rand_float() {
    return (float)((rand() % 20000) - 10000 + (rand() % 10000) / 10000.0);
}

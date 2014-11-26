#include "sysdeps.h"
#include "m68000.h"

int get_interrupt_level(void) {
}

uae_u32 get_long(uaecptr addr) {
	return 0;
}
uae_u32 get_word(uaecptr addr) {
	return 0;
}
uae_u32 get_byte(uaecptr addr) {
	return 0;
}
void put_long(uaecptr addr, uae_u32 l) {
}
void put_word(uaecptr addr, uae_u32 w) {
}
void put_byte(uaecptr addr, uae_u32 b) {
}
uae_u8 *get_real_address(uaecptr addr) {
	return 0;
}
int valid_address(uaecptr addr, uae_u32 size) {
	return 0;
}
uae_u32 get_longi(uaecptr addr) {
	return 0;
}
uae_u32 get_wordi(uaecptr addr) {
	return 0;
}

int main() {
	M68000_Init();
	M68000_Start();
	return 0;
}

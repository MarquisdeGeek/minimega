# minimega
A small emulator for the largest working microprocessor in the world - the Megaprocessor!

# Development notes

Mostly as notes to me...

## EMF changes

Everything can be auto-generated from the EMF toolkit, with the following exceptional changes, necessary by hand...

* int lsl_ext(const char *pName, emfNumber<uint16_t>& thereg) {
* int bits_ext(const char *pName, emfNumber<uint16_t>& thereg) {
* Remove uint16_t read8(uint16_t addr) and read16


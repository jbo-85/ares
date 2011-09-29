#include "board/board.hpp"

struct Cartridge : Processor, property<Cartridge> {
  static void Main();
  void main();

  void load(const string &xml, const uint8_t *data, unsigned size);
  void unload();

  unsigned ram_size();
  uint8 *ram_data();

  void power();
  void reset();

  readonly<bool> loaded;
  readonly<string> sha256;

  void serialize(serializer&);
  Cartridge();

//privileged:
  Board *board;
  Mapper::Mapper *mapper;

  uint8 prg_read(unsigned addr);
  void prg_write(unsigned addr, uint8 data);

  uint8 chr_read(unsigned addr);
  void chr_write(unsigned addr, uint8 data);

  uint8 *rom_data;
  unsigned rom_size;

  uint8 *prg_data;
  unsigned prg_size;

  uint8 *chr_data;
  unsigned chr_size;

  bool chr_ram;
  unsigned mirroring;
};

extern Cartridge cartridge;
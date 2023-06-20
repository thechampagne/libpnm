#include <iostream>
#include <fstream>
#include "pnm.hpp"

std::uint8_t* pnm_allocator( size_t const& size )
{
   return (std::uint8_t *) malloc(size);
}

struct pnm_info_t;

enum pnm_type_t
{
    PNM_TYPE_ERROR,
    PNM_TYPE_P1=1,
    PNM_TYPE_P2=2,
    PNM_TYPE_P3=3,
    PNM_TYPE_P4=4,
    PNM_TYPE_P5=5,
    PNM_TYPE_P6=6
};

extern "C" pnm_info_t* pnm_info_init()
{
  return (pnm_info_t*) new PNM::Info;
}

extern "C" void pnm_load(const char* f, std::uint8_t ** data, pnm_info_t* info)
{
  std::ifstream ifs(f, std::ios_base::binary );
  ifs >> PNM::load( data, pnm_allocator, *((PNM::Info*) info) );
}

extern "C" void pnm_save(const char* f ,const std::uint8_t* data, const std::size_t width, const std::size_t height, pnm_type_t type)
{
  std::ofstream ofs(f);
  ofs << PNM::save(data, width, height, (PNM::type) type);
}

extern "C" void pnm_probe(const char* f, pnm_info_t* info)
{
  std::ifstream ifs(f, std::ios_base::binary );
  ifs >> PNM::probe(*((PNM::Info*) info));
}

extern "C" int pnm_info_valid(const pnm_info_t* info)
{
  auto in = *((const PNM::Info*) info);
  if (in.valid())
  {
    return 1;
  }
  return 0;
}

extern "C" std::size_t pnm_info_width(const pnm_info_t* info)
{
  auto in = *((const PNM::Info*) info);
  return in.width();
}

extern "C" std::size_t pnm_info_height(const pnm_info_t* info)
{
  auto in = *((const PNM::Info*) info);
  return in.height();
}

extern "C" std::size_t pnm_info_channel(const pnm_info_t* info)
{
  auto in = *((const PNM::Info*) info);
  return in.channel();
}

extern "C" std::size_t pnm_info_depth(const pnm_info_t* info)
{
  auto in = *((const PNM::Info*) info);
  return in.depth();
}

extern "C" std::size_t pnm_info_maximum(const pnm_info_t* info)
{
  auto in = *((const PNM::Info*) info);
  return in.maximum();
}

extern "C" pnm_type_t pnm_info_type(const pnm_info_t* info)
{
  auto in = *((const PNM::Info*) info);
  return (pnm_type_t) in.type();
}

extern "C" void pnm_info_destroy(pnm_info_t* info)
{
  if (info != nullptr)
  {
    delete ((PNM::Info*) info);
  }
}

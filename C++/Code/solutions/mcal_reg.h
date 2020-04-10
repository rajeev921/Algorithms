#include <cstdint>

  namespace mcal
  {
    namespace reg
    {
      constexpr std::uint8_t portb = 0x25U;

      constexpr std::uint8_t bval0 = 0x01U;
      constexpr std::uint8_t bval1 = 0x01U << 1U;
      constexpr std::uint8_t bval2 = 0x01U << 2U;
      constexpr std::uint8_t bval3 = 0x01U << 3U;
      constexpr std::uint8_t bval4 = 0x01U << 4U;
      constexpr std::uint8_t bval5 = 0x01U << 5U;
      constexpr std::uint8_t bval6 = 0x01U << 6U;
      constexpr std::uint8_t bval7 = 0x01U << 7U;
    }
  }


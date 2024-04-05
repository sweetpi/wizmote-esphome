#include "wizmote.h"

namespace esphome {
namespace wizmote {
void WizMoteListener::on_esp_now_message(esp_now::ESPNowPacket packet) {
  WizMotePacket wizmote = WizMotePacket::build(packet);
  this->on_button_->trigger(wizmote);
}

bool WizMoteListener::find_bssid_index(WizMotePacket *packet, uint8_t *index)
{
  for (uint8_t i = 0; i < WIZMOTEHISTORYSIZE; i++)
  {
    if (is_bssid_equal(packet, &(this->history[i])))
    {
      *index = i;
      return true;
    }
  }
  return false;
}

bool WizMoteListener::is_bssid_equal(WizMotePacket *packet, WizMoteHistory *history)
{
  for (uint8_t i = 0; i < 6; i++)
  {
    if (packet->bssid[i] != history->bssid[i])
      return false;
  }
  return true;
}
  
}  // namespace wizmote
}  // namespace esphome

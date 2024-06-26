#include "wizmote.h"

namespace esphome {
namespace wizmote {
void WizMoteListener::on_esp_now_message(esp_now::ESPNowPacket packet) {
  WizMotePacket wizmote = WizMotePacket::build(packet);
  this->on_button_->trigger(wizmote);
}  
}  // namespace wizmote
}  // namespace esphome

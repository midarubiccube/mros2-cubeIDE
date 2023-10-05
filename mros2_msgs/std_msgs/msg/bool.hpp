#include <string>
#include <cstring>

namespace std_msgs
{
namespace msg
{
class Bool
{
public:
  typedef std::pair<bool, uint32_t> FragCopyReturnType;

  std::string getTypeName();
  bool data;
  uint32_t cntPub = 0;

  void copyToBuf(uint8_t *addrPtr)
  {
    memcpy(addrPtr, &data, 1);
    addrPtr += 1;
    cntPub += 1;
  }

  void copyFromBuf(const uint8_t *addrPtr)
  {
    memcpy(&data, addrPtr, 1);
    addrPtr += 1;
  }

  void memAlign(uint8_t *addrPtr)
  {
    return;
  }

  uint32_t getTotalSize()
  {
    uint32_t tmpCntPub = cntPub;
    cntPub = 0;
    return tmpCntPub;
  }

  uint32_t getPubCnt()
  {
    return cntPub;
  }

  void resetCount()
  {
    cntPub = 0;
    return;
  }

  uint32_t calcRawTotalSize()
  {
    return 1;
  }

  uint32_t calcTotalSize()
  {
    uint32_t tmp;
    tmp = 4 + calcRawTotalSize();                  // CDR encoding version.
    tmp += (0 == (tmp % 4) ? 0 : (4 - (tmp % 4))); // Padding
    return tmp;
  }

  FragCopyReturnType copyToFragBuf(uint8_t *addrPtr, uint32_t size)
  {
    // Nothing to be done because the message template
    // has own primitive types in it so that
    // this message type won't be used as a part of
    // fragmented messages.
    return {false, 0};
  }

private:
  std::string type_name = "std_msgs::msg::dds_::Bool";
};
}//namspace msg
}//namespace std_msgs

namespace message_traits
{

template<>
struct TypeName<std_msgs::msg::Bool*> {
  static const char* value()
  {
    return "std_msgs::msg::dds_::Bool_";
  }
};

}

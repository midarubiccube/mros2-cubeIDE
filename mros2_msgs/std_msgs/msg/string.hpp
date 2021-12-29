#include <string>

namespace std_msgs
{
namespace msg
{
class String
{
public:
  std::string getTypeName();
  std::string data;
  uint8_t cntPub = 0;
  void copyToBuf(uint8_t *addrPtr)
  {
    uint32_t size = data.size();
    memcpy(addrPtr, &size, 4);
    addrPtr += 4;
    cntPub += 4 ;
    memcpy(addrPtr, data.c_str(),size);
    addrPtr += size;
    cntPub += size;
    if (cntPub%4 > 0){
      for(int i=0; i<(4-(size%4)) ; i++){
        *addrPtr = 0;
        addrPtr += 1;
        cntPub += 1;
      }
    }  
    
  }

  void copyFromBuf(const uint8_t *addrPtr)
  {
    uint32_t msg_size;
    memcpy(&msg_size, addrPtr, 4);
    addrPtr += 4;
    data.resize(msg_size);
    memcpy(&data[0], addrPtr, msg_size);

  }

  uint8_t getTotalSize()
  {
    return cntPub;
  }
private:
  std::string type_name = "std_msgs::msg::dds_::String";
};
}//namspace msg
}//namespace std_msgs

namespace message_traits
{

template<>
struct TypeName<std_msgs::msg::String*> {
  static const char* value()
  {
    return "std_msgs::msg::dds_::String_";
  }
};

}

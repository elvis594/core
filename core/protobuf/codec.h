#ifndef PROTOBUF_CODEC_H
#define PROTOBUF_CODEC_H


#include <google/protobuf/message.h>

namespace ProtobufCodec
{
    google::protobuf::Message* createMessage(const std::string& typeName);

} // namespace ProtobufCodec



#endif // !PROTOBUF_CODEC_H


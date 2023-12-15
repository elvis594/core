#include <google/protobuf/message.h>
#include <google/protobuf/descriptor.h>

#include "codec.h"

// 实现反射 use type name crate a message.
google::protobuf::Message *ProtobufCodec::createMessage(const std::string &typeName)
{
	google::protobuf::Message *message = nullptr;
	const google::protobuf::Descriptor *descriptor =
		google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(typeName);
	if (descriptor)
	{
		const google::protobuf::Message *prototype =
			google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
		if (prototype)
		{
			message = prototype->New();
		}
	}
	return message;
}

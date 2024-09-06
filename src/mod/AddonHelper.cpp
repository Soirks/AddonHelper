#include "mod/AddonHelper.h"

#include <memory>
#include <fmt/format.h>
#include <functional>
#include <ll/api/Config.h>
#include <ll/api/Logger.h>
#include <ll/api/command/Command.h>
#include <ll/api/command/CommandHandle.h>
#include <ll/api/command/CommandRegistrar.h>
#include <ll/api/data/KeyValueDB.h>
#include <ll/api/event/EventBus.h>
#include <ll/api/event/ListenerBase.h>
#include <ll/api/event/player/PlayerJoinEvent.h>
#include <ll/api/event/player/PlayerUseItemEvent.h>
#include <ll/api/form/ModalForm.h>
#include <ll/api/io/FileUtils.h>
#include <ll/api/mod/NativeMod.h>
#include <ll/api/mod/ModManagerRegistry.h>
#include <ll/api/service/Bedrock.h>
#include <mc/entity/utilities/ActorType.h>
#include <mc/server/commands/CommandOrigin.h>
#include <mc/server/commands/CommandOutput.h>
#include <mc/server/commands/CommandPermissionLevel.h>
#include <mc/world/actor/player/Player.h>
#include <mc/world/item/registry/ItemStack.h>

#include "ll/api/mod/RegisterHelper.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
namespace addon_helper {

static std::unique_ptr<AddonHelper> instance;
using namespace rapidjson;
AddonHelper& AddonHelper::getInstance() { return *instance; }
bool jsontest(){
        // 1. 把 JSON 解析至 DOM。
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d;
    d.Parse(json);
 
    // 2. 利用 DOM 作出修改。
    Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);
 
    // 3. 把 DOM 转换（stringify）成 JSON。
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
 
    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;
    return 0;
}
bool AddonHelper::load() {
    getSelf().getLogger().debug("Loading...");
    // Code for loading the mod goes here.
    return true;
}

bool AddonHelper::enable() {
    getSelf().getLogger().debug("Enabling...");
    // Code for enabling the mod goes here.
    return true;
}

bool AddonHelper::disable() {
    getSelf().getLogger().debug("Disabling...");
    // Code for disabling the mod goes here.
    return true;
}

} // namespace addon_helper

LL_REGISTER_MOD(addon_helper::AddonHelper, addon_helper::instance);

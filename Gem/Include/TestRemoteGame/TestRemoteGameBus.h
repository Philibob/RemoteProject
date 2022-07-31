
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace TestRemoteGame
{
    class TestRemoteGameRequests
    {
    public:
        AZ_RTTI(TestRemoteGameRequests, "{fef36638-8e11-477c-9758-6c16f4faefd2}");
        virtual ~TestRemoteGameRequests() = default;
        // Put your public methods here
    };

    class TestRemoteGameBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using TestRemoteGameRequestBus = AZ::EBus<TestRemoteGameRequests, TestRemoteGameBusTraits>;
    using TestRemoteGameInterface = AZ::Interface<TestRemoteGameRequests>;

} // namespace TestRemoteGame

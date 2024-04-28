#pragma once

#include <Features/Common/InWorldPanels.h>
#include <Features/Common/FeatureToggle.h>
#include <GameClient/WorldToScreen/WorldToClipSpaceConverter.h>
#include <Hooks/ViewRenderHook.h>

#include "PlayerInfoInWorldContext.h"
#include "PlayerInfoInWorldState.h"
#include "PlayerPositionArrow/PlayerPositionArrowColorType.h"
#include "PlayerStateIcons/PlayerStateIconsToShow.h"

template <typename HookContext>
struct PlayerInfoInWorldToggle {
    PlayerInfoInWorldToggle(HookContext& hookContext) noexcept
        : hookContext{hookContext}
    {
    }

    void update(char option) noexcept
    {
        switch (option) {
        case '0': setVariable<player_info_vars::Enabled>(true); setVariable<player_info_vars::OnlyEnemies>(true); break;
        case '1': setVariable<player_info_vars::Enabled>(true); setVariable<player_info_vars::OnlyEnemies>(false); break;
        case '2': setVariable<player_info_vars::Enabled>(false); break;
        }
    }

    void updatePlayerPositionArrowColorMode(char option) const noexcept
    {
        switch (option) {
        case '0': hookContext.config().template setVariable<player_info_vars::PlayerPositionArrowColorMode>(PlayerPositionArrowColorType::PlayerOrTeamColor); break;
        case '1': hookContext.config().template setVariable<player_info_vars::PlayerPositionArrowColorMode>(PlayerPositionArrowColorType::TeamColor); break;
        }
    }

    void updatePlayerHealthColorMode(char option) const noexcept
    {
        switch (option) {
        case '0': hookContext.config().template setVariable<player_info_vars::PlayerHealthColorMode>(PlayerHealthTextColor::HealthBased); break;
        case '1': hookContext.config().template setVariable<player_info_vars::PlayerHealthColorMode>(PlayerHealthTextColor::White); break;
        }
    }

private:
    template <typename ConfigVariable>
    void setVariable(ConfigVariable::ValueType value) const noexcept
    {
        hookContext.config().template setVariable<ConfigVariable>(value);
    }

    HookContext& hookContext;
};

template <typename HookContext>
class PlayerInfoInWorld {
public:
    PlayerInfoInWorld(HookContext& hookContext) noexcept
        : hookContext{hookContext}
    {
    }

    void drawPlayerInformation(auto&& playerPawn) noexcept
    {
        auto&& condition = context().condition();
        if (!condition.shouldRun() || !condition.shouldDrawInfoOnPawn(playerPawn))
            return;

        const auto absOrigin = playerPawn.absOrigin();
        if (!absOrigin.hasValue())
            return;

        const auto positionInClipSpace = hookContext.template make<WorldToClipSpaceConverter>().toClipSpace(absOrigin.value());
        if (!positionInClipSpace.onScreen())
            return;

        auto&& playerInformationPanel = hookContext.template make<InWorldPanels>().getNextPlayerInfoPanel();
        playerInformationPanel.drawPlayerInfo(playerPawn);
        playerInformationPanel.updatePosition(absOrigin.value());
    }

private:
    [[nodiscard]] decltype(auto) context() const noexcept
    {
        return hookContext.template make<PlayerInfoInWorldContext>();
    }

    [[nodiscard]] auto& state() const noexcept
    {
        return hookContext.featuresStates().visualFeaturesStates.playerInfoInWorldState;
    }

    HookContext& hookContext;
};

#pragma once

#include <CS2/Panorama/CImagePanel.h>
#include <MemoryPatterns/PatternTypes/PanoramaImagePanelPatternTypes.h>
#include <GameClient/Panorama/PanoramaUiPanel.h>

template <typename HookContext>
struct PanoramaImagePanelContext {
    PanoramaImagePanelContext(HookContext& hookContext, cs2::CImagePanel* panel) noexcept
        : hookContext{hookContext}
        , panel{panel}
    {
    }

    [[nodiscard]] decltype(auto) uiPanel() const noexcept
    {
        return hookContext.uiPanel(panel ? panel->uiPanel : nullptr);
    }

    [[nodiscard]] const char* getImagePath() const noexcept
    {
        if (auto&& imagePath = hookContext.patternSearchResults().template get<OffsetToImagePath>().of(panel).get())
            return imagePath->m_pString;
        return nullptr;
    }

    HookContext& hookContext;
    cs2::CImagePanel* panel;
};

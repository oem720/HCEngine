
#include <HellfireControl/Core/Window.hpp>

#define HC_INCLUDE_WINDOW //Enable window include

#include <Platform/OSInclude.hpp>

void Window::CleanupWindow() {
	PlatformWindow::CleanupWindow(m_whgHandle);
}

void Window::SetWindowName(const std::string& _strName) {
	if (!PlatformWindow::SetWindowName(m_whgHandle, _strName)) {
		assert(!"ERROR: Window name failed to change!");
	}
}

void Window::SetWindowType(WindowType _wtType) {
	if (!PlatformWindow::SetWindowStyleParameters(m_whgHandle, _wtType)) {
		assert(!"ERROR: Window type failed to change!");
	}
}

void Window::SetWindowSize(const Vec2F& _v2Size) {
	if (!PlatformWindow::SetWindowSize(m_whgHandle, _v2Size)) {
		assert(!"ERROR: Window size failed to change!");
	}
}

void Window::SetWindowLocation(const Vec2F& _v2Loc) {
	if (!PlatformWindow::SetWindowLocation(m_whgHandle, _v2Loc)) {
		assert(!"ERROR: Window location failed to change!");
	}
}

void Window::InitWindow() {
	PlatformWindow::InitWindow(m_whgHandle, m_wtType, m_strWindowName, m_v2WindowSize, m_v2WindowLocation);
}

void Window::UpdateWindowData() {
	m_v2WindowSize = PlatformWindow::GetWindowSize(m_whgHandle);
	m_v2WindowLocation = PlatformWindow::GetWindowLocation(m_whgHandle);
	m_wtType = static_cast<WindowType>(PlatformWindow::GetWindowParameters(m_whgHandle));
}

void Window::UpdateWindowSize() {
	m_v2WindowSize = PlatformWindow::GetWindowSize(m_whgHandle);
}

void Window::UpdateWindowLocation() {
	m_v2WindowLocation = PlatformWindow::GetWindowLocation(m_whgHandle);
}

void Window::UpdateWindowType() {
	m_wtType = static_cast<WindowType>(PlatformWindow::GetWindowParameters(m_whgHandle));
}
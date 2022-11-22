// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#include "pch.h"
#include "MainWindow.xaml.h"
#include <microsoft.ui.xaml.window.h>
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::progressbar::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
        auto windowNative{ this->try_as<::IWindowNative>() };
        HWND hWnd{ 0 };
        windowNative->get_WindowHandle(&hWnd);
        SetWindowPos(hWnd, NULL, 200, 200, 390, 290, NULL);
        this->Title(L"���α׷��� �� �ǽ�");
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

}


void winrt::progressbar::implementation::MainWindow::PausedRB_Checked(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    ProgressBar().ShowPaused(true);
    ProgressBar().ShowError(false);
    ProgressBar().IsIndeterminate(true);
}


void winrt::progressbar::implementation::MainWindow::ErrorRB_Checked(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    ProgressBar().ShowPaused(false);
    ProgressBar().ShowError(true);
    ProgressBar().IsIndeterminate(true);
}


void winrt::progressbar::implementation::MainWindow::RunningRB_Checked(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    ProgressBar().ShowPaused(false);
    ProgressBar().ShowError(false);
    ProgressBar().IsIndeterminate(true);
}

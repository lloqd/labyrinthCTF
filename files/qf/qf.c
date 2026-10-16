int32_t __stdcall sub_401000(HINSTANCE arg1, enum SHOW_WINDOW_CMD arg2 @ 0x10)
{
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    char* lpClassName = "QTEGameWindowClass";
    WNDCLASSA wndClass;
    __builtin_memset(&wndClass, 0, 0x28);
    wndClass.lpfnWndProc = sub_402470;
    wndClass.hInstance = arg1;
    wndClass.lpszClassName = lpClassName;
    wndClass.hCursor = LoadCursorA(nullptr, 0x7f00);
    wndClass.hbrBackground = 0;
    RegisterClassA(&wndClass);
    RECT rect;
    rect.left = 0;
    rect.top = 0;
    rect.right = data_41e000;
    rect.bottom = data_41e004;
    AdjustWindowRect(&rect, WS_TILEDWINDOW, 0);
    HWND hWnd = CreateWindowExA(WS_EX_LEFT, lpClassName, "Quick Fate", WS_TILEDWINDOW, 0x80000000,
        0x80000000, rect.right - rect.left, rect.bottom - rect.top, nullptr, nullptr, arg1,
        nullptr);
    ShowWindow(hWnd, arg2);
    UpdateWindow(hWnd);
    MSG msg;

    while (GetMessageA(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }

    sub_402910(eax_1 ^ &__saved_ebp);
    return 0;
}

int32_t sub_401130()
{
    if (!data_41eab4)
    {
        for (void* i = nullptr; i < 0x18; i += 1)
            *(i + 0x41ea98) = *(i + 0x416210) ^ 0x5a;

        data_41eab0 = 0;
        data_41eab4 = 1;
    }

    return 0x41ea98;
}

int32_t sub_4011b0(void* arg1, int32_t arg2)
{
    int32_t result = sub_401130();
    int32_t result_1 = 0;

    while (result_1 + 1 < arg2)
    {
        result = *(0x41ea98 + result_1);
        if (!result)
            break;

        char var_10_1;
        if (*(0x41ea98 + result_1) != 0x20)
            var_10_1 = *(0x41ea98 + result_1);
        else
            var_10_1 = 0x5f;
        *(arg1 + result_1) = var_10_1;
        result = result_1 + 1;
        result_1 = result;
    }
    *(arg1 + result_1) = 0;
    return result;
}

long double sub_401230()
{
    return _rand() / 32767.0;
}

int32_t sub_401260(HWND arg1, int32_t arg2, int32_t arg3)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    HDC eax_1 = GetDC(arg1);

    if (data_41eab8)
    {
        SelectObject(data_41eab8, data_41eac0);
        DeleteObject(data_41eabc);
        DeleteDC(data_41eab8);
    }

    data_41eab8 = CreateCompatibleDC(eax_1);
    data_41eabc = CreateCompatibleBitmap(eax_1, arg2, arg3);
    data_41eac0 = SelectObject(data_41eab8, data_41eabc);
    int32_t result = ReleaseDC(arg1, eax_1);
    data_41e000 = arg2;
    data_41e004 = arg3;
    return result;
}

HANDLE sub_401310()
{
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    void* var_31c = 0xffffffff;
    char filename[0x104];
    GetModuleFileNameA(nullptr, &filename, 0x104);
    void* var_318 = nullptr;

    while (*(&filename + var_318))
    {
        if (*(&filename + var_318) == 0x5c || *(&filename + var_318) == 0x2f)
            var_31c = var_318;

        var_318 += 1;
    }

    char var_210[0x104];

    if (var_31c < 0)
        var_210[0] = 0;
    else
    {
        sub_4035c0(&var_210, &filename, var_31c);

        if (var_31c >= 0x104)
        {
            sub_402900();
            /* no return */
        }

        *(&var_210 + var_31c) = 0;
    }

    char (* var_340_2)[0x104] = &var_210;
    void name;
    _snprintf(&name, 0x104, "%s\background.bmp");
    HANDLE result =
        LoadImageA(nullptr, &name, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    data_41eac4 = result;

    if (data_41eac4)
    {
        void pv;
        result = GetObjectA(data_41eac4, 0x18, &pv);
        int32_t var_338;
        data_41eac8 = var_338;
        int32_t var_334;
        data_41eacc = var_334;
    }

    sub_402910(eax_1 ^ &__saved_ebp);
    return result;
}

int32_t sub_4014b0(long double arg1 @ st0, long double arg2 @ st1)
{
    int32_t var_8;

    if (data_41e000 >= data_41e004)
        var_8 = data_41e004;
    else
        var_8 = data_41e000;

    double xmm0_4 = sub_401230() * 2.0 * 3.1415926535897931;
    double var_70 = sub_401230();
    int16_t x87control;
    long double st0_2;
    st0_2 = sub_405c90();
    double xmm0_6 = st0_2 * var_8 * 0.34000000000000002;
    double xmm0_10 = data_41e004 / 2.0;
    double xmm0_11 = 160.0;
    double var_70_1 = xmm0_4;
    double var_18 = arg1 * xmm0_6 + data_41e000 / 2.0;
    double var_70_2 = xmm0_4;
    int32_t mxcsr;
    sub_405c40(mxcsr, sub_405bd0(mxcsr, x87control));
    double var_20 = arg2 * xmm0_6 + xmm0_10;

    if (!(xmm0_11 <= var_18))
        var_18 = xmm0_11;

    if (!(xmm0_11 <= var_20))
        var_20 = xmm0_11;

    if (!(var_18 <= data_41e000 - xmm0_11))
        var_18 = data_41e000 - xmm0_11;

    if (!(var_20 <= data_41e004 - xmm0_11))
        var_20 = data_41e004 - xmm0_11;

    int32_t result = var_18;
    data_41ea68 = result;
    data_41ea6c = var_20;
    data_41ea48 = 1;
    data_41ea50 = {0};
    data_41ea60 = 0x4062c00000000000;
    return result;
}

int32_t sub_401680()
{
    _memset(&data_41ea48, 0, 0x50);
    long double x87_r0;
    long double x87_r1;
    return sub_4014b0(x87_r0, x87_r1);
}

int32_t sub_4016a0()
{
    int32_t ecx;
    int32_t var_8 = ecx;

    if (data_41ea7c < 0x18)
        return 0;

    return 1;
}

int32_t sub_4016d0(int32_t arg1, int32_t arg2)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    data_41ea48 = 2;
    data_41ea58 = {0};
    data_41ea70 = arg1;
    data_41ea74 = arg2;

    if (arg1)
    {
        int32_t var_8_1;

        var_8_1 = !arg2 ? 1 : 2;

        data_41ea78 += var_8_1;
    }

    return arg1;
}

void sub_401730(double arg1)
{
    if (data_41ea80)
    {
        data_41ea88 = data_41ea88 + arg1;
        int64_t var_14_1;

        if (data_41ea80 != 1)
            var_14_1 = 0x3fe999999999999a;
        else
            var_14_1 = 0x3ff0000000000000;

        if (!(data_41ea88 < var_14_1))
            data_41ea80 = 0;
    }

    if (data_41ea48 == 1)
    {
        data_41ea50 = data_41ea50 + arg1;
        double var_c_1 = data_41ea50 / 1.1499999999999999;

        if (!(var_c_1 < 1.0))
            var_c_1 = 1.0;

        data_41ea60 = (1.0 - var_c_1) * 150.0;

        if (!(var_c_1 < 1.0))
            sub_4016d0(0, 0);
    }
    else if (data_41ea48 == 2)
    {
        data_41ea58 = data_41ea58 + arg1;

        if (!(data_41ea58 < 0.45000000000000001))
        {
            if (data_41ea70)
            {
                long double x87_r0;
                long double x87_r1;

                if (!sub_4016a0())
                    sub_4014b0(x87_r0, x87_r1);
                else
                    data_41ea48 = 4;
            }
            else
                data_41ea48 = 3;
        }
    }
}

void sub_401890(char arg1)
{
    if (data_41ea48 != 1)
        return;

    double var_28_1 = data_41ea60 - 42.0;
    double var_1c_1 = sub_405c20(var_28_1);
    int32_t var_8_1;

    var_8_1 = 0x402e000000000000 < var_1c_1 ? 0 : 1;

    int32_t var_c_1;

    var_c_1 = !var_8_1 || 0x4014000000000000 < var_1c_1 ? 0 : 1;

    sub_401130();

    if (arg1 != *(0x41ea98 + data_41ea7c))
    {
        if (data_41ea7c > 0)
        {
            data_41ea80 = 2;
            data_41ea88 = {0};
        }

        data_41ea7c = 0;
    }
    else
    {
        data_41ea7c += 1;
        data_41ea80 = 1;
        data_41ea88 = {0};
        data_41ea90 = data_41ea7c;
    }

    *(&var_28_1 + 4) = var_c_1;
    var_28_1 = var_8_1;
    sub_4016d0(var_28_1);
}

BOOL sub_4019a0(HDC arg1)
{
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    BOOL result;

    if (!data_41eac4)
    {
        RECT lprc;
        lprc.left = 0;
        lprc.top = 0;
        lprc.right = data_41e000;
        lprc.bottom = data_41e004;
        result = FillRect(arg1, &lprc, GetStockObject(BLACK_BRUSH));
    }
    else
    {
        HDC eax_3 = CreateCompatibleDC(arg1);
        HGDIOBJ h = SelectObject(eax_3, data_41eac4);
        SetStretchBltMode(arg1, HALFTONE);
        StretchBlt(arg1, 0, 0, data_41e000, data_41e004, eax_3, 0, 0, data_41eac8, data_41eacc,
            SRCCOPY);
        SelectObject(eax_3, h);
        result = DeleteDC(eax_3);
    }

    sub_402910(eax_1 ^ &__saved_ebp);
    return result;
}

void sub_401a90(HDC arg1, int32_t arg2, int32_t arg3, double arg4, COLORREF arg5, int32_t arg6)
{
    if (!(0x3ff0000000000000 <= arg4))
        return;

    HPEN eax_2 = CreatePen(PS_COSMETIC, arg6, arg5);
    HGDIOBJ h = SelectObject(arg1, eax_2);
    HGDIOBJ h_1 = SelectObject(arg1, GetStockObject(HOLLOW_BRUSH));
    int32_t edx_2 = arg4;
    Ellipse(arg1, arg2 - edx_2, arg3 - edx_2, arg2 + edx_2, arg3 + edx_2);
    SelectObject(arg1, h_1);
    SelectObject(arg1, h);
    DeleteObject(eax_2);
}

HGDIOBJ sub_401b40(HDC arg1, uint8_t* arg2, int32_t arg3, int32_t arg4, HGDIOBJ arg5, COLORREF arg6)
{
    HGDIOBJ h = SelectObject(arg1, arg5);
    SetTextColor(arg1, arg6);
    SetBkMode(arg1, 1);
    SIZE psizl;
    GetTextExtentPoint32A(arg1, arg2, _strlen(arg2), &psizl);
    void* c = _strlen(arg2);
    int32_t eax_6;
    int32_t edx_2;
    edx_2 = HIGHD(psizl.cy);
    eax_6 = LOWD(psizl.cy);
    int32_t eax_10;
    int32_t edx_5;
    edx_5 = HIGHD(psizl.cx);
    eax_10 = LOWD(psizl.cx);
    TextOutA(arg1, arg3 - ((eax_10 - edx_5) >> 1), arg4 - ((eax_6 - edx_2) >> 1), arg2, c);
    return SelectObject(arg1, h);
}

BOOL sub_401be0(HDC arg1, COLORREF arg2, char arg3)
{
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    RECT lprc;
    lprc.left = 0;
    lprc.top = 0;
    lprc.right = data_41e000;
    lprc.bottom = data_41e004;
    HBRUSH eax_3 = CreateSolidBrush(arg2);
    HDC eax_5 = CreateCompatibleDC(arg1);
    HBITMAP eax_7 = CreateCompatibleBitmap(arg1, data_41e000, data_41e004);
    HGDIOBJ h = SelectObject(eax_5, eax_7);
    BitBlt(eax_5, 0, 0, data_41e000, data_41e004, arg1, 0, 0, SRCCOPY);
    FillRect(eax_5, &lprc, eax_3);
    char var_20 = 0;
    char var_1f = 0;
    char var_1e = arg3;
    char var_1d = 0;
    BLENDFUNCTION ftn = struct BLENDFUNCTION {
        .BlendOp = var_20,
        .BlendFlags = *(&var_20 + 1),
        .SourceConstantAlpha = *(&var_20 + 2),
        .AlphaFormat = *(&var_20 + 3)
    };
    AlphaBlend(arg1, 0, 0, data_41e000, data_41e004, eax_5, 0, 0, data_41e000, data_41e004, ftn);
    SelectObject(eax_5, h);
    DeleteObject(eax_7);
    DeleteDC(eax_5);
    BOOL result = DeleteObject(eax_3);
    sub_402910(eax_1 ^ &__saved_ebp);
    return result;
}

HGDIOBJ sub_401d20(HDC arg1)
{
    sub_4019a0(arg1);
    sub_401be0(arg1, 0xf0a0a, 0x6e);
    int32_t eax_2;
    int32_t edx;
    edx = HIGHD(data_41e000);
    eax_2 = LOWD(data_41e000);
    int32_t eax_4 = (eax_2 - edx) >> 1;
    int32_t eax_6;
    int32_t edx_1;
    edx_1 = HIGHD(data_41e004);
    eax_6 = LOWD(data_41e004);
    int32_t eax_8 = (eax_6 - edx_1) >> 1;
    sub_401b40(arg1, "QUICK FATE", eax_4, eax_8 - 0x1e, data_41ead4, 0xffffff);
    return sub_401b40(arg1, "Press any key to start", eax_4, eax_8 + 0x1e, data_41ead0, 0xdcdcdc);
}

HGDIOBJ sub_401dc0(HDC arg1, int32_t arg2)
{
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    sub_4019a0(arg1);
    COLORREF var_190;

    var_190 = !arg2 ? 0x8081e : 0xf1e0a;

    sub_401be0(arg1, var_190, 0x8c);
    int32_t eax_4;
    int32_t edx_1;
    edx_1 = HIGHD(data_41e000);
    eax_4 = LOWD(data_41e000);
    int32_t eax_6 = (eax_4 - edx_1) >> 1;
    int32_t eax_8;
    int32_t edx_2;
    edx_2 = HIGHD(data_41e004);
    eax_8 = LOWD(data_41e004);
    int32_t eax_10 = (eax_8 - edx_2) >> 1;
    void var_e4;

    if (!arg2)
        _snprintf(&var_e4, 0xc0, "YOU FAILED THE TRIAL AND DIED");
    else
    {
        void var_24;
        sub_4011b0(&var_24, 0x19);
        void* var_19c_1 = &var_24;
        _snprintf(&var_e4, 0xc0, "VICTORY! YOUR FLAG IS %s");
    }

    COLORREF var_194;

    var_194 = !arg2 ? 0x4646ff : 0xa0ff78;

    sub_401b40(arg1, &var_e4, eax_6, eax_10 - 0x3c, data_41ead4, var_194);
    int32_t var_19c_3 = data_41ea78;
    void var_184;
    _snprintf(&var_184, 0xa0, "Score: %d");
    sub_401b40(arg1, &var_184, eax_6, eax_10, data_41ead0, 0xffffff);
    HGDIOBJ result =
        sub_401b40(arg1, "Press any key to restart", eax_6, eax_10 + 0x32, data_41ead0, 0xc8c8c8);
    sub_402910(eax_1 ^ &__saved_ebp);
    return result;
}

HGDIOBJ sub_401f60(HDC arg1)
{
    int32_t __saved_ebp;
    HGDIOBJ result = __security_cookie ^ &__saved_ebp;
    HGDIOBJ result_1 = result;

    if (data_41ea80)
    {
        double var_60_1;

        if (data_41ea80 != 1)
            var_60_1 = 0.80000000000000004;
        else
            var_60_1 = 1.0;

        double var_58_1 = data_41ea88 / var_60_1;

        if (!(var_58_1 <= 1.0))
            var_58_1 = 1.0;

        double xmm0_9 = 1.0 - var_58_1;
        int32_t eax_2;
        int32_t edx_1;
        edx_1 = HIGHD(data_41e000);
        eax_2 = LOWD(data_41e000);
        int32_t eax_4 = (eax_2 - edx_1) >> 1;

        if (data_41ea80 != 1)
        {
            sub_401be0(arg1, 0x2323e6, 150.0 * xmm0_9);
            result = sub_401b40(arg1, "FLAG RESET", eax_4, 0x46, data_41ead4, 0xaaaaff);
        }
        else
        {
            sub_401be0(arg1, 0x6edc28, 130.0 * xmm0_9);
            int32_t var_74_2 = data_41ea90;
            void var_48;
            _snprintf(&var_48, 0x40, "char_%d found");
            result = sub_401b40(arg1, &var_48, eax_4, 0x46, data_41ead4, 0xc8ffb4);
        }
    }

    sub_402910(result_1 ^ &__saved_ebp);
    return result;
}

HGDIOBJ sub_4020d0(HDC arg1)
{
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    HGDIOBJ result;

    if (!data_41ea48)
        result = sub_401d20(arg1);
    else if (data_41ea48 == 3 || data_41ea48 == 4)
    {
        int32_t var_98_1;

        if (data_41ea48 != 4)
            var_98_1 = 0;
        else
            var_98_1 = 1;

        result = sub_401dc0(arg1, var_98_1);
    }
    else
    {
        sub_4019a0(arg1);
        int32_t ecx_2 = data_41ea68;
        int32_t edx_2 = data_41ea6c;
        double var_e0_2;
        double var_d0;

        if (data_41ea48 != 1)
        {
            char* var_a4_1;

            if (!data_41ea70)
                var_a4_1 = "MISS";
            else
            {
                char* var_a0_1;

                if (!data_41ea74)
                    var_a0_1 = "HIT!";
                else
                    var_a0_1 = "PERFECT!";

                var_a4_1 = var_a0_1;
            }

            HGDIOBJ var_ac_1;

            if (!data_41ea70)
                var_ac_1 = 0x5050ff;
            else
            {
                HGDIOBJ var_a8_1;

                if (!data_41ea74)
                    var_a8_1 = 0x5ae6ff;
                else
                    var_a8_1 = 0xa0ff78;

                var_ac_1 = var_a8_1;
            }

            var_e0_2 = 42.0;
            sub_401a90(arg1, ecx_2, edx_2, var_e0_2, var_ac_1, 3);
            *(&var_e0_2 + 4) = edx_2;
            var_e0_2 = ecx_2;
            sub_401b40(arg1, var_a4_1, var_e0_2, data_41ead4, var_ac_1);
        }
        else
        {
            int32_t var_d8;
            var_d8 = data_41ea60 - 42.0;
            var_d0 = sub_405c20(var_d8);
            COLORREF var_9c_1;

            var_9c_1 = 0x401e000000000000 < var_d0 ? 0x2896ff : 0x78e65a;

            sub_401a90(arg1, ecx_2, edx_2, 42.0, var_9c_1, 3);
            var_e0_2 = data_41ea60;
            sub_401a90(arg1, ecx_2, edx_2, var_e0_2, 0xffffff, 4);
        }

        *(&var_e0_2 + 4) = 0x80;
        char y_1[0x80];
        var_e0_2 = &y_1;
        _snprintf(var_e0_2, "Score: %d", data_41ea78, var_d0);
        HGDIOBJ h = SelectObject(arg1, data_41ead0);
        SetTextColor(arg1, 0xffffff);
        SetBkMode(arg1, 1);
        *(&var_e0_2 + 4) = 0xe;
        var_e0_2 = 0x10;
        TextOutA(arg1, 0xe00000010, &y_1, _strlen(&y_1));
        SelectObject(arg1, h);
        char* y = "Esc to quit";
        HGDIOBJ h_1 = SelectObject(arg1, data_41ead0);
        *(&var_e0_2 + 4) = y;
        var_e0_2 = arg1;
        int32_t c;
        GetTextExtentPoint32A(var_e0_2, _strlen(y), &c);
        uint8_t* lpString = _strlen(y);
        int32_t var_c4;
        *(&var_e0_2 + 4) = data_41e004 - var_c4 - 0xe;
        var_e0_2 = data_41e000 - c - 0x10;
        TextOutA(arg1, var_e0_2, y, lpString);
        SelectObject(arg1, h_1);
        result = sub_401f60(arg1);
    }

    sub_402910(eax_1 ^ &__saved_ebp);
    return result;
}

LRESULT __stdcall sub_402470(HWND arg1, uint32_t arg2, WPARAM arg3, LPARAM arg4)
{
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    LRESULT result;

    if (arg2 > 0xf)
    {
        if (arg2 == 0x14)
            result = 1;
        else if (arg2 == 0x100)
        {
            if (arg3 == 0x1b)
            {
                DestroyWindow(arg1);
                result = 0;
            }
            else if (!(arg4 & 0x40000000))
            {
                if (!data_41ea48 || data_41ea48 == 3 || data_41ea48 == 4)
                    sub_401680();
                else if (data_41ea48 == 1)
                    sub_401890(arg3);

                result = 0;
            }
            else
                result = 0;
        }
        else if (arg2 == 0x113)
        {
            int32_t performanceCount;
            QueryPerformanceCounter(&performanceCount);
            int32_t performanceCount_1 = performanceCount;
            int32_t var_68;
            void invalid;
            double xmm0_1 =
                sub_402920(performanceCount_1 - data_41eae0, var_68 - data_41eae4, invalid);
            double var_78_1 = xmm0_1 / sub_402920(data_41ead8, data_41eadc, invalid, xmm0_1);
            data_41eae0 = performanceCount;
            data_41eae4 = var_68;

            if (!(var_78_1 <= 0.10000000000000001))
                var_78_1 = 0.10000000000000001;

            int32_t var_88;
            var_88 = var_78_1;
            sub_401730(var_88);
            InvalidateRect(arg1, nullptr, 0);
            result = 0;
        }
        else
            result = DefWindowProcA(arg1, arg2, arg3, arg4);
    }
    else if (arg2 == 0xf)
    {
        PAINTSTRUCT paint;
        HDC hdc = BeginPaint(arg1, &paint);
        sub_4020d0(data_41eab8);
        BitBlt(hdc, 0, 0, data_41e000, data_41e004, data_41eab8, 0, 0, SRCCOPY);
        EndPaint(arg1, &paint);
        result = 0;
    }
    else if (arg2 == 1)
    {
        sub_405bbc(sub_402880(nullptr));
        QueryPerformanceFrequency(&data_41ead8);
        QueryPerformanceCounter(&data_41eae0);
        data_41ead0 = CreateFontA(0x14, 0, 0, 0, 0x190, 0, 0, 0, 0, 0, 0, 4, 0x20, "Segoe UI");
        data_41ead4 = CreateFontA(0x22, 0, 0, 0, 0x2bc, 0, 0, 0, 0, 0, 0, 4, 0x20, "Segoe UI");
        sub_401310();
        RECT rect;
        GetClientRect(arg1, &rect);
        sub_401260(arg1, rect.right - rect.left, rect.bottom - rect.top);
        _memset(&data_41ea48, 0, 0x50);
        data_41ea48 = 0;
        SetTimer(arg1, 1, 0xa, nullptr);
        result = 0;
    }
    else if (arg2 == 2)
    {
        KillTimer(arg1, 1);

        if (data_41eab8)
        {
            SelectObject(data_41eab8, data_41eac0);
            DeleteObject(data_41eabc);
            DeleteDC(data_41eab8);
        }

        if (data_41eac4)
            DeleteObject(data_41eac4);

        if (data_41ead0)
            DeleteObject(data_41ead0);

        if (data_41ead4)
            DeleteObject(data_41ead4);

        PostQuitMessage(0);
        result = 0;
    }
    else if (arg2 == 5)
    {
        int32_t edx_3 = arg4;
        uint32_t ecx_5 = arg4 >> 0x10;

        if (edx_3 > 0 && ecx_5 > 0)
            sub_401260(arg1, edx_3, ecx_5);

        result = 0;
    }
    else
        result = DefWindowProcA(arg1, arg2, arg3, arg4);

    sub_402910(eax_1 ^ &__saved_ebp);
    return result;
}

int32_t sub_402830() __pure
{
    return &data_41f130;
}

int32_t* _snprintf(int32_t* arg1, int32_t arg2, int32_t arg3)
{
    int32_t var_8_1 = 0;
    void arg_10;
    return _vsnprintf(arg1, arg2, arg3, &arg_10);
}

uint32_t sub_402880(uint32_t* arg1)
{
    int32_t ecx;
    int32_t edx;
    return sub_407a99(arg1, edx, ecx, arg1);
}

int32_t* _vsnprintf(int32_t* arg1, int32_t arg2, int32_t arg3, int32_t arg4)
{
    int32_t* result =
        ___stdio_common_vsprintf(data_41f130 | 2, data_41f134, arg1, arg2, arg3, nullptr, arg4);

    if (result >= 0)
        return result;

    return 0xffffffff;
}

void sub_4028f0() __noreturn
{
    trap(0xd);
}

void sub_402900() __noreturn
{
    trap(0xd);
}

int32_t __fastcall sub_402910(int32_t arg1)
{
    if (arg1 != __security_cookie)
        /* tailcall */
        return sub_4028f0();
}

int32_t __fastcall sub_402920(int32_t arg1, uint32_t arg2, void arg3 @ invalid)
{
    if (data_41e190 & 0x20)
    {
        __orps_xmmxud_memxud(arg1, *data_4162b0);
        return;
    }

    _mm_cvtepi64_pd(arg3, __vpinsrd_xmmdq_xmmdq_gpr32d_immb(arg1, arg2, 1));
}

int32_t sub_402970()
{
    sub_40856b(2);
    sub_408f26(0x4000);
    data_41ecb0 = 0;

    if (sub_403050(1))
    {
        __fnclex();
        sub_403550();
        sub_403230(sub_403580);
        int32_t var_8_1 = 1;

        if (!sub_408914())
        {
            sub_403360();

            if (sub_4033f0())
                sub_4085f0(sub_403330);

            sub_403380();
            __configthreadlocale(0);

            if (sub_403370())
                j_common_initialize_environment_nolock<char>();

            j_sub_403330();
            return 0;
        }
    }

    sub_403420(7);
    /* no return */
}

int32_t sub_402a50()
{
    int32_t var_8 = 0xfffffffe;
    int32_t var_c = 0x41c998;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_c_1 = var_c ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_38 = __security_cookie_1 ^ &__saved_ebp;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t* var_1c = &var_38;

    if (!sub_403010(1))
    {
        sub_403420(7);
        /* no return */
    }

    char ebx = 0;
    char var_1d = 0;
    int32_t var_8_1 = 0;
    char eax_3 = sub_402fd0();
    int32_t eax_4 = data_41eaf4;

    if (eax_4 == 1)
    {
        sub_403420(7);
        /* no return */
    }

    if (eax_4)
    {
        ebx = 1;
        char var_1d_1 = 1;
    }
    else
    {
        data_41eaf4 = 1;

        if (__initterm_e(0x4161d4, 0x4161f0))
        {
            int32_t var_8_2 = 0xfffffffe;
            fsbase->NtTib.ExceptionList = ExceptionList;
            return 0xff;
        }

        __initterm(0x4161c8, 0x4161d0);
        data_41eaf4 = 2;
    }

    ___scrt_release_startup_lock(eax_3);

    if (data_41f140 && sub_403100(&data_41f140))
        data_41f140(0, 2, 0);

    if (data_41f13c && sub_403100(&data_41f13c))
        sub_408eea(data_41f13c);

    uint32_t esi_2 = sub_403430();
    char* var_40 = sub_408b19();
    int32_t var_44 = 0;
    sub_401000(&__dos_header, esi_2);

    if (!sub_403480())
    {
        sub_408f10(0);
        uint32_t var_24;
        sub_408ed4(var_24);
        breakpoint();
    }

    if (!ebx)
        sub_408ec5();

    sub_403200(1, 0);
    int32_t var_8_3 = 0xfffffffe;
    fsbase->NtTib.ExceptionList = ExceptionList;
    return 0;
}

int32_t sub_402bcf(void* arg1 @ ebp)
{
    int32_t* ecx = *(arg1 - 0x14);
    int32_t eax_1 = **ecx;
    *(arg1 - 0x20) = eax_1;
    return __seh_filter_exe(eax_1, ecx);
}

int32_t _start()
{
    sub_403280();
    /* tailcall */
    return sub_402a50();
}

int32_t sub_402c50(int64_t arg1 @ xcr0)
{
    data_41e188 |= 1;
    data_41eae8 = 0;

    if (IsProcessorFeaturePresent(PF_XMMI64_INSTRUCTIONS_AVAILABLE))
    {
        int32_t ebx;
        int32_t var_34_1 = ebx;
        int32_t eax_1;
        int32_t ecx_1;
        int32_t edx_1;
        int32_t ebx_1;
        eax_1 = __cpuid(0, 0);
        int32_t var_40_2 = ebx;
        int32_t eax_7;
        int32_t ecx_6;
        int32_t edx_2;
        int32_t ebx_3;
        eax_7 = __cpuid(1, 0);
        int32_t var_2c_2 = ebx_3;
        int32_t var_24_2 = edx_2;
        int32_t eax_9;

        if (!((edx_1 ^ 0x49656e69) | (ecx_1 ^ 0x6c65746e) | (ebx_1 ^ 0x756e6547)))
            eax_9 = eax_7 & 0xfff3ff0;

        int32_t edi_2;

        if (!((edx_1 ^ 0x49656e69) | (ecx_1 ^ 0x6c65746e) | (ebx_1 ^ 0x756e6547)) && (
            eax_9 == 0x106c0 || eax_9 == 0x20660 || eax_9 == 0x20670 || eax_9 == 0x30650
            || eax_9 == 0x30660 || eax_9 == 0x30670))
        {
            edi_2 = data_41eaec | 1;
            data_41eaec = edi_2;
        }
        else
            edi_2 = data_41eaec;

        int32_t ebx_5 = 0;
        int32_t esi_3 = 0;
        int32_t var_1c_1 = 0;
        int32_t var_10_1 = 0;
        char var_20_1 = 0;

        if (eax_1 >= 7)
        {
            int32_t eax_10;
            int32_t ecx_7;
            int32_t edx_4;
            int32_t ebx_6;
            eax_10 = __cpuid(7, 0);
            int32_t var_28_3 = ecx_7;
            ebx_5 = ebx_6;
            int32_t var_c_1 = ebx_5;
            var_1c_1 = edx_4;

            if (ebx_5 & 0x200)
                data_41eaec = edi_2 | 2;

            int32_t var_30;

            if (eax_10 < 1)
                esi_3 = 0;
            else
            {
                int32_t var_40_3 = ebx_5;
                int32_t eax_12;
                int32_t ecx_8;
                int32_t edx_5;
                int32_t ebx_7;
                eax_12 = __cpuid(7, 1);
                ebx_5 = var_c_1;
                var_30 = eax_12;
                int32_t var_2c_4 = ebx_7;
                int32_t var_28_4 = ecx_8;
                esi_3 = edx_5;
                var_10_1 = esi_3;
            }

            if (eax_1 >= 0x24)
            {
                int32_t var_40_4 = ebx_5;
                int32_t eax_13;
                int32_t ecx_9;
                int32_t edx_6;
                char ebx_8;
                eax_13 = __cpuid(0x24, 0);
                ebx_5 = var_c_1;
                var_30 = eax_13;
                esi_3 = var_10_1;
                int32_t var_28_5 = ecx_9;
                int32_t var_24_5 = edx_6;
                var_20_1 = ebx_8;
            }
        }

        int32_t eax_16 = data_41e188 | 2;
        int32_t edi_4 = data_41e194;
        int32_t ecx_11 = *data_41e190 & 0xfffffffe;
        data_41eae8 = 1;
        data_41e188 = eax_16;
        *data_41e190 = ecx_11;
        data_41e194 = edi_4;

        if (ecx_6 & 0x100000)
        {
            data_41eae8 = 2;
            data_41e188 = eax_16 | 4;
            *data_41e190 = ecx_11 & 0xffffffef;
            data_41e194 = edi_4;

            if ((ecx_6 & 0x18000000) == 0x18000000)
            {
                int32_t eax_18;
                int32_t edx_8;
                edx_8 = _xgetbv(0, arg1);
                int32_t var_14_2 = edx_8;

                if ((eax_18 & 6) == 6)
                {
                    int32_t eax_22 = data_41e188 | 8;
                    data_41eae8 = 3;
                    data_41e188 = eax_22;
                    int32_t eax_25;
                    int32_t ecx_14;

                    if (!(ebx_5 & 0x20))
                    {
                        ecx_14 = data_41e194;
                        eax_25 = *data_41e190;
                    }
                    else
                    {
                        ecx_14 = data_41e194;
                        data_41e188 = eax_22 | 0x20;
                        eax_25 = *data_41e190 & 0xfffffffd;
                        data_41eae8 = 5;
                        *data_41e190 = eax_25;
                        data_41e194 = ecx_14;

                        if ((ebx_5 & 0xd0030000) == 0xd0030000)
                        {
                            if ((eax_18 & 0xe0) != 0xe0)
                            {
                                ecx_14 = data_41e194;
                                eax_25 = *data_41e190;
                            }
                            else
                            {
                                int32_t eax_28 = *data_41e190;
                                data_41e188 |= 0x40;
                                eax_25 = eax_28 & 0xffffffdb;
                                ecx_14 = data_41e194;
                                data_41eae8 = 6;
                                *data_41e190 = eax_25;
                                data_41e194 = ecx_14;
                            }
                        }
                    }

                    if (var_1c_1 & 0x800000)
                    {
                        data_41e194 = ecx_14;
                        *data_41e190 = eax_25 & 0xfeffffff;
                    }

                    if (esi_3 & 0x80000 && (eax_18 & 0xe0) == 0xe0)
                    {
                        int32_t edx_9 = data_41e194;
                        int32_t ecx_18 = *data_41e190 & 0xfeffffd0;
                        uint32_t eax_33 = var_20_1;
                        data_41eaf0 = eax_33;
                        *data_41e190 = ecx_18;
                        data_41e194 = edx_9;

                        if (eax_33 > 1)
                        {
                            data_41e194 = edx_9;
                            *data_41e190 = ecx_18 & 0xffffffbf;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

void* sub_402f80(void* arg1, int32_t arg2)
{
    void* ecx_1 = *(arg1 + 0x3c) + arg1;
    void* i = *(ecx_1 + 0x14) + 0x18 + ecx_1;

    for (void* edi = i + *(ecx_1 + 6) * 0x28; i != edi; i += 0x28)
    {
        int32_t edx_1 = *(i + 0xc);

        if (arg2 >= edx_1 && arg2 < *(i + 8) + edx_1)
            return i;
    }

    return nullptr;
}

int32_t sub_402fd0()
{
    int32_t i = sub_4035b0();

    if (i)
    {
        TEB* fsbase;
        PVOID StackBase = fsbase->NtTib.Self->NtTib.StackBase;
        i = 0;

        if (0 == data_41eaf8)
            data_41eaf8 = StackBase;
        else
            i = data_41eaf8;

        while (i)
        {
            if (StackBase == i)
            {
                i = 1;
                return i;
            }

            i = 0;

            if (0 == data_41eaf8)
                data_41eaf8 = StackBase;
            else
                i = data_41eaf8;
        }
    }

    i = 0;
    return i;
}

int32_t sub_403010(int32_t arg1)
{
    if (!arg1)
        data_41eafc = 1;

    int64_t xcr0;
    sub_402c50(xcr0);

    if (sub_403e50())
    {
        if (___acrt_initialize())
            return 1;

        ___vcrt_uninitialize(0);
    }

    return 0;
}

int32_t sub_403050(int32_t arg1)
{
    if (data_41eafd)
    {
        int32_t eax;
        eax = 1;
        return eax;
    }

    if (arg1 && arg1 != 1)
    {
        sub_403420(5);
        /* no return */
    }

    int32_t eax_1 = sub_4035b0();

    if (!eax_1 || arg1)
        __builtin_memset(&data_41eb00, 0xff, 0x18);
    else
    {
        eax_1 = __initialize_onexit_table(&data_41eb00);

        if (eax_1)
        {
            eax_1 = 0;
            return eax_1;
        }

        eax_1 = __initialize_onexit_table(&data_41eb0c);

        if (eax_1)
        {
            eax_1 = 0;
            return eax_1;
        }
    }

    data_41eafd = 1;
    eax_1 = 1;
    return eax_1;
}

void* sub_403100(int32_t arg1)
{
    int32_t var_8 = 0xfffffffe;
    int32_t var_c = 0x41c9b8;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_c_1 = var_c ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_2c = __security_cookie_1 ^ &__saved_ebp;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t* var_1c = &var_2c;
    int32_t var_8_1 = 0;
    void* result = sub_402f80(&__dos_header, arg1 - &__dos_header);

    if (result && *(result + 0x24) >= 0)
    {
        int32_t var_8_2 = 0xfffffffe;
        result = 1;
        fsbase->NtTib.ExceptionList = ExceptionList;
        return result;
    }

    int32_t var_8_3 = 0xfffffffe;
    result = 0;
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t sub_4031a2(void* arg1 @ ebp)
{
    int32_t result = 0;
    result = ***(arg1 - 0x14) == 0xc0000005;
    return result;
}

int32_t ___scrt_release_startup_lock(char arg1)
{
    int32_t eax = sub_4035b0();

    if (!eax || arg1)
        return eax;

    int32_t temp0_1 = data_41eaf8;
    data_41eaf8 = 0;
    return temp0_1;
}

int32_t sub_403200(char arg1, char arg2)
{
    int32_t result;

    if (!data_41eafc || !arg2)
    {
        ___acrt_uninitialize(arg1);
        result = ___vcrt_uninitialize(arg1);
    }

    result = 1;
    return result;
}

int32_t sub_403230(int32_t arg1)
{
    if (data_41eb00 == 0xffffffff)
    {
        int32_t ecx = 0;

        if (!sub_409358(arg1))
            ecx = arg1;

        int32_t ecx_1 = -(ecx);
        return -((ecx_1 - ecx_1)) - 1;
    }

    int32_t* var_10 = &data_41eb00;
    int32_t ecx_4 = 0;

    if (!__register_onexit_function())
        ecx_4 = arg1;

    int32_t ecx_5 = -(ecx_4);
    return -((ecx_5 - ecx_5)) - 1;
}

uint32_t* sub_403280()
{
    uint32_t __security_cookie_1 = __security_cookie;

    if (__security_cookie_1 != 0xbb40e64e && __security_cookie_1 & 0xffff0000)
    {
        uint32_t eax = ~__security_cookie_1;
        data_41e180 = eax;
        return eax;
    }

    FILETIME systemTimeAsFileTime;
    __builtin_memset(&systemTimeAsFileTime, 0, 8);
    GetSystemTimeAsFileTime(&systemTimeAsFileTime);
    uint32_t var_8 = systemTimeAsFileTime.dwHighDateTime ^ systemTimeAsFileTime.dwLowDateTime;
    uint32_t eax_3 = GetCurrentThreadId();
    var_8 ^= eax_3;
    uint32_t eax_4 = GetCurrentProcessId();
    var_8 ^= eax_4;
    int32_t performanceCount;
    QueryPerformanceCounter(&performanceCount);
    uint32_t* eax_5 = &var_8;
    int32_t var_14;
    uint32_t ecx_3 = var_14 ^ performanceCount ^ var_8 ^ &var_8;

    if (ecx_3 == 0xbb40e64e)
    {
        __security_cookie = 0xbb40e64f;
        data_41e180 = 0x44bf19b0;
        return eax_5;
    }

    if (!(ecx_3 & 0xffff0000))
    {
        eax_5 = (ecx_3 | 0x4711) << 0x10;
        ecx_3 |= eax_5;
    }

    __security_cookie = ecx_3;
    data_41e180 = ~ecx_3;
    return eax_5;
}

int32_t sub_403330() __pure
{
    return 0;
}

int32_t sub_403340() __pure
{
    return 1;
}

int32_t sub_403350() __pure
{
    return 0x4000;
}

int32_t sub_403360()
{
    return InitializeSListHead(&data_41eb18);
}

int32_t sub_403370() __pure
{
    int32_t result;
    result = 1;
    return result;
}

int32_t sub_403380()
{
    int32_t result = sub_409550(nullptr, 0x10000, 0x30000);

    if (!result)
        return result;

    sub_403420(7);
    /* no return */
}

int32_t sub_4033b0() __pure
{
    return;
}

int32_t sub_4033c0() __pure
{
    return &data_41eb20;
}

int32_t ___scrt_initialize_default_local_stdio_options()
{
    int32_t ecx = data_41f134;
    data_41f130 |= 0x24;
    data_41f134 = ecx;
    int32_t ecx_1 = data_41eb24;
    data_41eb20 |= 2;
    data_41eb24 = ecx_1;
    return &data_41eb20;
}

int32_t sub_4033f0()
{
    int32_t result = 0;
    result = !data_41e19c;
    return result;
}

int32_t sub_403400() __pure
{
    return &data_41f140;
}

int32_t sub_403410() __pure
{
    return &data_41f13c;
}

void sub_403420(int32_t arg1) __noreturn
{
    trap(0xd);
}

uint32_t sub_403430()
{
    void startupInfo;
    _memset(&startupInfo, 0, 0x44);
    GetStartupInfoW(&startupInfo);
    char var_1c;
    int16_t var_18;

    if (var_1c & 1)
        return var_18;
    return 0xa;
}

int32_t j_sub_403330()
{
    /* tailcall */
    return sub_403330();
}

HMODULE sub_403480()
{
    HMODULE result = GetModuleHandleW(nullptr);

    if (result && result->unused == 0x5a4d)
    {
        int32_t* ecx_2 = *(result + 0x3c) + result;

        if (*ecx_2 == 0x4550)
        {
            result = 0x10b;

            if (ecx_2[6] == 0x10b && ecx_2[0x1d] > 0xe)
            {
                result = ecx_2[0x3a];
                return result;
            }
        }
    }

    result = 0;
    return result;
}

LPTOP_LEVEL_EXCEPTION_FILTER ___scrt_set_unhandled_exception_filter()
{
    return SetUnhandledExceptionFilter(___scrt_unhandled_exception_filter@4);
}

int32_t __stdcall ___scrt_unhandled_exception_filter@4(int32_t* arg1)
{
    int32_t* esi = *arg1;

    if (*esi == 0xe06d7363 && esi[4] == 3)
    {
        int32_t eax_1 = esi[5];

        if (eax_1 == 0x19930520 || eax_1 == 0x19930521 || eax_1 == 0x19930522 || eax_1 == 0x1994000)
        {
            *sub_404110() = esi;
            *sub_404120() = arg1[1];
            _terminate();
            /* no return */
        }
    }

    return 0;
}

int32_t sub_403540()
{
    data_41eb28 = 0;
}

void* const sub_403550()
{
    return &data_41c98c;
}

void* const sub_403580()
{
    return &data_41c994;
}

int32_t sub_4035b0()
{
    int32_t result = 0;
    result = data_41f138;
    return result;
}

char* sub_4035c0(char* arg1, char* arg2, void* arg3)
{
    char* esi = arg2;
    void* count = arg3;
    char* edi = arg1;

    if (edi > esi && edi < count + esi)
    {
        int128_t* esi_5 = esi + count;
        int128_t* edi_1 = edi + count;

        if (count >= 0x20)
        {
            if (TEST_BITD(data_41e188, 1))
            {
                while (edi_1 & 0xf)
                {
                    count -= 1;
                    esi_5 -= 1;
                    edi_1 -= 1;
                    *edi_1 = *esi_5;
                }

                while (count >= 0x80)
                {
                    esi_5 -= 0x80;
                    edi_1 -= 0x80;
                    int128_t xmm1_7 = esi_5[1];
                    int128_t xmm2_4 = esi_5[2];
                    int128_t xmm3_7 = esi_5[3];
                    int128_t xmm4_4 = esi_5[4];
                    int128_t xmm5_7 = esi_5[5];
                    int128_t xmm6_1 = esi_5[6];
                    int128_t xmm7_1 = esi_5[7];
                    *edi_1 = *esi_5;
                    edi_1[1] = xmm1_7;
                    edi_1[2] = xmm2_4;
                    edi_1[3] = xmm3_7;
                    edi_1[4] = xmm4_4;
                    edi_1[5] = xmm5_7;
                    edi_1[6] = xmm6_1;
                    edi_1[7] = xmm7_1;
                    count -= 0x80;

                    if (!(count & 0xffffff80))
                        break;
                }

                if (count >= 0x20)
                {
                    do
                    {
                        esi_5 -= 0x20;
                        edi_1 -= 0x20;
                        int128_t xmm1_8 = esi_5[1];
                        *edi_1 = *esi_5;
                        edi_1[1] = xmm1_8;
                        count -= 0x20;
                    } while (count & 0xffffffe0);
                }
            }
            else
            {
                if (edi_1 & 3)
                {
                    void* i_12 = edi_1 & 3;
                    count -= i_12;
                    void* i;

                    do
                    {
                        *(edi_1 - 1) = *(esi_5 - 1);
                        esi_5 -= 1;
                        edi_1 -= 1;
                        i = i_12;
                        i_12 -= 1;
                    } while (i != 1);
                }

                if (count >= 0x20)
                {
                    uint32_t ecx_1 = count >> 2;
                    void* esi_7;
                    void* edi_3;
                    edi_3 = __builtin_memcpy(edi_1 - 4 - (ecx_1 << 2), esi_5 - 4 - (ecx_1 << 2),
                        ecx_1 << 2);

                    switch (count & 3)
                    {
                        case nullptr:
                        {
                            return arg1;
                            break;
                        }
                        case 1:
                        {
                            *(edi_3 + 3) = *(esi_7 + 3);
                            return arg1;
                            break;
                        }
                        case 2:
                        {
                            *(edi_3 + 3) = *(esi_7 + 3);
                            *(edi_3 + 2) = *(esi_7 + 2);
                            return arg1;
                            break;
                        }
                        case 3:
                        {
                            *(edi_3 + 3) = *(esi_7 + 3);
                            *(edi_3 + 2) = *(esi_7 + 2);
                            *(edi_3 + 1) = *(esi_7 + 1);
                            return arg1;
                            break;
                        }
                    }
                }
            }
        }

        while (count & 0xfffffffc)
        {
            edi_1 -= 4;
            esi_5 -= 4;
            *edi_1 = *esi_5;
            count -= 4;
        }

        if (count)
        {
            void* i_1;

            do
            {
                edi_1 -= 1;
                esi_5 -= 1;
                *edi_1 = *esi_5;
                i_1 = count;
                count -= 1;
            } while (i_1 != 1);
        }

        return arg1;
    }

    if (count < 0x20)
    {
    label_403abb:
        void* ecx_2 = count & 0x1f;

        if (ecx_2)
        {
            uint32_t i_9 = ecx_2 >> 2;

            if (i_9)
            {
                uint32_t i_2;

                do
                {
                    *edi = *esi;
                    edi = &edi[4];
                    esi = &esi[4];
                    i_2 = i_9;
                    i_9 -= 1;
                } while (i_2 != 1);
            }

            void* i_10 = ecx_2 & 3;

            if (i_10)
            {
                void* i_3;

                do
                {
                    *edi = *esi;
                    esi = &esi[1];
                    edi = &edi[1];
                    i_3 = i_10;
                    i_10 -= 1;
                } while (i_3 != 1);
            }
        }
    }
    else
    {
        char* esi_2;

        if (count >= 0x80)
        {
            if (TEST_BITD(data_41eaec, 1))
            {
                __builtin_memcpy(edi, esi, count);
                return arg1;
            }

            if (!((edi ^ esi) & 0xf) && TEST_BITD(data_41e188, 1))
            {
                void* eax_22 = esi & 0xf;

                if (eax_22)
                {
                    void* i_11 = (0x10 - eax_22) & 3;

                    if (i_11)
                    {
                        void* i_4;

                        do
                        {
                            *edi = *esi;
                            esi = &esi[1];
                            edi = &edi[1];
                            i_4 = i_11;
                            i_11 -= 1;
                        } while (i_4 != 1);
                    }

                    uint32_t i_8 = (0x10 - eax_22) >> 2;

                    if (i_8)
                    {
                        uint32_t i_5;

                        do
                        {
                            *edi = *esi;
                            esi = &esi[4];
                            edi = &edi[4];
                            i_5 = i_8;
                            i_8 -= 1;
                        } while (i_5 != 1);
                    }

                    count -= 0x10 - eax_22;
                }

                void* count_1 = count;
                count &= 0x7f;
                uint32_t i_13 = count_1 >> 7;

                if (i_13)
                {
                    uint32_t i_6;

                    do
                    {
                        int128_t xmm1_9 = *(esi + 0x10);
                        int128_t xmm2_5 = *(esi + 0x20);
                        int128_t xmm3_8 = *(esi + 0x30);
                        *edi = *esi;
                        *(edi + 0x10) = xmm1_9;
                        *(edi + 0x20) = xmm2_5;
                        *(edi + 0x30) = xmm3_8;
                        int128_t xmm5_8 = *(esi + 0x50);
                        int128_t xmm6_2 = *(esi + 0x60);
                        int128_t xmm7_2 = *(esi + 0x70);
                        *(edi + 0x40) = *(esi + 0x40);
                        *(edi + 0x50) = xmm5_8;
                        *(edi + 0x60) = xmm6_2;
                        *(edi + 0x70) = xmm7_2;
                        esi = &esi[0x80];
                        edi = &edi[0x80];
                        i_6 = i_13;
                        i_13 -= 1;
                    } while (i_6 != 1);
                }

                goto label_403a8d;
            }

            if (!TEST_BITD(data_41eaec, 0) || edi & 3)
                goto label_4037e7;

            if (esi & 3)
                goto label_403804;

            if (TEST_BITD(edi, 2))
            {
                int32_t eax_4 = *esi;
                count -= 4;
                esi = &esi[4];
                *edi = eax_4;
                edi = &edi[4];
            }

            if (TEST_BITD(edi, 3))
            {
                int64_t xmm1_1 = *esi;
                count -= 8;
                esi = &esi[8];
                *edi = xmm1_1;
                edi = &edi[8];
            }

            if (!(esi & 7))
            {
                int128_t xmm1_3 = *(esi - 8);
                void* esi_3 = &esi[0xfffffff8];

                do
                {
                    int128_t xmm3_3 = *(esi_3 + 0x10);
                    count -= 0x30;
                    int128_t xmm0_3 = *(esi_3 + 0x20);
                    int128_t xmm5_3 = *(esi_3 + 0x30);
                    esi_3 += 0x30;
                    *edi = xmm1_3 >> 0x40 | xmm3_3 << 0x40;
                    *(edi + 0x10) = xmm3_3 >> 0x40 | xmm0_3 << 0x40;
                    xmm1_3 = xmm5_3;
                    *(edi + 0x20) = xmm0_3 >> 0x40 | xmm5_3 << 0x40;
                    edi = &edi[0x30];
                } while (count >= 0x30);

                esi_2 = esi_3 + 8;
            }
            else if (!TEST_BITD(esi, 3))
            {
                int128_t xmm1_4 = *(esi - 4);
                void* esi_4 = &esi[0xfffffffc];

                do
                {
                    int128_t xmm3_5 = *(esi_4 + 0x10);
                    count -= 0x30;
                    int128_t xmm0_5 = *(esi_4 + 0x20);
                    int128_t xmm5_5 = *(esi_4 + 0x30);
                    esi_4 += 0x30;
                    *edi = xmm1_4 >> 0x20 | xmm3_5 << 0x60;
                    *(edi + 0x10) = xmm3_5 >> 0x20 | xmm0_5 << 0x60;
                    xmm1_4 = xmm5_5;
                    *(edi + 0x20) = xmm0_5 >> 0x20 | xmm5_5 << 0x60;
                    edi = &edi[0x30];
                } while (count >= 0x30);

                esi_2 = esi_4 + 4;
            }
            else
            {
                int128_t xmm1_2 = *(esi - 0xc);
                void* esi_1 = &esi[0xfffffff4];

                do
                {
                    int128_t xmm3_1 = *(esi_1 + 0x10);
                    count -= 0x30;
                    int128_t xmm0_1 = *(esi_1 + 0x20);
                    int128_t xmm5_1 = *(esi_1 + 0x30);
                    esi_1 += 0x30;
                    *edi = xmm1_2 >> 0x60 | xmm3_1 << 0x20;
                    *(edi + 0x10) = xmm3_1 >> 0x60 | xmm0_1 << 0x20;
                    xmm1_2 = xmm5_1;
                    *(edi + 0x20) = xmm0_1 >> 0x60 | xmm5_1 << 0x20;
                    edi = &edi[0x30];
                } while (count >= 0x30);

                esi_2 = esi_1 + 0xc;
            }

            while (count >= 0x10)
            {
                int128_t xmm1_5 = *esi_2;
                count -= 0x10;
                esi_2 = &esi_2[0x10];
                *edi = xmm1_5;
                edi = &edi[0x10];
            }

            if (TEST_BITD(count, 2))
            {
                int32_t eax_5 = *esi_2;
                count -= 4;
                esi_2 = &esi_2[4];
                *edi = eax_5;
                edi = &edi[4];
            }

            if (TEST_BITD(count, 3))
            {
                int64_t xmm1_6 = *esi_2;
                count -= 8;
                esi_2 = &esi_2[8];
                *edi = xmm1_6;
                edi = &edi[8];
            }

            switch (count)
            {
                case 1:
                {
                    *edi = *esi_2;
                    break;
                }
                case 2:
                {
                    goto label_40384a;
                }
                case 3:
                {
                    goto label_40385e;
                }
            }
        }
        else if (TEST_BITD(data_41e188, 1))
        {
        label_403a8d:

            if (count)
            {
                uint32_t i_14 = count >> 5;

                if (i_14)
                {
                    uint32_t i_7;

                    do
                    {
                        int128_t xmm1_10 = *(esi + 0x10);
                        *edi = *esi;
                        *(edi + 0x10) = xmm1_10;
                        esi = &esi[0x20];
                        edi = &edi[0x20];
                        i_7 = i_14;
                        i_14 -= 1;
                    } while (i_7 != 1);
                }

                goto label_403abb;
            }
        }
        else
        {
        label_4037e7:

            while (edi & 3)
            {
                *edi = *esi;
                count -= 1;
                esi = &esi[1];
                edi = &edi[1];
            }

        label_403804:

            if (count < 0x20)
                goto label_403abb;

            edi = __builtin_memcpy(edi, esi, count & 0xfffffffc);

            switch (count & 3)
            {
                case 1:
                {
                    *edi = *esi_2;
                    break;
                }
                case 2:
                {
                label_40384a:
                    *edi = *esi_2;
                    edi[1] = esi_2[1];
                    break;
                }
                case 3:
                {
                label_40385e:
                    *edi = *esi_2;
                    edi[1] = esi_2[1];
                    edi[2] = esi_2[2];
                    break;
                }
            }
        }
    }

    return arg1;
}

int32_t __fastcall sub_40381c(int32_t arg1)
{
    /* jump -> *((arg1 << 2) + &data_403834) */
}

uint32_t (*)[0x4] _memset(uint32_t (* arg1)[0x4], char arg2, void* arg3)
{
    void* i = arg3;
    uint32_t (* edi)[0x4] = arg1;

    if (i)
    {
        uint32_t eax_1 = arg2 * 0x1010101;

        if (i <= 0x20)
        {
        label_403c4b:

            while (i & 3)
            {
                *edi = eax_1;
                edi += 1;
                i -= 1;
            }

            if (i & 4)
            {
                *edi = eax_1;
                edi = &(*edi)[1];
                i -= 4;
            }

            while (i & 0xfffffff8)
            {
                *edi = eax_1;
                (*edi)[1] = eax_1;
                edi = &(*edi)[2];
                i -= 8;
            }
        }
        else
        {
            uint32_t xmm0_2[0x4];

            if (i >= 0x80)
            {
                if (TEST_BITD(data_41eaec, 1))
                {
                    int32_t ecx;
                    int32_t edi_1;
                    edi_1 = __memfill_u8(edi, eax_1, i);
                    return arg1;
                }

                if (!TEST_BITD(data_41e188, 1))
                    goto label_403c4b;

                xmm0_2 = _mm_shuffle_epi32(eax_1, 0);
                void* ecx_1 = i + edi;
                *edi = xmm0_2;
                edi = &edi[1] & 0xfffffff0;
                i = ecx_1 - edi;

                if (i <= 0x80)
                    goto label_403c05;

                do
                {
                    *edi = xmm0_2;
                    edi[1] = xmm0_2;
                    edi[2] = xmm0_2;
                    edi[3] = xmm0_2;
                    edi[4] = xmm0_2;
                    edi[5] = xmm0_2;
                    edi[6] = xmm0_2;
                    edi[7] = xmm0_2;
                    edi = &edi[8];
                    i -= 0x80;
                } while (i & 0xffffff00);

                goto label_403c10;
            }

        label_403c05:

            if (!TEST_BITD(data_41e188, 1))
                goto label_403c4b;

            xmm0_2 = _mm_shuffle_epi32(eax_1, 0);
        label_403c10:

            if (i < 0x20)
            {
            label_403c35:
                *(edi + i - 0x20) = xmm0_2;
                *(edi + i - 0x10) = xmm0_2;
                return arg1;
            }

            do
            {
                *edi = xmm0_2;
                edi[1] = xmm0_2;
                edi = &edi[2];
                i -= 0x20;
            } while (i >= 0x20);

            if (i & 0x1f)
                goto label_403c35;
        }
    }

    return arg1;
}

int32_t _ValidateLocalCookies(int32_t* arg1, int32_t arg2)
{
    int32_t eax = *arg1;

    if (eax != 0xfffffffe)
        sub_402910((arg1[1] + arg2) ^ *(eax + arg2));

    /* tailcall */
    return sub_402910((arg1[3] + arg2) ^ *(arg1[2] + arg2));
}

int32_t sub_403ce0(int32_t* arg1, void* arg2, void* arg3)
{
    char var_5 = 0;
    int32_t result = 1;
    int32_t mxcsr;
    *arg1 = sub_4155c0(mxcsr, *arg1);
    void* esi = arg2 + 0x10;
    int32_t* eax_2 = *(arg2 + 8) ^ __security_cookie;
    _ValidateLocalCookies(eax_2, esi);
    sub_4042b0(arg3);
    int32_t edi = *(arg2 + 0xc);

    if (!(arg1[1] & 0x66))
    {
        int32_t* var_24 = arg1;
        void* var_20_1 = arg3;
        *(arg2 - 4) = &var_24;

        if (edi != 0xfffffffe)
        {
            void* ecx_2 = &eax_2[4];
            void* var_14_1 = ecx_2;
            char ecx_5;

            while (true)
            {
                int32_t eax_5 = edi * 3;
                int32_t ebx_2 = *(ecx_2 + (eax_5 << 2));

                if (!*(ecx_2 + (eax_5 << 2) + 4))
                    ecx_5 = var_5;
                else
                {
                    int32_t eax_6 = @_EH4_CallFilterFunc@8();
                    ecx_5 = 1;
                    var_5 = 1;

                    if (eax_6 < 0)
                    {
                        result = 0;
                        goto label_403db1_1;
                    }

                    if (eax_6 > 0)
                    {
                        EXCEPTION_RECORD* eax_8 = arg1;

                        if (eax_8->ExceptionCode == 0xe06d7363)
                        {
                            if (__IsNonwritableInCurrentImage(&data_4162e0))
                            {
                                int32_t var_34_2 = 1;
                                sub_403ed0(arg1);
                            }

                            eax_8 = arg1;
                        }

                        @_EH4_GlobalUnwind2@8(arg2, eax_8);
                        void* eax_10 = arg2;

                        if (*(eax_10 + 0xc) != edi)
                        {
                            @_EH4_LocalUnwind@16(eax_10, edi, esi, &__security_cookie);
                            eax_10 = arg2;
                        }

                        *(eax_10 + 0xc) = ebx_2;
                        _ValidateLocalCookies(eax_2, esi);
                        @_EH4_TransferToHandler@8(*(ecx_2 + (eax_5 << 2) + 8), esi);
                        breakpoint();
                    }
                }

                edi = ebx_2;

                if (ebx_2 == 0xfffffffe)
                    break;

                ecx_2 = var_14_1;
            }

            if (ecx_5)
            {
            label_403db1:
                _ValidateLocalCookies(eax_2, esi);
            }
        }
    }
    else if (edi != 0xfffffffe)
    {
        @_EH4_LocalUnwind@16(arg2, 0xfffffffe, esi, &__security_cookie);
    label_403db1_1:
        _ValidateLocalCookies(eax_2, esi);
    }

    return result;
}

int32_t sub_403e50()
{
    if (sub_404430())
    {
        if (sub_4043c0())
            return 1;

        sub_404490();
    }

    return 0;
}

int32_t ___vcrt_uninitialize(char arg1)
{
    int32_t result;

    if (!arg1)
    {
        sub_404410();
        result = sub_404490();
    }

    result = 1;
    return result;
}

int32_t sub_403e90(void* arg1, void* arg2)
{
    if (arg1 != arg2)
    {
        char* eax_1 = arg2 + 5;
        char* ecx_1 = arg1 + 5;

        while (true)
        {
            char edx_1 = *ecx_1;
            char temp0_1 = *eax_1;
            bool c_1 = edx_1 < temp0_1;

            if (edx_1 == temp0_1)
            {
                if (!edx_1)
                    break;

                edx_1 = ecx_1[1];
                char temp1_1 = eax_1[1];
                c_1 = edx_1 < temp1_1;

                if (edx_1 == temp1_1)
                {
                    ecx_1 = &ecx_1[2];
                    eax_1 = &eax_1[2];

                    if (!edx_1)
                        break;

                    continue;
                }
            }

            return (eax_1 - eax_1) | 1;
        }
    }

    return 0;
}

int32_t* sub_403ed0(int32_t* arg1)
{
    int32_t var_8 = 0xfffffffe;
    int32_t var_c = 0x41c9d8;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_c_1 = var_c ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_2c = __security_cookie_1 ^ &__saved_ebp;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t* var_1c = &var_2c;
    int32_t* eax_2 = arg1;

    if (eax_2 && *eax_2 == 0xe06d7363 && eax_2[4] == 3)
    {
        int32_t ecx_1 = eax_2[5];

        if (ecx_1 == 0x19930520 || ecx_1 == 0x19930521 || ecx_1 == 0x19930522)
        {
            char* ecx_2 = eax_2[7];

            if (ecx_2)
            {
                int32_t edx_1 = *(ecx_2 + 4);

                if (edx_1)
                {
                    int32_t var_8_1 = 0;
                    int32_t eax_3 = sub_403fe0(eax_2[6], edx_1);
                    int32_t var_8_2 = 0xfffffffe;
                    fsbase->NtTib.ExceptionList = ExceptionList;
                    return eax_3;
                }

                if (*ecx_2 & 0x10)
                {
                    eax_2 = eax_2[6];
                    int32_t* ecx_5 = *eax_2;

                    if (ecx_5)
                        eax_2 = (*(*ecx_5 + 8))(ecx_5);
                }
            }
        }
    }

    fsbase->NtTib.ExceptionList = ExceptionList;
    return eax_2;
}

int32_t sub_403f7a(void* arg1 @ ebp)
{
    sub_403ff0(*(arg1 - 0x14), *(arg1 + 0xc));
    return 0;
}

int32_t sub_403f89(int32_t* arg1 @ ebp)
{
    int32_t* esp_4 = arg1[-6];
    arg1[-1] = 0xfffffffe;
    TEB* fsbase;
    fsbase->NtTib.ExceptionList = arg1[-4];
    *esp_4;
    esp_4[1];
    esp_4[2];
    esp_4[3];
    *arg1;
}

int32_t __stdcall sub_403fe0(int32_t arg1, int32_t arg2)
{
    return arg2();
}

int32_t sub_403ff0(int32_t* arg1, char arg2)
{
    if (arg2)
    {
        int32_t* esi_1 = *arg1;

        if (*esi_1 == 0xe06d7363 && esi_1[4] == 3)
        {
            int32_t eax_1 = esi_1[5];

            if (eax_1 == 0x19930520 || eax_1 == 0x19930521 || eax_1 == 0x19930522)
            {
                *(sub_404310() + 0x10) = esi_1;
                *(sub_404310() + 0x14) = arg1[1];
                _terminate();
                /* no return */
            }
        }
    }

    return 0;
}

int32_t sub_404050(int32_t arg1)
{
    for (int32_t* i = *(sub_404310() + 0x24); i; i = i[1])
    {
        if (*i == arg1)
            return 0;
    }

    return 1;
}

void* ___AdjustPointer(int32_t arg1, int32_t* arg2)
{
    int32_t* esi = arg2[1];
    void* result = *arg2 + arg1;

    if (esi < 0)
        return result;

    return result + *(*(esi + arg1) + arg2[2]) + esi;
}

int32_t sub_4040b0(int32_t* arg1)
{
    int32_t* edi = *arg1;
    int32_t eax = *edi;

    if (eax == 0xe0434352 || eax == 0xe0434f4d)
    {
        if (*(sub_404310() + 0x18) > 0)
        {
            void* eax_2 = sub_404310();
            *(eax_2 + 0x18) -= 1;
        }
    }
    else if (eax == 0xe06d7363)
    {
        *(sub_404310() + 0x10) = edi;
        *(sub_404310() + 0x14) = arg1[1];
        _terminate();
        /* no return */
    }

    return 0;
}

int32_t sub_404110()
{
    return sub_404310() + 0x10;
}

int32_t sub_404120()
{
    return sub_404310() + 0x14;
}

void j__terminate() __noreturn
{
    /* tailcall */
    return _terminate();
}

void* __local_unwind4(int32_t arg1, void* arg2, int32_t arg3)
{
    int32_t ebp;
    int32_t var_10 = ebp;
    int32_t var_14 = arg1;
    void* var_18 = arg2;
    int32_t var_1c = arg3;
    int32_t var_20 = arg3;
    int32_t (* var_24)(int32_t arg1, void* arg2, void** arg3 @ 0x10) = __unwind_handler4;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t var_20_1 = __security_cookie ^ &ExceptionList;
    fsbase->NtTib.ExceptionList = &ExceptionList;

    while (true)
    {
        int32_t esi_1 = *(arg2 + 0xc);

        if (esi_1 == 0xfffffffe)
        {
            fsbase->NtTib.ExceptionList = ExceptionList;
            return arg2;
        }

        if (arg3 != 0xfffffffe && esi_1 <= arg3)
        {
            fsbase->NtTib.ExceptionList = ExceptionList;
            return arg2;
        }

        int32_t* ebx_3 = (*(arg2 + 8) ^ *arg1) + esi_1 * 0xc + 0x10;
        *(arg2 + 0xc) = *ebx_3;

        if (!ebx_3[1])
        {
            __NLG_Notify(ebx_3[2], ebp, 0x101);
            ebx_3[2];
            sub_4044f0();
        }
    }
}

int32_t __unwind_handler4(int32_t arg1, void* arg2, void** arg3 @ 0x10)
{
    if (!(*(arg1 + 4) & 6))
        return 1;

    sub_402910(*(arg2 + 8) ^ arg2);
    *(arg2 + 0x18);
    __local_unwind4(*(arg2 + 0x14), *(arg2 + 0x10), *(arg2 + 0xc));
    *arg3 = arg2;
    return 3;
}

int32_t @_EH4_CallFilterFunc@8()
{
    int32_t ecx;
    return ecx();
}

int32_t __fastcall @_EH4_TransferToHandler@8(int32_t arg1, int32_t arg2)
{
    __NLG_Notify(arg1, arg2, 1);
    /* jump -> arg1 */
}

int32_t __fastcall @_EH4_GlobalUnwind2@8(int32_t arg1, EXCEPTION_RECORD* arg2)
{
    return RtlUnwind(arg1, &data_404285, arg2, nullptr);
}

void* __fastcall @_EH4_LocalUnwind@16(void* arg1, int32_t arg2, int32_t arg3, int32_t arg4)
{
    return __local_unwind4(arg4, arg1, arg2);
}

void sub_4042b0(void* arg1)
{
    return;
}

int32_t __stdcall sub_4042f0(int32_t arg1)
{
    if (arg1 && arg1 != &data_41eb30)
        return j___free_base(arg1);

    return arg1;
}

int32_t sub_404310()
{
    if (data_41e1a0 != 0xffffffff)
    {
        enum WIN32_ERROR dwErrCode = GetLastError();
        int32_t lpFlsData = FlsGetValue(data_41e1a0);

        if (lpFlsData != 0xffffffff)
        {
            if (lpFlsData)
            {
                SetLastError(dwErrCode);
                return lpFlsData;
            }

            if (FlsSetValue(data_41e1a0, 0xffffffff))
            {
                int32_t var_c_2 = 0x28;
                int32_t var_10_2 = 1;
                lpFlsData = sub_409700();

                if (!lpFlsData)
                {
                    FlsSetValue(data_41e1a0, nullptr);
                    j___free_base(0);
                }
                else
                {
                    if (FlsSetValue(data_41e1a0, lpFlsData))
                    {
                        j___free_base(0);
                        SetLastError(dwErrCode);
                        return lpFlsData;
                    }

                    FlsSetValue(data_41e1a0, nullptr);
                    j___free_base(lpFlsData);
                }
            }
        }

        SetLastError(dwErrCode);
    }

    sub_4096af();
    /* no return */
}

uint32_t sub_4043c0()
{
    uint32_t dwFlsIndex = FlsAlloc(sub_4042f0);
    data_41e1a0 = dwFlsIndex;

    if (dwFlsIndex != 0xffffffff)
    {
        BOOL eax = FlsSetValue(dwFlsIndex, &data_41eb30);

        if (eax)
        {
            eax = 1;
            return eax;
        }

        dwFlsIndex = data_41e1a0;

        if (dwFlsIndex != 0xffffffff)
        {
            dwFlsIndex = FlsFree(dwFlsIndex);
            data_41e1a0 = 0xffffffff;
        }
    }

    dwFlsIndex = 0;
    return dwFlsIndex;
}

BOOL sub_404410()
{
    BOOL dwFlsIndex = data_41e1a0;

    if (dwFlsIndex != 0xffffffff)
    {
        dwFlsIndex = FlsFree(dwFlsIndex);
        data_41e1a0 = 0xffffffff;
    }

    dwFlsIndex = 1;
    return dwFlsIndex;
}

BOOL sub_404430()
{
    int32_t esi = 0;
    BOOL result;

    while (true)
    {
        result = InitializeCriticalSectionEx(esi * 0x18 + &data_41eb58, 0xfa0, 0);

        if (!result)
            break;

        data_41eb70 += 1;
        esi += 1;

        if (esi >= 1)
        {
            result = 1;
            return result;
        }
    }

    int32_t i_1 = data_41eb70;

    if (i_1)
    {
        int32_t i;

        do
        {
            result = DeleteCriticalSection(i_1 * 0x18 + &data_41eb40);
            data_41eb70 -= 1;
            i = i_1;
            i_1 -= 1;
        } while (i != 1);
    }

    result = 0;
    return result;
}

int32_t sub_404490()
{
    int32_t i_1 = data_41eb70;
    int32_t result;

    if (i_1)
    {
        int32_t i;

        do
        {
            result = DeleteCriticalSection(i_1 * 0x18 + &data_41eb40);
            data_41eb70 -= 1;
            i = i_1;
            i_1 -= 1;
        } while (i != 1);
    }

    result = 1;
    return result;
}

int32_t __convention("regparm") sub_4044c0(int32_t arg1, int32_t, int32_t arg3, int32_t arg4 @ ebp)
{
    int32_t var_8 = arg3;
    data_41e1b8 = arg3;
    data_41e1b4 = arg1;
    data_41e1bc = arg4;
    int32_t var_c = arg4;
    int32_t var_10 = arg3;
    return arg1;
}

int32_t __stdcall __NLG_Notify(int32_t arg1 @ eax, int32_t arg2 @ ebp, int32_t arg3)
{
    data_41e1b8 = arg3;
    data_41e1b4 = arg1;
    data_41e1bc = arg2;
    int32_t var_c = arg2;
    int32_t var_10 = arg3;
    return arg1;
}

int32_t sub_4044f0()
{
    int32_t eax;
    return eax();
}

int32_t* sub_404500(int32_t* arg1, int32_t arg2, int32_t arg3, void* arg4 @ 0x14, int32_t arg5)
{
    int32_t ecx = *(arg4 + 0x10);
    int32_t eax_1 = *(arg4 + 0xc);
    int32_t ecx_1 = eax_1;
    int32_t esi = ecx_1;
    int32_t edi = ecx_1;

    if (arg5 >= 0)
    {
        int32_t i;

        do
        {
            if (ecx_1 == 0xffffffff)
                goto label_40457e;

            ecx_1 -= 1;
            int32_t eax_2 = ecx_1 * 5;
            i = arg5;

            if (*(ecx + (eax_2 << 2) + 4) < arg3)
            {
                i = arg5;

                if (arg3 <= *(ecx + (eax_2 << 2) + 8) || ecx_1 == 0xffffffff)
                {
                label_40454e:
                    i -= 1;
                    esi = edi;
                    arg5 = i;
                    edi = ecx_1;
                }
            }
            else if (ecx_1 == 0xffffffff)
                goto label_40454e;
        } while (i >= 0);
    }

    if (esi > eax_1 || ecx_1 + 1 > esi)
    {
    label_40457e:
        sub_4096af();
        /* no return */
    }

    arg1[3] = esi;
    *arg1 = arg2;
    arg1[1] = ecx_1 + 1;
    arg1[2] = arg2;
    return arg1;
}

int32_t sub_404590(int32_t* arg1, int32_t arg2, int32_t arg3, int32_t arg4, int32_t arg5)
{
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList;
    int32_t var_14 = &ExceptionList ^ __security_cookie;
    int32_t var_10 = arg2;
    ExceptionList = nullptr;
    int32_t (* var_18)(int32_t* arg1, void** arg2, void* arg3) = sub_4047b0;
    int32_t* var_c = arg1;
    int32_t var_8 = arg4 + 1;
    TEB* fsbase;
    ExceptionList = fsbase->NtTib.ExceptionList;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t result = __CallSettingFrame@12(arg1, arg3, arg1, arg5);
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t sub_404600(int32_t* arg1, int32_t* arg2, int32_t arg3, int32_t arg4 @ 0x14, int32_t arg5, int32_t arg6)
{
    if (arg1 == 0x123)
    {
        *arg2 = 0x4046da;
        return 1;
    }

    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = nullptr;
    int32_t (__convention("regparm")* var_3c_1)(int32_t arg1, int32_t arg2, int32_t arg3,
        EXCEPTION_RECORD* arg4, void* arg5, void* arg6) = __TranslatorGuardHandler;
    int32_t var_38_1 = __security_cookie ^ &ExceptionList;
    int32_t var_34_1 = arg4;
    int32_t* var_30_1 = arg2;
    int32_t var_2c_1 = arg5;
    int32_t var_28_1 = arg6;
    int32_t var_24_1 = 0;
    int32_t var_20_1 = 0;
    int32_t var_1c_1 = 0;
    int32_t __saved_ebx;
    int32_t* var_24_2 = &__saved_ebx;
    int32_t __saved_ebp;
    int32_t* var_20_2 = &__saved_ebp;
    TEB* fsbase;
    ExceptionList = fsbase->NtTib.ExceptionList;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t mxcsr;
    *arg1 = sub_4155c0(mxcsr, *arg1);
    int32_t var_c_1 = 1;
    int32_t* var_18 = arg1;
    int32_t var_14_1 = arg3;
    int32_t edx_4 = *(sub_404310() + 8);
    sub_409788();
    edx_4(*arg1, &var_18);
    int32_t result = 0;

    if (!var_1c_1)
        fsbase->NtTib.ExceptionList = ExceptionList;
    else
    {
        struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList_1 = ExceptionList;
        ExceptionList_1->Next = fsbase->NtTib.ExceptionList->Next;
        fsbase->NtTib.ExceptionList = ExceptionList_1;
    }

    return result;
}

int32_t _JumpToContinuation(int32_t arg1, void* arg2)
{
    void* var_8 = arg2 + 0xc;
    TEB* fsbase;
    fsbase->NtTib.ExceptionList = fsbase->NtTib.ExceptionList->Next;
    *(arg2 - 4);
    /* jump -> arg1 */
}

EXCEPTION_RECORD* __stdcall sub_404750(int32_t arg1, EXCEPTION_RECORD* arg2)
{
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    RtlUnwind(arg1, &data_40477f, arg2, nullptr);
    arg2->ExceptionFlags &= 0xfffffffd;
    ExceptionList->Next = fsbase->NtTib.ExceptionList;
    fsbase->NtTib.ExceptionList = ExceptionList;
    return arg2;
}

int32_t sub_4047b0(int32_t* arg1, void** arg2, void* arg3)
{
    sub_402910(arg2[2] ^ arg2);
    return sub_405240(arg1, arg2[4], arg3, 0, arg2[3], arg2[5], arg2, 0);
}

int32_t* __CreateFrameInfo(int32_t* arg1, int32_t arg2)
{
    *arg1 = arg2;
    arg1[1] = *(sub_404310() + 0x24);
    *(sub_404310() + 0x24) = arg1;
    return arg1;
}

void* sub_404820(void* arg1)
{
    if (arg1 == *(sub_404310() + 0x24))
    {
        int32_t esi_1 = *(arg1 + 4);
        void* eax_1 = sub_404310();
        *(eax_1 + 0x24) = esi_1;
        return eax_1;
    }

    void* eax_3 = *(sub_404310() + 0x24);

    while (*(eax_3 + 4))
    {
        int32_t* ecx_1 = eax_3 + 4;
        eax_3 = *ecx_1;

        if (arg1 == eax_3)
        {
            int32_t eax_4 = *(arg1 + 4);
            *ecx_1 = eax_4;
            return eax_4;
        }
    }

    sub_4096af();
    /* no return */
}

int32_t __convention("regparm") __TranslatorGuardHandler(int32_t arg1, int32_t arg2, int32_t arg3, EXCEPTION_RECORD* arg4, void* arg5, void* arg6)
{
    int32_t var_8 = arg3;
    sub_402910(*(arg5 + 8) ^ arg5);

    if (arg4->ExceptionFlags & 0x66)
    {
        *(arg5 + 0x24) = 1;
        return 1;
    }

    sub_405240(arg4, *(arg5 + 0x10), arg6, 0, *(arg5 + 0xc), *(arg5 + 0x14), *(arg5 + 0x18), 1);

    if (!*(arg5 + 0x24))
        sub_404750(arg5, arg4);

    int32_t var_1c_1 = 0;
    sub_404600(0x123, &var_8, 0, 0, 0, 0);
    *(arg5 + 0x1c);
    *(arg5 + 0x20);
    /* jump -> var_8 */
}

int32_t __convention("regparm") sub_404920(int32_t* arg1, int32_t* arg2 @ 0x4, void** arg3 @ 0x8, void* arg4 @ 0xc, int32_t arg5 @ 0x10)
{
    return sub_405240(arg2, arg3, arg4, arg5, arg1, 0, nullptr, 0);
}

int32_t sub_404960(void* arg1, void** arg2, int32_t* arg3, char* arg4)
{
    int32_t var_8 = 0xfffffffe;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_c_1 = 0x41caa0 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_34 = __security_cookie_1 ^ &__saved_ebp;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t* var_1c = &var_34;
    int32_t result = 0;
    void* ecx = arg3[1];

    if (ecx && *(ecx + 8))
    {
        int32_t edx_1 = arg3[2];

        if (edx_1 || *arg3 < 0)
        {
            int32_t ecx_1 = *arg3;
            void** esi = arg2;

            if (ecx_1 >= 0)
                esi = &esi[3] + edx_1;

            int32_t var_8_1 = 0;
            int32_t eax_3;

            if (ecx_1 < 0 && *arg4 & 0x10)
                eax_3 = data_41eb2c;

            void* ecx_3;

            if (ecx_1 < 0 && *arg4 & 0x10 && eax_3)
            {
                ecx_3 = eax_3();
                goto label_4049fe;
            }

            if (!(ecx_1 & 8))
            {
                char edx_2 = *arg4;

                if (!(edx_2 & 1))
                {
                    int32_t ecx_9 = *(arg1 + 0x18);

                    if (*(arg4 + 0x18))
                    {
                        if (ecx_9 && esi)
                        {
                            int32_t ebx = 0;
                            ebx = edx_2 & 4;
                            result = ebx + 1;
                            int32_t result_1 = result;
                        label_404b04:
                            int32_t var_8_5 = 0xfffffffe;
                            fsbase->NtTib.ExceptionList = ExceptionList;
                            return result;
                        }
                    }
                    else if (ecx_9 && esi)
                    {
                        sub_4035c0(esi, ___AdjustPointer(ecx_9, &arg4[8]), *(arg4 + 0x14));
                        int32_t var_8_4 = 0xfffffffe;
                        fsbase->NtTib.ExceptionList = ExceptionList;
                        return 0;
                    }
                }
                else
                {
                    char* eax_9 = *(arg1 + 0x18);

                    if (eax_9 && esi)
                    {
                        sub_4035c0(esi, eax_9, *(arg4 + 0x14));

                        if (*(arg4 + 0x14) == 4)
                        {
                            void* ecx_6 = *esi;

                            if (ecx_6)
                            {
                                *esi = ___AdjustPointer(ecx_6, &arg4[8]);
                                int32_t var_8_3 = 0xfffffffe;
                                fsbase->NtTib.ExceptionList = ExceptionList;
                                return 0;
                            }
                        }

                        goto label_404b04;
                    }
                }
            }
            else
            {
                ecx_3 = *(arg1 + 0x18);
            label_4049fe:

                if (ecx_3 && esi)
                {
                    *esi = ecx_3;
                    *esi = ___AdjustPointer(ecx_3, &arg4[8]);
                    int32_t var_8_2 = 0xfffffffe;
                    fsbase->NtTib.ExceptionList = ExceptionList;
                    return 0;
                }
            }

            sub_4096af();
            /* no return */
        }
    }

    fsbase->NtTib.ExceptionList = ExceptionList;
    return 0;
}

int32_t sub_404b1f() __pure
{
    return 1;
}

int32_t sub_404b50(void* arg1, void** arg2, int32_t* arg3, char* arg4)
{
    int32_t var_8 = 0xfffffffe;
    int32_t var_c = 0x41cac0;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_c_1 = var_c ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_2c = __security_cookie_1 ^ &__saved_ebp;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t* var_1c = &var_2c;
    void** edi;

    if (*arg3 >= 0)
        edi = &arg2[3] + arg3[2];
    else
        edi = arg2;

    int32_t var_8_1 = 0;
    int32_t eax_2 = sub_404960(arg1, arg2, arg3, arg4);
    int32_t result;

    if (eax_2 == 1)
    {
        void* eax_7 = ___AdjustPointer(*(arg1 + 0x18), &arg4[8]);
        result = sub_405900(edi, *(arg4 + 0x18), eax_7);
    }
    else
    {
        result = eax_2 - 2;

        if (eax_2 == 2)
        {
            void* eax_5 = ___AdjustPointer(*(arg1 + 0x18), &arg4[8]);
            result = sub_405910(edi, *(arg4 + 0x18), eax_5, 1);
        }
    }

    int32_t var_8_2 = 0xfffffffe;
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t sub_404c0a() __pure
{
    return 1;
}

void sub_404c10() __noreturn
{
    sub_4096af();
    /* no return */
}

void* sub_404c20(int32_t* arg1, void** arg2, int32_t arg3, int32_t arg4, int32_t* arg5, char arg6, int32_t arg7, void** arg8)
{
    int32_t* esi = arg5;
    void** edi = arg2;
    int32_t var_70 = arg4;
    int32_t ecx = __FrameHandler3::GetCurrentState(edi, esi);
    int32_t var_10 = ecx;

    if (ecx >= 0xffffffff && ecx < esi[1])
    {
        int32_t* ebx_1 = arg1;
        int32_t var_48;
        int32_t var_8_1;
        void* result;
        int32_t edx_1;

        if (*ebx_1 != 0xe06d7363 || ebx_1[4] != 3)
        {
        label_404d54:
            edx_1 = arg3;
            var_8_1 = edx_1;
        label_404d65:
            int32_t* var_3c = esi;
            int32_t var_38_1 = 0;
            int32_t eax_14;

            if (*ebx_1 == 0xe06d7363 && ebx_1[4] == 3)
                eax_14 = ebx_1[5];

            if (*ebx_1 == 0xe06d7363 && ebx_1[4] == 3
                && (eax_14 == 0x19930520 || eax_14 == 0x19930521 || eax_14 == 0x19930522))
            {
                int32_t edi_2 = arg7;

                if (esi[3] > 0)
                {
                    int32_t var_74_1 = arg4;
                    int32_t* var_4c;
                    sub_404500(&var_4c, &var_3c, ecx, esi, edi_2);
                    int32_t edi_3 = var_48;
                    int32_t* edx_2 = var_4c;
                    int32_t* var_34_1 = edx_2;
                    int32_t var_c_1 = edi_3;
                    int32_t var_40;

                    if (edi_3 < var_40)
                    {
                        int32_t eax_15 = edi_3;

                        do
                        {
                            int32_t ecx_3 = eax_15 * 5;
                            int32_t eax_17 = *(*edx_2 + 0x10);
                            int32_t edx_3 = *(eax_17 + (ecx_3 << 2));
                            int32_t edx_4 = *(eax_17 + (ecx_3 << 2) + 4);
                            int32_t edx_5 = *(eax_17 + (ecx_3 << 2) + 0xc);
                            int32_t eax_18 = *(eax_17 + (ecx_3 << 2) + 0x10);

                            if (edx_3 <= var_10 && var_10 <= edx_4)
                            {
                                int32_t ecx_4 = 0;
                                int32_t var_14_1 = 0;

                                if (edx_5)
                                {
                                    int32_t* edx_6 = ebx_1[7];
                                    int32_t* var_24_1 = edx_6;
                                    int32_t* eax_20 = edx_6[3];
                                    int32_t ebx_2 = *eax_20;
                                    char** esi_1 = &eax_20[1];
                                    int32_t var_28_1 = ebx_2;
                                    char** var_30_1 = esi_1;

                                    while (true)
                                    {
                                        char** edi_4 = esi_1;
                                        int32_t esi_2 = ebx_2;
                                        int128_t var_5c = *((ecx_4 << 4) + eax_18);

                                        if (esi_2 > 0)
                                        {
                                            while (true)
                                            {
                                                char* ebx_3 = *edi_4;

                                                if (sub_4051b0(&var_5c, ebx_3, edx_6))
                                                {
                                                    if (!ebx_3)
                                                        ebx_1 = arg1;
                                                    else
                                                    {
                                                        ebx_1 = arg1;
                                                        sub_404b50(ebx_1, arg2, &var_5c, ebx_3);
                                                    }

                                                    void** eax_25 = arg2;

                                                    if (arg8)
                                                        eax_25 = arg8;

                                                    sub_404750(eax_25, ebx_1);
                                                    esi = arg5;
                                                    sub_405710(arg2, arg4, esi, edx_3);
                                                    int32_t* var_80_2 = esi;
                                                    int32_t var_84_1 = arg4;
                                                    sub_4059e0(arg2, edx_4 + 1);
                                                    int32_t eax_28 = sub_405430(ebx_1, arg2,
                                                        var_8_1, esi, *(&var_5c + 0xc), arg7,
                                                        0x100);

                                                    if (eax_28)
                                                        _JumpToContinuation(eax_28, arg2);

                                                    break;
                                                }

                                                edx_6 = var_24_1;
                                                esi_2 -= 1;
                                                edi_4 = &edi_4[1];

                                                if (esi_2 <= 0)
                                                {
                                                    ecx_4 = var_14_1;
                                                    ebx_2 = var_28_1;
                                                    goto label_404e7c;
                                                }
                                            }

                                            break;
                                        }

                                    label_404e7c:
                                        ecx_4 += 1;
                                        var_14_1 = ecx_4;

                                        if (ecx_4 == edx_5)
                                        {
                                            ebx_1 = arg1;
                                            esi = arg5;
                                            break;
                                        }

                                        esi_1 = var_30_1;
                                    }

                                    edi_3 = var_c_1;
                                }
                            }

                            edx_2 = var_34_1;
                            edi_3 += 1;
                            eax_15 = edi_3;
                            var_c_1 = edi_3;
                        } while (eax_15 < var_40);
                    }

                    edi_2 = arg7;
                }

                if (arg6)
                {
                    int32_t var_6c_8 = 1;
                    sub_403ed0(ebx_1);
                }

                if ((*esi & 0x1fffffff) < 0x19930521)
                    goto label_404f8c;

                int32_t* ecx_6 = esi[7];
                uint8_t eax_32 = esi[8] >> 2;

                if (ecx_6)
                {
                    if (!(eax_32 & 1))
                    {
                        if (sub_405860(ebx_1, ecx_6))
                            goto label_404f8c;

                        *(sub_404310() + 0x10) = ebx_1;
                        *(sub_404310() + 0x14) = var_8_1;
                        void** eax_38 = arg2;

                        if (arg8)
                            eax_38 = arg8;

                        sub_404750(eax_38, ebx_1);
                        __FrameHandler3::FrameUnwindToEmptyState(arg2, arg4, esi);
                        int32_t var_6c_14 = sub_405930(esi);
                        sub_405640();
                        /* no return */
                    }
                }
                else if (!(eax_32 & 1) || edi_2)
                    goto label_404f8c;

                *(sub_404310() + 0x10) = ebx_1;
                *(sub_404310() + 0x14) = var_8_1;
                _terminate();
                /* no return */
            }

            if (esi[3] <= 0)
                goto label_404f8c;

            if (!arg6)
            {
                sub_405030(ebx_1, edi, edx_1, arg4, esi, ecx, arg7, arg8);
            label_404f8c:
                result = sub_404310();

                if (!*(result + 0x1c))
                    return result;
            }
        }
        else
        {
            int32_t eax_1 = ebx_1[5];

            if (eax_1 == 0x19930520 || eax_1 == 0x19930521)
            {
                if (ebx_1[7])
                    goto label_404d54;
            }
            else if (eax_1 != 0x19930522 || ebx_1[7])
                goto label_404d54;

            result = sub_404310();

            if (!*(result + 0x10))
                return result;

            ebx_1 = *(sub_404310() + 0x10);
            arg1 = ebx_1;
            var_8_1 = *(sub_404310() + 0x14);

            if (ebx_1)
            {
                if (*ebx_1 != 0xe06d7363 || ebx_1[4] != 3)
                {
                label_404cef:

                    if (*(sub_404310() + 0x1c))
                    {
                        int32_t* edi_1 = *(sub_404310() + 0x1c);
                        *(sub_404310() + 0x1c) = 0;

                        if (!sub_405860(ebx_1, edi_1))
                        {
                            int32_t i = 0;

                            if (*edi_1 > 0)
                            {
                                do
                                {
                                    if (!sub_403e90(*(edi_1[1] + i * 0x10 + 4) + 4,
                                        &class std::bad_exception `RTTI Type Descriptor'.spare))
                                    {
                                        int32_t var_6c_11 = 1;
                                        sub_403ed0(ebx_1);
                                        sub_405390(&var_48);
                                        sub_405a90(&var_48, 0x41cadc);
                                        /* no return */
                                    }

                                    i += 1;
                                } while (i < *edi_1);
                            }

                            _terminate();
                            /* no return */
                        }

                        edi = arg2;
                    }

                    edx_1 = var_8_1;
                    ecx = var_10;
                    goto label_404d65;
                }

                int32_t eax_5 = ebx_1[5];

                if (eax_5 == 0x19930520 || eax_5 == 0x19930521)
                {
                    if (ebx_1[7])
                        goto label_404cef;
                }
                else if (eax_5 != 0x19930522 || ebx_1[7])
                    goto label_404cef;
            }
        }
    }

    sub_4096af();
    /* no return */
}

int32_t* sub_405030(int32_t* arg1, int32_t* arg2, int32_t arg3, int32_t arg4, void* arg5, int32_t arg6, int32_t arg7, int32_t* arg8)
{
    int32_t* result = arg1;

    if (*result != 0x80000003)
    {
        if (!*(sub_404310() + 8))
        {
        label_4050a1:
            void* var_20 = arg5;
            int32_t var_1c_1 = 0;

            if (*(arg5 + 0xc) <= 0)
            {
                sub_4096af();
                /* no return */
            }

            int32_t var_48_2 = arg4;
            int32_t* result_1;
            sub_404500(&result_1, &var_20, arg6, arg5, arg7);
            int32_t var_2c;
            int32_t esi_2 = var_2c;
            result = result_1;
            int32_t* result_2 = result;
            int32_t var_24;

            if (esi_2 < var_24)
            {
                int32_t ecx_2 = esi_2;

                do
                {
                    int32_t ecx_3 = ecx_2 * 5;
                    int32_t eax_5 = *(*result + 0x10);
                    int32_t edx_1 = *(eax_5 + (ecx_3 << 2));
                    int32_t edx_2 = *(eax_5 + (ecx_3 << 2) + 4);
                    int32_t ecx_4 = *(eax_5 + (ecx_3 << 2) + 0x10);

                    if (edx_1 <= arg6 && arg6 <= edx_2)
                    {
                        int32_t edx_4 = *(eax_5 + (ecx_3 << 2) + 0xc) << 4;
                        void* eax_7 = *(edx_4 + ecx_4 - 0xc);

                        if ((!eax_7 || !*(eax_7 + 8)) && !(*(edx_4 + ecx_4 - 0x10) & 0x40))
                        {
                            int32_t* eax_8 = arg2;

                            if (arg8)
                                eax_8 = arg8;

                            sub_404750(eax_8, arg1);
                            sub_405710(arg2, arg4, arg5, edx_1);
                            void* var_54_3 = arg5;
                            int32_t var_58_2 = arg4;
                            sub_4059e0(arg2, edx_2 + 1);
                            int32_t eax_12 = sub_405430(arg1, arg2, arg3, arg5,
                                *(edx_4 + ecx_4 - 4), arg7, 0x100);

                            if (eax_12)
                                _JumpToContinuation(eax_12, arg2);
                        }
                    }

                    result = result_2;
                    esi_2 += 1;
                    ecx_2 = esi_2;
                } while (ecx_2 < var_24);
            }
        }
        else
        {
            if (*(sub_404310() + 8) == EncodePointer(nullptr))
                goto label_4050a1;

            int32_t* eax_3 = arg1;
            int32_t ecx_1 = *eax_3;

            if (ecx_1 == 0xe0434f4d || ecx_1 == 0xe0434352)
                goto label_4050a1;

            int32_t var_4c_1 = arg4;
            result = sub_404600(eax_3, arg2, arg3, arg5, arg7, arg8);

            if (!result)
                goto label_4050a1;
        }
    }

    return result;
}

int32_t sub_4051b0(int32_t* arg1, char* arg2, int32_t* arg3)
{
    void* ecx = arg1[1];

    if (ecx)
    {
        char* eax_1 = ecx + 8;

        if (*(ecx + 8))
        {
            char ebx_1 = *arg1;

            if (ebx_1 >= 0 || !(*arg2 & 0x10))
            {
                void* edx_1 = *(arg2 + 4);

                if (ecx != edx_1)
                {
                    char* ecx_1 = edx_1 + 8;
                    int32_t eax_3;

                    while (true)
                    {
                        char edx_2 = *eax_1;
                        char temp0_1 = *ecx_1;
                        bool c_1 = edx_2 < temp0_1;

                        if (edx_2 == temp0_1)
                        {
                            if (!edx_2)
                            {
                                eax_3 = 0;
                                break;
                            }

                            edx_2 = eax_1[1];
                            char temp1_1 = ecx_1[1];
                            c_1 = edx_2 < temp1_1;

                            if (edx_2 == temp1_1)
                            {
                                eax_1 = &eax_1[2];
                                ecx_1 = &ecx_1[2];

                                if (edx_2)
                                    continue;

                                eax_3 = 0;
                                break;
                            }
                        }

                        eax_3 = (eax_1 - eax_1) | 1;
                        break;
                    }

                    if (eax_3 || (*arg2 & 2 && !(ebx_1 & 8)))
                        return 0;
                }
                else if (*arg2 & 2 && !(ebx_1 & 8))
                    return 0;

                char eax_6 = *arg3;

                if (eax_6 & 1 && !(ebx_1 & 1))
                    return 0;

                if (eax_6 & 2 && !(ebx_1 & 2))
                    return 0;
            }
        }
    }

    return 1;
}

int32_t sub_405240(int32_t* arg1, void** arg2, void* arg3, int32_t arg4, int32_t* arg5, int32_t arg6, void** arg7, char arg8)
{
    sub_4042b0(arg3);
    void* eax = sub_404310();
    int32_t eax_1;

    if (!*(eax + 0x20))
        eax_1 = *arg1;

    if (*(eax + 0x20) || eax_1 == 0xe06d7363 || eax_1 == 0x80000026
        || (*arg5 & 0x1fffffff) < 0x19930522 || !(arg5[8] & 1))
    {
        if (!(arg1[1] & 0x66))
        {
            if (arg5[3])
            {
            label_4052f1:

                if (*arg1 == 0xe06d7363 && arg1[4] >= 3 && arg1[5] > 0x19930522)
                {
                    int32_t edi_1 = *(arg1[7] + 8);

                    if (edi_1)
                        return edi_1(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
                }

                sub_404c20(arg1, arg2, arg3, arg4, arg5, arg8, arg6, arg7);
            }
            else
            {
                int32_t eax_6 = *arg5 & 0x1fffffff;

                if (eax_6 >= 0x19930521 && arg5[7])
                    goto label_4052f1;

                if (eax_6 >= 0x19930522 && arg5[8] >> 2 & 1)
                    goto label_4052f1;
            }

            return 1;
        }

        if (arg5[1] && !arg6)
            sub_405710(arg2, arg4, arg5, 0xffffffff);
    }

    return 1;
}

struct std::exception::VTable** __thiscall sub_405350(struct std::exception::VTable** arg1, void* arg2)
{
    *arg1 = &std::exception::`vftable';
    *(arg1 + 4) = 0;
    sub_4059f0(arg2 + 4, &arg1[1]);
    *arg1 = &std::bad_exception::`vftable'{for `std::exception'};
    return arg1;
}

struct std::exception::std::bad_exception::VTable** __fastcall sub_405390(struct std::exception::std::bad_exception::VTable** arg1)
{
    *(arg1 + 4) = 0;
    arg1[1] = "bad exception";
    *arg1 = &std::bad_exception::`vftable'{for `std::exception'};
    return arg1;
}

struct std::exception::VTable** __thiscall sub_4053b0(struct std::exception::VTable** arg1, void* arg2)
{
    *arg1 = &std::exception::`vftable';
    *(arg1 + 4) = 0;
    sub_4059f0(arg2 + 4, &arg1[1]);
    return arg1;
}

int32_t __fastcall sub_4053e0(struct std::exception::VTable** arg1)
{
    *arg1 = &std::exception::`vftable';
    return sub_405a60(&arg1[1]);
}

struct std::exception::VTable** __thiscall sub_405400(struct std::exception::VTable** arg1, char arg2)
{
    *arg1 = &std::exception::`vftable';
    sub_405a60(&arg1[1]);

    if (arg2 & 1)
    {
        int32_t var_c_1 = 0xc;
        sub_414ef0(arg1);
    }

    return arg1;
}

int32_t sub_405430(int32_t* arg1, int32_t* arg2, int32_t arg3, int32_t arg4, int32_t arg5, int32_t arg6, int32_t arg7)
{
    int32_t var_8 = 0xfffffffe;
    int32_t var_c = 0x41ca20;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_c_1 = var_c ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_5c = __security_cookie_1 ^ &__saved_ebp;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t* var_1c = &var_5c;
    int32_t var_20 = arg5;
    int32_t var_40 = 0;
    int32_t var_30 = arg2[-1];
    void var_4c;
    int32_t* var_34 = __CreateFrameInfo(&var_4c, arg1[6]);
    int32_t var_38 = *(sub_404310() + 0x10);
    int32_t var_3c = *(sub_404310() + 0x14);
    *(sub_404310() + 0x10) = arg1;
    *(sub_404310() + 0x14) = arg3;
    int32_t var_8_1 = 0;
    int32_t var_44 = 1;
    int32_t var_8_2 = 1;
    int32_t result = sub_404590(arg2, arg4, arg5, arg6, arg7);
    int32_t result_1 = result;
    int32_t var_8_3 = 0;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_44_1 = 0;
    sub_4055ba(&__saved_ebp, arg1, result);
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t sub_4054f0(void* arg1 @ ebp)
{
    return sub_4056a0(*(arg1 - 0x14));
}

int32_t sub_4054fc(int32_t* arg1 @ ebp)
{
    int32_t esp_14 = arg1[-6];
    *(sub_404310() + 0x20) = 0;
    void* edi = arg1[5];
    arg1[-9] = *(edi + 8);
    *(esp_14 - 4) = edi;
    *(esp_14 - 8) = arg1[6];
    int32_t ebx = arg1[3];
    *(esp_14 - 0xc) = ebx;
    int32_t edx = __FrameHandler3::GetCurrentState();
    arg1[-8] = edx;
    int32_t esi = *(edi + 0x10);
    int32_t ecx = 0;
    arg1[-0xa] = 0;
    int32_t edi_1 = *(edi + 0xc);

    if (edi_1)
    {
        do
        {
            if (edx > *(esi + ecx * 0x14 + 4) && edx <= *(esi + ecx * 0x14 + 8))
            {
                int32_t eax_7 = *(esi + ecx * 0x14 + 4) + 1;
                arg1[-8] = eax_7;
                edx = *(arg1[-9] + (eax_7 << 3));
                arg1[-8] = edx;
                break;
            }

            ecx += 1;
            arg1[-0xa] = ecx;
        } while (ecx < edi_1);
    }

    *(esp_14 - 4) = edx;
    *(esp_14 - 8) = arg1[5];
    *(esp_14 - 0xc) = 0;
    *(esp_14 - 0x10) = ebx;
    sub_405710();
    arg1[-7] = 0;
    arg1[-1] = 0;
    int32_t* esi_1 = arg1[2];
    arg1[-1] = 0xfffffffe;
    arg1[-0x10] = 0;
    sub_4055ba(arg1, esi_1, 0);
    TEB* fsbase;
    fsbase->NtTib.ExceptionList = arg1[-4];
    *esp_14;
    *(esp_14 + 4);
    *(esp_14 + 8);
    *(esp_14 + 0xc);
    *arg1;
    return 0;
}

int32_t* sub_4055ba(void* arg1 @ ebp, int32_t* arg2 @ esi, int32_t arg3 @ edi)
{
    void* entry_ebx;
    *(entry_ebx - 4) = *(arg1 - 0x2c);
    sub_404820(*(arg1 - 0x30));
    void* eax = sub_404310();
    *(eax + 0x10) = *(arg1 - 0x34);
    int32_t* result = sub_404310();
    result[5] = *(arg1 - 0x38);

    if (*arg2 == 0xe06d7363 && arg2[4] == 3
        && (arg2[5] == 0x19930520 || arg2[5] == 0x19930521 || arg2[5] == 0x19930522)
        && !*(arg1 - 0x3c) && arg3)
    {
        result = sub_404050(arg2[6]);

        if (result)
        {
            uint32_t var_4_2 = *(arg1 - 0x40);
            return sub_403ed0(arg2);
        }
    }

    return result;
}

void sub_405640() __noreturn
{
    int32_t ebp;
    int32_t var_4 = ebp;
    int32_t var_8 = 0xffffffff;
    int32_t (* var_c)(void* arg1 @ 0x8) = sub_415650;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t var_24 = __security_cookie ^ &var_4;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t* var_14 = &var_24;

    if (*(sub_404310() + 0x1c))
    {
        sub_4096af();
        /* no return */
    }

    int32_t var_8_1 = 0;
    _unexpected();
    /* no return */
}

int32_t sub_4056a0(int32_t* arg1)
{
    int32_t* eax_1 = *arg1;

    if (*eax_1 == 0xe06d7363 && eax_1[4] == 3)
    {
        int32_t ecx_1 = eax_1[5];

        if ((ecx_1 == 0x19930520 || ecx_1 == 0x19930521 || ecx_1 == 0x19930522) && !eax_1[7])
        {
            *(sub_404310() + 0x20) = 1;
            return 1;
        }
    }

    return 0;
}

void* __FrameHandler3::FrameUnwindToEmptyState(void* arg1, int32_t arg2, void* arg3)
{
    return sub_405710(arg1, arg2, arg3, 0xffffffff);
}

void* sub_405710(void* arg1, int32_t arg2, void* arg3, int32_t arg4)
{
    int32_t var_8 = 0xfffffffe;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_c_1 = 0x41c9f8 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_38 = __security_cookie_1 ^ &__saved_ebp;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t* var_1c = &var_38;
    void* edi = arg3;
    int32_t var_40 = arg2;
    int32_t esi = __FrameHandler3::GetCurrentState(arg1, edi);
    int32_t var_20 = esi;
    void* eax_3 = sub_404310();
    *(eax_3 + 0x18) += 1;
    int32_t var_8_1 = 0;

    while (true)
    {
        if (esi == arg4)
        {
            int32_t var_8_4 = 0xfffffffe;
            sub_40583c();

            if (esi != arg4)
                break;

            void* var_40_3 = edi;
            int32_t var_44_3 = arg2;
            void* result = sub_4059e0(arg1, esi);
            fsbase->NtTib.ExceptionList = ExceptionList;
            return result;
        }

        if (esi <= 0xffffffff)
            break;

        if (esi >= *(edi + 4))
            break;

        int32_t* ecx_1 = esi << 3;
        int32_t* eax_4 = *(edi + 8);
        esi = *(eax_4 + ecx_1);
        int32_t var_28_1 = esi;
        int32_t var_8_2 = 1;

        if (*(eax_4 + ecx_1 + 4))
        {
            void* var_40_1 = edi;
            int32_t var_44_1 = arg2;
            sub_4059e0(arg1, esi);
            esi = __CallSettingFrame@12(ecx_1, *(*(edi + 8) + ecx_1 + 4), arg1, 0x103);
        }

        int32_t var_8_3 = 0;
        int32_t var_20_1 = esi;
    }

    sub_4096af();
    /* no return */
}

int32_t sub_4057db(void* arg1 @ ebp)
{
    sub_4040b0(*(arg1 - 0x14));
    return 0;
}

void* sub_40583c()
{
    void* result = sub_404310();

    if (*(result + 0x18) > 0)
    {
        result = sub_404310();
        *(result + 0x18) -= 1;
    }

    return result;
}

int32_t sub_405860(void* arg1, int32_t* arg2)
{
    if (!arg2)
    {
        sub_4096af();
        /* no return */
    }

    int32_t result = *arg2;
    int32_t ecx = 0;
    char ebx = 0;
    int32_t result_1 = result;
    char var_5 = 0;
    int32_t var_14 = 0;

    if (result > 0)
    {
        int32_t* edx_1 = *(arg1 + 0x1c);
        int32_t* var_c_1 = edx_1;
        int32_t* eax_2 = edx_1[3];
        int32_t esi_1 = *eax_2;
        int32_t* edi_1 = &eax_2[1];
        result = result_1;
        int32_t var_18_1 = esi_1;
        int32_t* var_1c_1 = edi_1;

        do
        {
            if (esi_1 > 0)
            {
                int32_t* ebx_3 = (ecx << 4) + arg2[1];

                while (true)
                {
                    int32_t eax_4 = sub_4051b0(ebx_3, *edi_1, edx_1);
                    edx_1 = var_c_1;

                    if (eax_4)
                    {
                        ebx = 1;
                        var_5 = 1;
                        break;
                    }

                    esi_1 -= 1;
                    edi_1 = &edi_1[1];

                    if (esi_1 <= 0)
                    {
                        ebx = var_5;
                        break;
                    }
                }

                result = result_1;
                ecx = var_14;
            }

            esi_1 = var_18_1;
            ecx += 1;
            edi_1 = var_1c_1;
            var_14 = ecx;
        } while (ecx < result);
    }

    result = ebx;
    return result;
}

int32_t __stdcall sub_405900(int32_t arg1, int32_t arg2, int32_t arg3)
{
    return arg2(arg3);
}

int32_t __stdcall sub_405910(int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4)
{
    return arg2(arg3, arg4);
}

int32_t sub_405930(void* arg1)
{
    return *(arg1 + 0x1c);
}

char const* const __fastcall sub_405940(void* arg1)
{
    char* result = *(arg1 + 4);

    if (result)
        return result;

    return "Unknown exception";
}

int32_t __thiscall __CallSettingFrame@12(int32_t* arg1, int32_t arg2, int32_t arg3, int32_t arg4)
{
    int32_t ebp;
    int32_t var_4 = ebp;
    int32_t ebx;
    int32_t var_c = ebx;
    int32_t* var_14 = &var_4;
    int32_t var_18 = arg4;
    int32_t edx;
    sub_4044c0(arg2, edx, arg4, arg3 + 0xc);
    int32_t esi;
    int32_t var_18_1 = esi;
    int32_t edi;
    int32_t var_1c = edi;
    int32_t result;
    int32_t edx_1;
    result = arg2();
    int32_t ecx_1 = arg1[4];

    if (ecx_1 == 0x100)
        ecx_1 = 2;

    int32_t var_14_1 = ecx_1;
    sub_4044c0(result, edx_1, ecx_1, arg3 + 0xc);
    *arg1;
    return result;
}

void _unexpected() __noreturn
{
    int32_t esi = *(sub_404310() + 4);

    if (esi)
        esi();

    _terminate();
    /* no return */
}

int32_t __FrameHandler3::GetCurrentState(void* arg1, void* arg2 @ 0xc)
{
    if (*(arg2 + 4) > 0x80)
        return *(arg1 + 8);

    return *(arg1 + 8);
}

void* sub_4059e0(void* arg1, int32_t arg2 @ 0x10)
{
    *(arg1 + 8) = arg2;
    return arg1;
}

char* sub_4059f0(int32_t* arg1, char** arg2)
{
    if (arg1[1])
    {
        char* ecx_1 = *arg1;

        if (ecx_1)
        {
            void* edx = &ecx_1[1];
            char i;

            do
            {
                i = *ecx_1;
                ecx_1 = &ecx_1[1];
            } while (i);
            void* var_14 = ecx_1 - edx + 1;
            char* esi = sub_409610();

            if (esi)
            {
                sub_409620(esi, ecx_1 - edx + 1, *arg1);
                char* ecx_3 = esi;
                esi = nullptr;
                *arg2 = ecx_3;
                arg2[1] = 1;
            }

            return j___free_base(esi);
        }
    }

    char* result = *arg1;
    *arg2 = result;
    arg2[1] = 0;
    return result;
}

void sub_405a60(int32_t* arg1)
{
    if (arg1[1])
        j___free_base(*arg1);

    *arg1 = 0;
    arg1[1] = 0;
}

void sub_405a90(int32_t* arg1, char* arg2) __noreturn
{
    char* edi = arg2;
    uint32_t arguments_1 = 0x19930520;

    if (edi)
    {
        if (!(*edi & 0x10))
        {
        label_405ad1:
            arguments_1 = 0x1994000;

            if (!(*edi & 8))
                arguments_1 = 0x19930520;
        }
        else
        {
            void* ecx_1 = *arg1;
            void* eax_1 = *(ecx_1 - 4);
            edi = *(eax_1 + 0x18);
            (*(eax_1 + 0x20))(ecx_1 - 4);

            if (edi)
                goto label_405ad1;
        }
    }

    int32_t* var_c = arg1;
    uint32_t arguments = arguments_1;
    char* var_8 = edi;
    RaiseException(0xe06d7363, 1, 3, &arguments);
    /* no return */
}

void* _strlen(char* arg1)
{
    char* ecx = arg1;

    while (ecx & 3)
    {
        int32_t eax;
        eax = *ecx;
        ecx = &ecx[1];

        if (!eax)
            return &ecx[0xffffffff] - arg1;
    }

    while (true)
    {
        int32_t eax_2 = *ecx;
        ecx = &ecx[4];

        if ((eax_2 ^ 0xffffffff ^ (0x7efefeff + eax_2)) & 0x81010100)
        {
            int32_t eax_5 = *(ecx - 4);

            if (!eax_5)
                return &ecx[0xfffffffc] - arg1;

            if (!*(&eax_5 + 1))
                return &ecx[0xfffffffd] - arg1;

            if (!(eax_5 & 0xff0000))
                return &ecx[0xfffffffe] - arg1;

            if (!(eax_5 & 0xff000000))
                break;
        }
    }

    return &ecx[0xffffffff] - arg1;
}

int32_t _rand()
{
    int32_t* eax_1 = sub_409b74();
    int32_t ecx_1 = eax_1[6] * 0x343fd + 0x269ec3;
    eax_1[6] = ecx_1;
    return ecx_1 >> 0x10 & 0x7fff;
}

int32_t* sub_405bbc(int32_t arg1)
{
    int32_t* result = sub_409b74();
    result[6] = arg1;
    return result;
}

int32_t sub_405bd0(int32_t arg1 @ mxcsr, int16_t arg2 @ x87control)
{
    if (!data_41f148)
        /* tailcall */
        return sub_409d4f();

    int32_t eax_2 = arg1 & 0x7f80;
    bool cond:0 = eax_2 != 0x1f80;

    if (eax_2 == 0x1f80)
    {
        int16_t x87status_2;
        int16_t temp0_1;
        temp0_1 = __fnstcw_memmem16(arg2);
        cond:0 = (temp0_1 & 0x7f) != 0x7f;
    }

    if (cond:0)
        /* tailcall */
        return sub_409d4f();

    /* tailcall */
    return sub_409e08();
}

long double sub_405c20(int64_t arg1)
{
    return __andps_xmmxud_memxud(arg1, data_416ce0);
}

int32_t sub_405c40(int32_t arg1 @ mxcsr, int16_t arg2 @ x87control)
{
    if (!data_41f148)
        /* tailcall */
        return sub_409fef();

    int32_t eax_2 = arg1 & 0x7f80;
    bool cond:0 = eax_2 != 0x1f80;

    if (eax_2 == 0x1f80)
    {
        int16_t x87status_2;
        int16_t temp0_1;
        temp0_1 = __fnstcw_memmem16(arg2);
        cond:0 = (temp0_1 & 0x7f) != 0x7f;
    }

    if (cond:0)
        /* tailcall */
        return sub_409fef();

    /* tailcall */
    return sub_40a0a8();
}

int80_t sub_405c90() __location("st0")
{
    void arg_4;
    int32_t ecx;
    int16_t x87control;
    /* tailcall */
    return sub_40a404(x87control, __fload_withFB(ecx, &arg_4));
}

int32_t* sub_405c9e(int32_t arg1, int32_t arg2, int32_t* arg3, int32_t arg4, int32_t arg5, int32_t* arg6, int32_t arg7)
{
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    int32_t* result_2 = arg3;
    int32_t* result;

    if (arg5 && (!arg4 || arg3))
    {
        int32_t edi;
        int32_t var_484_1 = edi;
        char* result_5 = nullptr;
        int32_t var_470;
        int32_t* edi_1 = &var_470;
        *edi_1 = 0;
        int32_t* edi_2 = &edi_1[1];
        *edi_2 = 0;
        edi_2[1] = 0;
        char* result_4 = result_2;
        int32_t eax_4 = arg1 & 2;
        int32_t var_478 = eax_4;
        result_5 = result_4;
        var_470 = arg4;
        int32_t var_46c_1 = 0;

        if (!eax_4)
            char var_468_1 = 0;

        if (eax_4 || !result_4)
            char var_468_2 = 1;

        result_2 = &result_5;
        void var_460;
        sub_4068d0(&var_460, &result_2, arg1, arg2, arg5, arg6, arg7);
        int32_t var_10_1 = 0;
        int32_t* result_3 = __crt_stdio_output::output_processor<char,class __crt_stdio_output::string_output_adapter<char>,class __crt_stdio_output::standard_base<char,class __crt_stdio_output::string_output_adapter<char> > >::process(
            &var_460);
        result_2 = result_3;
        int32_t* result_1;

        if (!result_4)
            result_1 = result_2;
        else if (!(arg1 & 1))
        {
            if (!var_478)
            {
                if (arg4)
                {
                    if (var_46c_1 != arg4)
                    {
                        result_4[var_46c_1] = 0;
                        result_1 = result_2;
                    }
                    else
                    {
                        result_4[arg4 - 1] = 0;
                        result_1 = 0xfffffffe;
                    }
                }
                else
                    result_1 = 0xffffffff;
            }
            else if (!arg4)
                result_1 = result_2;
            else if (result_3 >= 0)
            {
                if (var_46c_1 != arg4)
                {
                    result_4[var_46c_1] = 0;
                    result_1 = result_2;
                }
                else
                {
                    result_4[arg4 - 1] = 0;
                    result_1 = result_2;
                }
            }
            else
            {
                *result_4 = 0;
                result_1 = result_2;
            }
        }
        else if (!arg4 && result_3)
            result_1 = 0xffffffff;
        else if (var_46c_1 != arg4)
        {
            result_4[var_46c_1] = 0;
            result_1 = result_2;
        }
        else if (result_3 < 0 || result_3 <= arg4)
            result_1 = result_2;
        else
            result_1 = 0xffffffff;

        void var_424;
        __crt_stdio_output::formatting_buffer::~formatting_buffer(&var_424);
        result = result_1;
    }
    else
    {
        arg6[7] = 1;
        arg6[6] = 0x16;
        __invalid_parameter_internal(0, 0, 0, 0, 0, arg6);
        result = 0xffffffff;
    }

    sub_402910(eax_1 ^ &__saved_ebp);
    return result;
}

uint32_t __fastcall __crt_stdio_output::formatting_buffer::count<char>(void* arg1)
{
    if (*(arg1 + 0x404))
        return *(arg1 + 0x400) >> 1;

    return 0x200;
}

void* __thiscall sub_405e2a(void* arg1, int32_t arg2, void* arg3)
{
    void* var_8 = arg1;
    int32_t edi;
    int32_t var_10 = edi;
    void* result;

    if (arg2 <= 0x7fffffff)
    {
        char ebx_1 = 0;
        uint32_t esi_1 = arg2 * 2;

        if (*(arg1 + 0x404))
        {
            if (esi_1 > *(arg1 + 0x400))
                goto label_405e73;

            result = 1;
        }
        else if (esi_1 <= 0x400 || esi_1 <= *(arg1 + 0x400))
            result = 1;
        else
        {
        label_405e73:
            void* eax = sub_40a8b0(esi_1);
            var_8 = eax;

            if (eax)
            {
                sub_4069f6(arg1 + 0x404, &var_8);
                eax = var_8;
                ebx_1 = 1;
                *(arg1 + 0x400) = esi_1;
            }

            result = __free_base(eax);
            result = ebx_1;
        }
    }
    else
    {
        result = arg3;
        *(result + 0x1c) = 1;
        *(result + 0x18) = 0xc;
        result = 0;
    }

    return result;
}

int32_t __crt_strtox::is_overflow_condition<unsigned long>(char arg1, int32_t arg2) __pure
{
    int32_t result;

    if (!(arg1 & 4))
    {
        if (!(arg1 & 1))
        {
            result = 0;
            return result;
        }

        if (!(arg1 & 2))
        {
            result = arg2 > 0x7fffffff;
            return result;
        }

        if (arg2 <= 0x80000000)
        {
            result = 0;
            return result;
        }
    }

    result = 1;
    return result;
}

int32_t __crt_stdio_output::is_wide_character_specifier<char>(char arg1 @ 0xc, int32_t arg2) __pure
{
    int32_t result = arg2 - 2;

    if (arg2 != 2)
    {
        int32_t result_1 = result;
        result -= 1;

        if (result_1 == 1)
        {
            result = 1;
            return result;
        }

        int32_t result_2 = result;
        result -= 9;

        if (result_2 == 9)
        {
            result = 1;
            return result;
        }

        if (arg2 != 0xd)
        {
            result = arg1;

            if (result != 0x63 && result != 0x73)
            {
                result = 1;
                return result;
            }
        }
    }

    result = 0;
    return result;
}

int32_t sub_405f0f(int32_t* arg1, int32_t* arg2 @ 0xc, int32_t arg3, char arg4)
{
    int32_t esi = arg3;
    char* arg_8;

    if (!sub_40797b(&arg_8))
        goto label_405f57;

    if (!esi || (esi >= 2 && esi <= 0x24))
    {
        char* eax_3 = arg_8;
        int32_t result_1 = 0;
        int32_t edi;
        int32_t var_24_2 = edi;
        char ebx_1 = *eax_3;
        char* edi_1 = &eax_3[1];
        uint32_t eax_4 = arg4;
        char var_8_1 = ebx_1;
        uint32_t ecx_3 = eax_4 | 2;
        arg_8 = edi_1;

        if (ebx_1 != 0x2d)
            ecx_3 = eax_4;

        if (ebx_1 == 0x2d || ebx_1 == 0x2b)
        {
            ebx_1 = *edi_1;
            edi_1 = &edi_1[1];
            var_8_1 = ebx_1;
            arg_8 = edi_1;
        }

        int32_t ecx_4 = 0x10;

        if (!esi || esi == 0x10)
        {
            int32_t var_28_2;
            int32_t eax_7;

            if (ebx_1 - 0x30 > 9)
            {
                if (ebx_1 - 0x61 <= 0x19)
                {
                    eax_7 = ebx_1 - 0x57;
                    goto label_405fda;
                }

                if (ebx_1 - 0x41 <= 0x19)
                {
                    eax_7 = ebx_1 - 0x37;
                    goto label_405fda;
                }

            label_406012:
                var_28_2 = 0xa;
            label_406016:
                int32_t eax_12 = var_28_2;

                if (esi)
                    eax_12 = esi;

                esi = eax_12;
            }
            else
            {
                eax_7 = ebx_1 - 0x30;
            label_405fda:

                if (eax_7)
                    goto label_406012;

                char eax_10 = *edi_1;
                arg_8 = &edi_1[1];

                if (eax_10 != 0x78 && eax_10 != 0x58)
                {
                    __crt_strtox::c_string_character_source<char>::unget(&arg_8, eax_10);
                    var_28_2 = 8;
                    goto label_406016;
                }

                ebx_1 = edi_1[1];
                var_8_1 = ebx_1;
                arg_8 = &edi_1[2];

                if (esi)
                    ecx_4 = esi;

                esi = ecx_4;
            }
        }

        uint32_t edi_3 = ecx_3;

        while (true)
        {
            int32_t ecx_7;

            if (ebx_1 - 0x30 <= 9)
                ecx_7 = ebx_1 - 0x30;
            else if (ebx_1 - 0x61 <= 0x19)
                ecx_7 = ebx_1 - 0x57;
            else if (ebx_1 - 0x41 > 0x19)
                ecx_7 = 0xffffffff;
            else
                ecx_7 = ebx_1 - 0x37;

            if (ecx_7 >= esi)
                break;

            int32_t result_3 = result_1;
            int32_t eax_17 = result_3 * esi;
            int32_t result_2 = eax_17 + ecx_7;
            result_1 = result_2;
            edi_3 |= (-((ecx_7 - ecx_7)) | -((eax_17 - eax_17))) << 2 | 8;
            char* ecx_15 = arg_8;
            ebx_1 = *ecx_15;
            var_8_1 = ebx_1;
            arg_8 = &ecx_15[1];
        }

        uint32_t var_c_2 = edi_3;
        __crt_strtox::c_string_character_source<char>::unget(&arg_8, var_8_1);
        char ebx_2 = edi_3;

        if (ebx_2 & 8)
        {
            int32_t result = result_1;

            if (__crt_strtox::is_overflow_condition<unsigned long>(ebx_2, result))
            {
                arg1[7] = 1;
                arg1[6] = 0x22;

                if (ebx_2 & 1)
                {
                    if (!(ebx_2 & 2))
                    {
                        if (arg2)
                            *arg2 = arg_8;

                        return 0x7fffffff;
                    }

                    if (arg2)
                        *arg2 = arg_8;

                    return 0x80000000;
                }

                result = 0xffffffff;
            }
            else if (ebx_2 & 2)
                result = -(result);

            if (arg2)
                *arg2 = arg_8;

            return result;
        }

        if (arg2)
            *arg2 = eax_3;
    }
    else
    {
        arg1[7] = 1;
        arg1[6] = 0x16;
        __invalid_parameter_internal(0, 0, 0, 0, 0, arg1);
    label_405f57:

        if (arg2)
            *arg2 = arg_8;
    }

    return 0;
}

void* __fastcall __crt_stdio_output::formatting_buffer::scratch_data<char>(void* arg1)
{
    int32_t edi;
    int32_t var_8 = edi;
    int32_t edi_1 = *(arg1 + 0x404);
    uint32_t eax = __crt_stdio_output::formatting_buffer::count<char>(arg1);

    if (edi_1)
        return eax + edi_1;

    return eax + arg1;
}

uint32_t __thiscall sub_406140(void* arg1, int32_t arg2)
{
    int32_t edi;
    int32_t var_1c = edi;
    int32_t eax = __crt_stdio_output::to_integer_size(*(arg1 + 0x28));
    int32_t eax_8;
    int32_t edi_1;

    if (eax == 1)
    {
        edi_1 = *(arg1 + 0x1c);
        char* ecx_10 = *(arg1 + 0x10);
        *(arg1 + 0x10) = &ecx_10[4];

        if (!(edi_1 >> 4 & 1))
            eax_8 = *ecx_10;
        else
            eax_8 = *ecx_10;

        goto label_40621d;
    }

    if (eax == 2)
    {
        edi_1 = *(arg1 + 0x1c);
        int16_t* ecx_9 = *(arg1 + 0x10);
        *(arg1 + 0x10) = &ecx_9[2];

        if (!(edi_1 >> 4 & 1))
            eax_8 = *ecx_9;
        else
            eax_8 = *ecx_9;

        goto label_40621d;
    }

    uint32_t result;
    int32_t eax_4;
    uint32_t edx_1;

    if (eax == 4)
    {
        edi_1 = *(arg1 + 0x1c);
        uint32_t var_c_1;

        if (!(edi_1 >> 4 & 1))
        {
            int32_t* ecx_8 = *(arg1 + 0x10);
            var_c_1 = 0;
            *(arg1 + 0x10) = &ecx_8[1];
            eax_4 = *ecx_8;
        }
        else
        {
            int32_t* eax_7 = *(arg1 + 0x10);
            *(arg1 + 0x10) = &eax_7[1];
            eax_8 = *eax_7;
        label_40621d:
            edx_1 = HIGHD(eax_8);
            eax_4 = LOWD(eax_8);
        label_40621e:
            var_c_1 = edx_1;
        }

        uint32_t edx_3 = var_c_1;
        int32_t ecx_11 = eax_4;

        if (edi_1 >> 4 & 1 && edx_3 <= 0 && (edx_3 < 0 || ecx_11 < 0))
        {
            int32_t temp5_1 = ecx_11;
            ecx_11 = -(ecx_11);
            edx_3 = -((edx_3 + 0));
            edi_1 |= 0x40;
            *(arg1 + 0x1c) = edi_1;
        }

        if (*(arg1 + 0x24) >= 0)
        {
            void* var_20_2 = *(arg1 + 8);
            int32_t var_24_1 = *(arg1 + 0x24);
            *(arg1 + 0x1c) = edi_1 & 0xfffffff7;
            sub_405e2a(arg1 + 0x3c, var_24_1, var_20_2);
        }
        else
            *(arg1 + 0x24) = 1;

        if (!(ecx_11 | edx_3))
            *(arg1 + 0x1c) &= 0xffffffdf;

        int32_t var_20_3 = arg2;
        *(arg1 + 0x38) = 0;

        if (eax != 8)
            sub_4065e7(arg1, ecx_11);
        else
            sub_406744(arg1, ecx_11, edx_3);

        result = *(arg1 + 0x1c) >> 7;

        if (result & 1)
        {
            if (*(arg1 + 0x34))
                result = *(arg1 + 0x30);

            if (!*(arg1 + 0x34) || *result != 0x30)
            {
                *(arg1 + 0x30) -= 1;
                **(arg1 + 0x30) = 0x30;
                *(arg1 + 0x34) += 1;
            }
        }

        result = 1;
    }
    else
    {
        if (eax == 8)
        {
            int32_t* ecx_6 = *(arg1 + 0x10);
            edi_1 = *(arg1 + 0x1c);
            *(arg1 + 0x10) = &ecx_6[2];
            eax_4 = *ecx_6;
            edx_1 = ecx_6[1];
            goto label_40621e;
        }

        int32_t* eax_2 = *(arg1 + 8) + 0x18;
        eax_2[1] = 1;
        *eax_2 = 0x16;
        result = __invalid_parameter_internal(0, 0, 0, 0, 0, *(arg1 + 8));
        result = 0;
    }
    return result;
}

uint32_t __thiscall sub_4062cd(void* arg1, char arg2)
{
    int32_t edi;
    int32_t var_1c = edi;
    int32_t eax = __crt_stdio_output::to_integer_size(*(arg1 + 0x28));
    int32_t eax_8;
    int32_t edi_1;

    if (eax == 1)
    {
        edi_1 = *(arg1 + 0x1c);
        char* ecx_10 = *(arg1 + 0x10);
        *(arg1 + 0x10) = &ecx_10[4];

        if (!(edi_1 >> 4 & 1))
            eax_8 = *ecx_10;
        else
            eax_8 = *ecx_10;

        goto label_4063aa;
    }

    if (eax == 2)
    {
        edi_1 = *(arg1 + 0x1c);
        int16_t* ecx_9 = *(arg1 + 0x10);
        *(arg1 + 0x10) = &ecx_9[2];

        if (!(edi_1 >> 4 & 1))
            eax_8 = *ecx_9;
        else
            eax_8 = *ecx_9;

        goto label_4063aa;
    }

    uint32_t result;
    uint32_t eax_4;
    uint32_t edx_1;

    if (eax == 4)
    {
        edi_1 = *(arg1 + 0x1c);
        uint32_t var_c_1;

        if (!(edi_1 >> 4 & 1))
        {
            uint32_t* ecx_8 = *(arg1 + 0x10);
            var_c_1 = 0;
            *(arg1 + 0x10) = &ecx_8[1];
            eax_4 = *ecx_8;
        }
        else
        {
            int32_t* eax_7 = *(arg1 + 0x10);
            *(arg1 + 0x10) = &eax_7[1];
            eax_8 = *eax_7;
        label_4063aa:
            edx_1 = HIGHD(eax_8);
            eax_4 = LOWD(eax_8);
        label_4063ab:
            var_c_1 = edx_1;
        }

        uint32_t edx_3 = var_c_1;
        uint32_t ecx_11 = eax_4;

        if (edi_1 >> 4 & 1 && edx_3 <= 0 && (edx_3 < 0 || ecx_11 < 0))
        {
            uint32_t temp5_1 = ecx_11;
            ecx_11 = -(ecx_11);
            edx_3 = -((edx_3 + 0));
            edi_1 |= 0x40;
            *(arg1 + 0x1c) = edi_1;
        }

        if (*(arg1 + 0x24) >= 0)
        {
            void* var_20_2 = *(arg1 + 8);
            int32_t var_24_1 = *(arg1 + 0x24);
            *(arg1 + 0x1c) = edi_1 & 0xfffffff7;
            sub_405e2a(arg1 + 0x3c, var_24_1, var_20_2);
        }
        else
            *(arg1 + 0x24) = 1;

        if (!(ecx_11 | edx_3))
            *(arg1 + 0x1c) &= 0xffffffdf;

        *(arg1 + 0x38) = 0;

        if (eax != 8)
            sub_406649(arg1, ecx_11, arg2);
        else
            sub_4067b8(arg1, ecx_11, edx_3, arg2);

        result = *(arg1 + 0x1c) >> 7;

        if (result & 1)
        {
            if (*(arg1 + 0x34))
                result = *(arg1 + 0x30);

            if (!*(arg1 + 0x34) || *result != 0x30)
            {
                *(arg1 + 0x30) -= 1;
                **(arg1 + 0x30) = 0x30;
                *(arg1 + 0x34) += 1;
            }
        }

        result = 1;
    }
    else
    {
        if (eax == 8)
        {
            uint32_t* ecx_6 = *(arg1 + 0x10);
            edi_1 = *(arg1 + 0x1c);
            *(arg1 + 0x10) = &ecx_6[2];
            eax_4 = *ecx_6;
            edx_1 = ecx_6[1];
            goto label_4063ab;
        }

        int32_t* eax_2 = *(arg1 + 8) + 0x18;
        eax_2[1] = 1;
        *eax_2 = 0x16;
        result = __invalid_parameter_internal(0, 0, 0, 0, 0, *(arg1 + 8));
        result = 0;
    }
    return result;
}

uint32_t __thiscall sub_40645a(void* arg1, char arg2)
{
    int32_t edi;
    int32_t var_1c = edi;
    int32_t eax = __crt_stdio_output::to_integer_size(*(arg1 + 0x28));
    int32_t eax_8;
    int32_t edi_1;

    if (eax == 1)
    {
        edi_1 = *(arg1 + 0x1c);
        char* ecx_10 = *(arg1 + 0x10);
        *(arg1 + 0x10) = &ecx_10[4];

        if (!(edi_1 >> 4 & 1))
            eax_8 = *ecx_10;
        else
            eax_8 = *ecx_10;

        goto label_406537;
    }

    if (eax == 2)
    {
        edi_1 = *(arg1 + 0x1c);
        int16_t* ecx_9 = *(arg1 + 0x10);
        *(arg1 + 0x10) = &ecx_9[2];

        if (!(edi_1 >> 4 & 1))
            eax_8 = *ecx_9;
        else
            eax_8 = *ecx_9;

        goto label_406537;
    }

    uint32_t result;
    uint32_t eax_4;
    uint32_t edx_1;

    if (eax == 4)
    {
        edi_1 = *(arg1 + 0x1c);
        uint32_t var_c_1;

        if (!(edi_1 >> 4 & 1))
        {
            uint32_t* ecx_8 = *(arg1 + 0x10);
            var_c_1 = 0;
            *(arg1 + 0x10) = &ecx_8[1];
            eax_4 = *ecx_8;
        }
        else
        {
            int32_t* eax_7 = *(arg1 + 0x10);
            *(arg1 + 0x10) = &eax_7[1];
            eax_8 = *eax_7;
        label_406537:
            edx_1 = HIGHD(eax_8);
            eax_4 = LOWD(eax_8);
        label_406538:
            var_c_1 = edx_1;
        }

        uint32_t edx_3 = var_c_1;
        uint32_t ecx_11 = eax_4;

        if (edi_1 >> 4 & 1 && edx_3 <= 0 && (edx_3 < 0 || ecx_11 < 0))
        {
            uint32_t temp5_1 = ecx_11;
            ecx_11 = -(ecx_11);
            edx_3 = -((edx_3 + 0));
            edi_1 |= 0x40;
            *(arg1 + 0x1c) = edi_1;
        }

        if (*(arg1 + 0x24) >= 0)
        {
            void* var_20_2 = *(arg1 + 8);
            int32_t var_24_1 = *(arg1 + 0x24);
            *(arg1 + 0x1c) = edi_1 & 0xfffffff7;
            sub_405e2a(arg1 + 0x3c, var_24_1, var_20_2);
        }
        else
            *(arg1 + 0x24) = 1;

        if (!(ecx_11 | edx_3))
            *(arg1 + 0x1c) &= 0xffffffdf;

        *(arg1 + 0x38) = 0;

        if (eax != 8)
            sub_4066c8(arg1, ecx_11, arg2);
        else
            sub_40684a(arg1, ecx_11, edx_3, arg2);

        result = *(arg1 + 0x1c) >> 7;

        if (result & 1)
        {
            if (*(arg1 + 0x34))
                result = *(arg1 + 0x30);

            if (!*(arg1 + 0x34) || *result != 0x30)
            {
                *(arg1 + 0x30) -= 1;
                **(arg1 + 0x30) = 0x30;
                *(arg1 + 0x34) += 1;
            }
        }

        result = 1;
    }
    else
    {
        if (eax == 8)
        {
            uint32_t* ecx_6 = *(arg1 + 0x10);
            edi_1 = *(arg1 + 0x1c);
            *(arg1 + 0x10) = &ecx_6[2];
            eax_4 = *ecx_6;
            edx_1 = ecx_6[1];
            goto label_406538;
        }

        int32_t* eax_2 = *(arg1 + 8) + 0x18;
        eax_2[1] = 1;
        *eax_2 = 0x16;
        result = __invalid_parameter_internal(0, 0, 0, 0, 0, *(arg1 + 8));
        result = 0;
    }
    return result;
}

void* __thiscall sub_4065e7(void* arg1, uint32_t arg2)
{
    int32_t edi;
    int32_t var_10 = edi;
    void* esi = *(arg1 + 0x440);

    if (!esi)
        esi = arg1 + 0x3c;

    uint32_t edx = arg2;
    char* ecx_2 = __crt_stdio_output::formatting_buffer::count<char>(arg1 + 0x3c) - 1 + esi;
    *(arg1 + 0x30) = ecx_2;
    char* eax_1 = ecx_2;
    char* ebx = ecx_2;

    while (true)
    {
        int32_t esi_1 = *(arg1 + 0x24);

        if (esi_1 <= 0 && !edx)
        {
            *(arg1 + 0x34) = ecx_2 - eax_1;
            *(arg1 + 0x30) = &eax_1[1];
            return &eax_1[1];
        }

        *(arg1 + 0x24) = esi_1 - 1;
        char eax_3 = edx & 7;
        edx u>>= 3;
        *ebx = eax_3 + 0x30;
        *(arg1 + 0x30) -= 1;
        eax_1 = *(arg1 + 0x30);
        ebx = eax_1;
    }
}

void* __thiscall sub_406649(void* arg1, uint32_t arg2, char arg3)
{
    void* var_8 = arg1;
    int32_t edi;
    int32_t var_14 = edi;
    void* esi = *(arg1 + 0x440);

    if (!esi)
        esi = arg1 + 0x3c;

    char* esi_2 = esi - 1 + __crt_stdio_output::formatting_buffer::count<char>(arg1 + 0x3c);
    char* eax_1 = esi_2;
    *(arg1 + 0x30) = esi_2;
    char* ebx = esi_2;
    uint32_t esi_3 = arg2;

    while (true)
    {
        int32_t ecx_1 = *(arg1 + 0x24);

        if (ecx_1 <= 0 && !esi_3)
        {
            *(arg1 + 0x34) = esi_2 - eax_1;
            *(arg1 + 0x30) = &eax_1[1];
            return &eax_1[1];
        }

        int32_t edx_1 = 0;
        *(arg1 + 0x24) = ecx_1 - 1;
        uint8_t edx_3 = COMBINE(edx_1, esi_3) % 0xa + 0x30;
        esi_3 = COMBINE(edx_1, esi_3) / 0xa;

        if (edx_3 > 0x39)
            edx_3 += ((arg3 ^ 1) << 5) + 7;

        *ebx = edx_3;
        *(arg1 + 0x30) -= 1;
        eax_1 = *(arg1 + 0x30);
        ebx = eax_1;
    }
}

void* __thiscall sub_4066c8(void* arg1, uint32_t arg2, char arg3)
{
    void* var_8 = arg1;
    int32_t edi;
    int32_t var_14 = edi;
    void* esi = *(arg1 + 0x440);

    if (!esi)
        esi = arg1 + 0x3c;

    int32_t ebx;
    *(&ebx + 1) = arg3;
    uint32_t edx = arg2;
    char* ecx_2 = esi - 1 + __crt_stdio_output::formatting_buffer::count<char>(arg1 + 0x3c);
    *(arg1 + 0x30) = ecx_2;
    char* eax_1 = ecx_2;
    char* var_8_1 = ecx_2;

    while (true)
    {
        int32_t esi_1 = *(arg1 + 0x24);

        if (esi_1 <= 0 && !edx)
        {
            *(arg1 + 0x34) = ecx_2 - eax_1;
            *(arg1 + 0x30) = &eax_1[1];
            return &eax_1[1];
        }

        *(arg1 + 0x24) = esi_1 - 1;
        char eax_3 = edx & 0xf;
        edx u>>= 4;
        eax_3 += 0x30;
        ebx = eax_3;

        if (eax_3 > 0x39)
            eax_3 = ((*(&ebx + 1) ^ 1) << 5) + 7 + ebx;

        *var_8_1 = eax_3;
        *(arg1 + 0x30) -= 1;
        eax_1 = *(arg1 + 0x30);
        var_8_1 = eax_1;
    }
}

void* __thiscall sub_406744(void* arg1, int32_t arg2, uint32_t arg3)
{
    void* var_8 = arg1;
    void* var_c = arg1;
    int32_t edi;
    int32_t var_18 = edi;
    void* esi = *(arg1 + 0x440);

    if (!esi)
        esi = arg1 + 0x3c;

    int32_t ebx = arg2;
    uint32_t esi_1 = arg3;
    char* ecx_2 = esi - 1 + __crt_stdio_output::formatting_buffer::count<char>(arg1 + 0x3c);
    char* var_c_1 = ecx_2;
    char* edx = ecx_2;
    *(arg1 + 0x30) = ecx_2;

    while (true)
    {
        int32_t eax_3 = *(arg1 + 0x24);

        if (eax_3 <= 0)
        {
            if (!(ebx | esi_1))
            {
                *(arg1 + 0x34) = var_c_1 - edx;
                *(arg1 + 0x30) = &edx[1];
                return &edx[1];
            }

            eax_3 = *(arg1 + 0x24);
        }

        *(arg1 + 0x24) = eax_3 - 1;
        char eax_5 = ebx & 7;
        ebx = ebx >> 3 | esi_1 << 0x1d;
        *ecx_2 = eax_5 + 0x30;
        esi_1 u>>= 3;
        *(arg1 + 0x30) -= 1;
        edx = *(arg1 + 0x30);
        ecx_2 = edx;
    }
}

void* __thiscall sub_4067b8(void* arg1, uint32_t arg2, uint32_t arg3, char arg4)
{
    int32_t edi;
    int32_t var_20 = edi;
    void* esi = *(arg1 + 0x440);

    if (!esi)
        esi = arg1 + 0x3c;

    uint32_t ebx = arg3;
    char* esi_2 = esi - 1 + __crt_stdio_output::formatting_buffer::count<char>(arg1 + 0x3c);
    char* ecx_1 = esi_2;
    *(arg1 + 0x30) = esi_2;
    char* var_8 = esi_2;
    uint32_t esi_3 = arg2;

    while (true)
    {
        int32_t edx_1 = *(arg1 + 0x24);

        if (edx_1 <= 0 && !(esi_3 | ebx))
        {
            *(arg1 + 0x34) = esi_2 - ecx_1;
            *(arg1 + 0x30) = &ecx_1[1];
            return &ecx_1[1];
        }

        uint32_t var_24_1 = ebx;
        *(arg1 + 0x24) = edx_1 - 1;
        uint32_t eax_4;
        char ecx_2;
        uint32_t edx_2;
        eax_4 = __aulldvrm(esi_3, ebx, 0xa, 0);
        char ecx_3 = ecx_2 + 0x30;
        esi_3 = eax_4;
        ebx = edx_2;

        if (ecx_3 > 0x39)
            ecx_3 += ((arg4 ^ 1) << 5) + 7;

        *var_8 = ecx_3;
        *(arg1 + 0x30) -= 1;
        ecx_1 = *(arg1 + 0x30);
        var_8 = ecx_1;
    }
}

void* __thiscall sub_40684a(void* arg1, int32_t arg2, uint32_t arg3, char arg4)
{
    void* var_8 = arg1;
    void* var_c = arg1;
    int32_t edi;
    int32_t var_18 = edi;
    void* esi = *(arg1 + 0x440);

    if (!esi)
        esi = arg1 + 0x3c;

    int32_t ebx = arg2;
    uint32_t esi_1 = arg3;
    char* ecx_2 = esi - 1 + __crt_stdio_output::formatting_buffer::count<char>(arg1 + 0x3c);
    char* var_c_1 = ecx_2;
    char* edx = ecx_2;
    *(arg1 + 0x30) = ecx_2;

    while (true)
    {
        int32_t eax_3 = *(arg1 + 0x24);

        if (eax_3 <= 0)
        {
            if (!(ebx | esi_1))
            {
                *(arg1 + 0x34) = var_c_1 - edx;
                *(arg1 + 0x30) = &edx[1];
                return &edx[1];
            }

            eax_3 = *(arg1 + 0x24);
        }

        *(arg1 + 0x24) = eax_3 - 1;
        char eax_5 = ebx & 0xf;
        ebx = ebx >> 4 | esi_1 << 0x1c;
        eax_5 += 0x30;
        esi_1 u>>= 4;

        if (eax_5 > 0x39)
            eax_5 += ((arg4 ^ 1) << 5) + 7;

        *ecx_2 = eax_5;
        *(arg1 + 0x30) -= 1;
        edx = *(arg1 + 0x30);
        ecx_2 = edx;
    }
}

int32_t* __thiscall sub_4068d0(int32_t* arg1, int32_t* arg2, int32_t arg3, int32_t arg4, int32_t arg5, int32_t arg6, int32_t arg7)
{
    arg1[2] = arg6;
    *arg1 = 0;
    arg1[1] = 0;
    arg1[3] = 0;
    arg1[4] = 0;
    arg1[0x10f] = 0;
    arg1[0x110] = 0;
    arg1[5] = 0;
    arg1[6] = 0;
    arg1[7] = 0;
    arg1[8] = 0;
    arg1[9] = 0;
    arg1[0xb] = 0;
    arg1[0xd] = 0;
    arg1[0xe] = 0;
    arg1[0x112] = *arg2;
    *arg1 = arg3;
    arg1[3] = arg5;
    arg1[4] = arg7;
    arg1[1] = arg4;
    return arg1;
}

int32_t* __thiscall __crt_cached_ptd_host::__crt_cached_ptd_host(int32_t* arg1, int32_t* arg2)
{
    arg1[5] = 0;
    *arg1 = 0;
    arg1[2] = 0;
    arg1[7] = 0;
    arg1[9] = 0;

    if (arg2)
    {
        int32_t ecx_1 = arg2[1];
        arg1[3] = *arg2;
        arg1[5] = 1;
        arg1[4] = ecx_1;
        return arg1;
    }

    if (!data_41eca8)
    {
        void* eax_3 = data_41e348;
        void* ecx_2 = data_41e34c;
        arg1[5] = 1;
        arg1[4] = ecx_2;
        arg1[3] = eax_3;
    }

    return arg1;
}

void __fastcall __crt_cached_ptd_host::~__crt_cached_ptd_host(enum WIN32_ERROR arg1)
{
    int32_t edi;
    int32_t var_8 = edi;
    int32_t* edi_1 = arg1;

    if (edi_1[5] == 2)
    {
        void* eax = *edi_1;
        *(eax + 0x350) &= 0xfffffffd;
    }

    if (edi_1[7])
        *(sub_406b80(arg1) + 0x10) = edi_1[6];

    if (edi_1[9])
        *(sub_406b80(edi_1) + 0x14) = edi_1[8];
}

int32_t __fastcall __crt_stdio_output::formatting_buffer::~formatting_buffer(void* arg1)
{
    int32_t result = __free_base(*(arg1 + 0x404));
    *(arg1 + 0x404) = 0;
    return result;
}

int32_t* __thiscall sub_4069f6(int32_t* arg1, int32_t* arg2)
{
    __free_base(*arg1);
    *arg1 = 0;
    *arg1 = *arg2;
    *arg2 = 0;
    return arg1;
}

char* sub_406a1a(char* arg1, int32_t* arg2)
{
    char ebx = ***(*arg2 + 0x88);
    char* eax_4 = arg1;
    char i = *eax_4;
    char i_1;

    if (i)
    {
        i_1 = i;

        do
        {
            i = i_1;

            if (i_1 == ebx)
                break;

            eax_4 = &eax_4[1];
            i = *eax_4;
            i_1 = i;
        } while (i);
    }

    char* result = &eax_4[1];

    if (i)
    {
        while (true)
        {
            i = *result;

            if (!i)
                break;

            if (i == 0x65)
                break;

            if (i == 0x45)
                break;

            result = &result[1];
        }

        char* result_2 = result;

        do
        {
            result -= 1;
            i_1 = *result;
        } while (i_1 == 0x30);

        char* result_1 = &result[0xffffffff];

        if (i_1 != ebx)
            result_1 = result;

        char* esi_1 = result_2 - result_1;

        do
        {
            result = *(esi_1 + result_1);
            result_1 = &result_1[1];
            *result_1 = result;
        } while (result);
    }

    return result;
}

int32_t __stdcall sub_406a84(char arg1, char arg2)
{
    char eax_4;

    if (arg1 - 0x20 > 0x5a)
        eax_4 = 0;
    else
        eax_4 = *((((arg1 - 0x20) & 0x7f) << 1) + &data_416cf1);

    int32_t result = (arg2 + (eax_4 << 3)) & 0x7f;
    result = *((result << 1) + &data_416cf0);
    return result;
}

char* sub_406abf(char* arg1, int32_t* arg2)
{
    char* esi = arg1;
    int32_t edi;
    int32_t var_c = edi;
    int32_t* edi_1 = *arg2;
    char i_1 = *esi;
    int32_t ecx = edi_1[0x25];

    if (*(i_1 + ecx) != 0x65)
    {
        do
        {
            esi = &esi[1];
            i_1 = *esi;
        } while (*(*edi_1 + (i_1 << 1)) & 4);
    }

    char temp0 = *(i_1 + ecx);

    if (temp0 == 0x78)
        i_1 = esi[2];

    char* ecx_1 = &esi[2];

    if (temp0 != 0x78)
        ecx_1 = esi;

    char* result = *edi_1[0x22];
    char* esi_1 = &ecx_1[1];
    result = *result;
    *ecx_1 = result;
    char i;

    do
    {
        result = *esi_1;
        i = i_1;
        *esi_1 = i_1;
        esi_1 = &esi_1[1];
        i_1 = result;
    } while (i);
    return result;
}

void* __fastcall __crt_cached_ptd_host::force_synchronize_per_thread_data(int32_t* arg1)
{
    enum WIN32_ERROR dwErrCode = arg1;
    int32_t edi;
    int32_t var_10 = edi;
    enum WIN32_ERROR dwErrCode_1 = GetLastError();
    bool cond:0 = arg1[2];
    dwErrCode = dwErrCode_1;
    int32_t eax;

    if (cond:0)
        eax = arg1[1];
    else
    {
        arg1[1] = 0;
        eax = 0;
        arg1[2] = 1;
    }

    enum WIN32_ERROR* var_18 = &dwErrCode;
    void* result = sub_409c51(eax);
    *arg1 = result;
    SetLastError(dwErrCode);
    return result;
}

int32_t __fastcall sub_406b80(enum WIN32_ERROR arg1)
{
    enum WIN32_ERROR dwErrCode = arg1;
    int32_t edi;
    int32_t var_c = edi;
    int32_t* edi_1 = arg1;

    if (!*edi_1)
    {
        enum WIN32_ERROR dwErrCode_1 = GetLastError();
        bool cond:0_1 = edi_1[2];
        dwErrCode = dwErrCode_1;
        int32_t eax_1;

        if (cond:0_1)
            eax_1 = edi_1[1];
        else
        {
            edi_1[1] = 0;
            eax_1 = 0;
            edi_1[2] = 1;
        }

        enum WIN32_ERROR* var_18_1 = &dwErrCode;
        void* eax_2 = sub_409c51(eax_1);
        *edi_1 = eax_2;
        SetLastError(dwErrCode);

        if (!eax_2)
        {
            sub_4096af();
            /* no return */
        }
    }

    return *edi_1;
}

int32_t __thiscall sub_406bdc(void* arg1, int32_t* arg2)
{
    int32_t edi;
    int32_t var_20 = edi;
    char ebx = 1;
    int32_t* edi_1 = *(arg1 + 8);
    int32_t ecx_1 = *(arg1 + 0xc) - 1;
    int32_t eax = edi_1[6];
    int32_t var_2c = ecx_1;
    int32_t result_1 = edi_1[7];
    int32_t var_30 = ecx_1;
    int32_t var_30_1 = ecx_1;
    int32_t var_8 = ecx_1;
    *arg2 = sub_405f0f(edi_1, &var_8, 0xa, 1);
    void* eax_3 = *(arg1 + 8);
    int32_t eax_4;

    if (!*(eax_3 + 0x1c) || *(eax_3 + 0x18) != 0x22)
        eax_4 = var_8;

    if ((!*(eax_3 + 0x1c) || *(eax_3 + 0x18) != 0x22) && eax_4 >= *(arg1 + 0xc))
        *(arg1 + 0xc) = eax_4;
    else
        ebx = 0;

    edi_1[6] = eax;
    int32_t result = result_1;
    edi_1[7] = result;
    result = ebx;
    return result;
}

int32_t __fastcall __crt_stdio_output::output_processor<char,class __crt_stdio_output::string_output_adapter<char>,class __crt_stdio_output::standard_base<char,class __crt_stdio_output::string_output_adapter<char> > >::process(int32_t* arg1)
{
    int32_t* var_8 = arg1;
    int32_t* var_c = arg1;
    int32_t edi;
    int32_t var_18 = edi;

    if (sub_407996(&arg1[0x112], arg1[2]))
    {
        char* ecx_1 = arg1[3];

        if (ecx_1)
        {
            int32_t eax_4 = arg1[0x114] + 1;
            arg1[0x114] = eax_4;

            if (eax_4 != 2)
            {
                do
                {
                    arg1[0xd] = 0;
                    arg1[6] = 0;
                    char edx_1 = *ecx_1;
                    ecx_1 = &ecx_1[1];
                    *(&var_8 + 3) = edx_1;
                    arg1[3] = ecx_1;
                    *(arg1 + 0x2d) = edx_1;

                    if (edx_1)
                    {
                        *(&var_c + 3) = edx_1;

                        while (arg1[5] >= 0)
                        {
                            char eax_6 = sub_406a84(*(&var_c + 3), arg1[6]);
                            arg1[6] = eax_6;

                            if (eax_6 >= 8)
                            {
                                void* ecx_12 = arg1[2];
                                *(ecx_12 + 0x1c) = 1;
                                *(ecx_12 + 0x18) = 0x16;
                                goto label_406c91;
                            }

                            uint32_t eax_7 = eax_6;

                            if (eax_7 > 7)
                                return 0xffffffff;

                            int32_t* eax_31;
                            char eax_32;
                            int32_t eax_34;

                            switch (eax_7)
                            {
                                case 0:
                                {
                                    enum WIN32_ERROR edi_2 = arg1[2];
                                    arg1[0xe] = 0;

                                    if (!*(edi_2 + 0x14))
                                        __crt_cached_ptd_host::update_locale_slow(edi_2);

                                    char eax_8 = *(arg1 + 0x2d);
                                    *(&var_8 + 3) = eax_8;
                                    char ecx_6;

                                    if (!___acrt_locale_get_ctype_array_value(**(edi_2 + 0xc),
                                            eax_8, 0x8000))
                                        ecx_6 = *(&var_8 + 3);
                                    else
                                    {
                                        void* ecx_5 = arg1[0x112];

                                        if (*(ecx_5 + 8) != *(ecx_5 + 4))
                                        {
                                            arg1[5] += 1;
                                            *(ecx_5 + 8) += 1;
                                            **arg1[0x112] = *(&var_8 + 3);
                                            int32_t* eax_15 = arg1[0x112];
                                            *eax_15 += 1;
                                        }
                                        else if (!*(ecx_5 + 0xc))
                                            arg1[5] = 0xffffffff;
                                        else
                                            arg1[5] += 1;

                                        char* eax_16 = arg1[3];
                                        ecx_6 = *eax_16;
                                        arg1[3] = &eax_16[1];
                                        *(arg1 + 0x2d) = ecx_6;

                                        if (!ecx_6)
                                        {
                                            void* eax_18 = arg1[2];
                                            *(eax_18 + 0x1c) = 1;
                                            *(eax_18 + 0x18) = 0x16;
                                            __invalid_parameter_internal(0, 0, 0, 0, 0, arg1[2]);
                                            void* eax_19 = arg1[2];
                                            *(eax_19 + 0x1c) = 1;
                                            *(eax_19 + 0x18) = 0x16;
                                            __invalid_parameter_internal(0, 0, 0, 0, 0, arg1[2]);
                                            return 0xffffffff;
                                        }
                                    }

                                    void* edx_2 = arg1[0x112];

                                    if (*(edx_2 + 8) != *(edx_2 + 4))
                                    {
                                        arg1[5] += 1;
                                        *(edx_2 + 8) += 1;
                                        **arg1[0x112] = ecx_6;
                                        int32_t* eax_23 = arg1[0x112];
                                        *eax_23 += 1;
                                    }
                                    else if (!*(edx_2 + 0xc))
                                        arg1[5] = 0xffffffff;
                                    else
                                        arg1[5] += 1;
                                    break;
                                }
                                case 1:
                                {
                                    arg1[9] = 0xffffffff;
                                    arg1[8] = 0;
                                    arg1[0xb] = 0;
                                    arg1[7] = 0;
                                    arg1[0xa] = 0;
                                    arg1[0xe] = 0;
                                    break;
                                }
                                case 2:
                                {
                                    int32_t eax_24 = *(&var_8 + 3);

                                    if (eax_24 == 0x20)
                                        arg1[7] |= 2;
                                    else if (eax_24 == 0x23)
                                        arg1[7] |= 0x20;
                                    else if (eax_24 == 0x2b)
                                        arg1[7] |= 1;
                                    else if (eax_24 == 0x2d)
                                        arg1[7] |= 4;
                                    else if (eax_24 == 0x30)
                                        arg1[7] |= 8;
                                    break;
                                }
                                case 3:
                                {
                                    if (*(&var_8 + 3) != 0x2a)
                                    {
                                        eax_31 = &arg1[8];
                                    label_406e58:
                                        eax_32 = sub_406bdc(arg1, eax_31);
                                        goto label_406eb6;
                                    }

                                    int32_t* ecx_8 = arg1[4];
                                    arg1[4] = &ecx_8[1];
                                    eax_34 = *ecx_8;
                                    arg1[8] = eax_34;

                                    if (eax_34 < 0)
                                    {
                                        arg1[7] |= 4;
                                        arg1[8] = -(eax_34);
                                    }

                                label_406e7a:
                                    eax_32 = 1;
                                    goto label_406eb6;
                                }
                                case 4:
                                {
                                    arg1[9] = 0;
                                    break;
                                }
                                case 5:
                                {
                                    if (*(&var_8 + 3) != 0x2a)
                                    {
                                        eax_31 = &arg1[9];
                                        goto label_406e58;
                                    }

                                    int32_t* ecx_9 = arg1[4];
                                    arg1[4] = &ecx_9[1];
                                    eax_34 = *ecx_9;
                                    arg1[9] = eax_34;

                                    if (eax_34 < 0)
                                        arg1[9] = 0xffffffff;

                                    goto label_406e7a;
                                }
                                case 6:
                                {
                                    eax_32 = sub_406f28(arg1);
                                label_406eb6:

                                    if (!eax_32)
                                        return 0xffffffff;
                                    break;
                                }
                                case 7:
                                {
                                    eax_32 = sub_407081(arg1);
                                    goto label_406eb6;
                                }
                            }

                            char* eax_36 = arg1[3];
                            edx_1 = *eax_36;
                            ecx_1 = &eax_36[1];
                            arg1[3] = ecx_1;
                            *(&var_8 + 3) = edx_1;
                            *(arg1 + 0x2d) = edx_1;
                            *(&var_c + 3) = edx_1;

                            if (!edx_1)
                                break;
                        }
                    }

                    arg1[0x114] += 1;
                } while (arg1[0x114] != 2);
            }

            return arg1[5];
        }

        void* eax_1 = arg1[2];
        *(eax_1 + 0x1c) = 1;
        *(eax_1 + 0x18) = 0x16;
    label_406c91:
        __invalid_parameter_internal(0, 0, 0, 0, 0, arg1[2]);
    }

    return 0xffffffff;
}

void* __fastcall sub_406f28(int32_t* arg1)
{
    void* __saved_esi_3;
    __saved_esi_3 = *(arg1 + 0x2d);

    if (__saved_esi_3 == 0x46)
    {
        __saved_esi_3 = *arg1 & 8;

        if (!__saved_esi_3)
        {
            arg1[6] = 7;
            /* tailcall */
            return sub_407081(arg1);
        }
    }
    else if (__saved_esi_3 != 0x4e)
    {
        if (arg1[0xa])
            goto label_406f60;

        if (__saved_esi_3 == 0x6c)
        {
            char* eax_10 = arg1[3];
            void* __saved_esi_2;

            if (*eax_10 != 0x6c)
                __saved_esi_2 = 3;
            else
            {
                arg1[3] = &eax_10[1];
                __saved_esi_2 = 4;
            }

            __saved_esi_3 = __saved_esi_2;
            arg1[0xa] = __saved_esi_3;
        }
        else if (__saved_esi_3 == 0x74)
            arg1[0xa] = 7;
        else if (__saved_esi_3 == 0x77)
            arg1[0xa] = 0xc;
        else if (__saved_esi_3 == 0x7a)
            arg1[0xa] = 6;

        if (__saved_esi_3 == 0x6a)
            arg1[0xa] = 5;
        else if (__saved_esi_3 == 0x49)
        {
            char* esi_1 = arg1[3];
            __saved_esi_3 = *esi_1;

            if (__saved_esi_3 == 0x33 && esi_1[1] == 0x32)
            {
                __saved_esi_3 = &esi_1[2];
                arg1[0xa] = 0xa;
                arg1[3] = __saved_esi_3;
            }
            else if (__saved_esi_3 != 0x36)
            {
                if (__saved_esi_3 == 0x64 || __saved_esi_3 == 0x69 || __saved_esi_3 == 0x6f
                        || __saved_esi_3 == 0x75 || __saved_esi_3 == 0x78 || __saved_esi_3 == 0x58)
                    arg1[0xa] = 9;
            }
            else if (esi_1[1] == 0x34)
            {
                __saved_esi_3 = &esi_1[2];
                arg1[0xa] = 0xb;
                arg1[3] = __saved_esi_3;
            }
        }
        else if (__saved_esi_3 == 0x4c)
            arg1[0xa] = 8;
        else if (__saved_esi_3 == 0x54)
            arg1[0xa] = 0xd;
        else if (__saved_esi_3 == 0x68)
        {
            char* eax_8 = arg1[3];

            if (*eax_8 != 0x68)
            {
                __saved_esi_3 = 2;
                arg1[0xa] = __saved_esi_3;
            }
            else
            {
                arg1[3] = &eax_8[1];
                __saved_esi_3 = 1;
                arg1[0xa] = __saved_esi_3;
            }
        }
    }
    else
    {
        __saved_esi_3 = *arg1 & 8;

        if (!__saved_esi_3)
        {
            arg1[6] = 8;
        label_406f60:
            int32_t* eax_6 = arg1[2] + 0x18;
            eax_6[1] = 1;
            *eax_6 = 0x16;
            int32_t eax_7 = __invalid_parameter_internal(0, 0, 0, 0, 0, arg1[2]);
            eax_7 = 0;
            return eax_7;
        }
    }

    __saved_esi_3 = 1;
    return __saved_esi_3;
}

int32_t* __fastcall sub_407081(int32_t* arg1)
{
    int32_t var_8 = 0xffffffff;
    int32_t (* var_c)(void* arg1 @ 0x8) = sub_41566d;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t __saved_ebp;
    int32_t eax_2 = __security_cookie ^ &__saved_ebp;
    int32_t edi;
    int32_t var_40 = edi;
    int32_t var_44 = eax_2;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t* esi = arg1;
    int32_t* var_1c = esi;
    int32_t eax_3 = *(esi + 0x2d);
    int32_t ebx = 0;
    int32_t* result;
    char var_48_2;

    if (eax_3 <= 0x64)
    {
        if (eax_3 == 0x64)
        {
        label_407155:
            esi[7] |= 0x10;
        label_40715c:
            result = sub_4062cd(esi, 0);
            goto label_407192;
        }

        if (eax_3 > 0x53)
        {
            if (eax_3 == 0x58)
            {
                var_48_2 = 1;
            label_407126:
                result = sub_40645a(esi, var_48_2);
                goto label_407192;
            }

            if (eax_3 == 0x5a)
            {
                result = sub_407514(esi);
                goto label_407192;
            }

            if (eax_3 == 0x61)
                goto label_4070ef;

            result = eax_3 - 0x63;

            if (eax_3 == 0x63)
                goto label_40710f;

            result = 0;
        }
        else
        {
            if (eax_3 == 0x53)
                goto label_407184;

            if (eax_3 == 0x41)
                goto label_4070ef;

            if (eax_3 == 0x43)
            {
            label_40710f:
                int32_t var_48_1 = 0;
                result = sub_40773e(esi);
                goto label_407192;
            }

            if (eax_3 == 0x45 || eax_3 == 0x46)
                goto label_4070ef;

            result = eax_3 - 0x47;

            if (eax_3 == 0x47)
                goto label_4070ef;

            result = 0;
        }
    }
    else if (eax_3 <= 0x6f)
    {
        if (eax_3 == 0x6f)
        {
            result = sub_40784f(esi);
            goto label_407192;
        }

        if (eax_3 == 0x65 || eax_3 == 0x66 || eax_3 == 0x67)
        {
        label_4070ef:
            result = sub_407587(esi);
            goto label_407192;
        }

        if (eax_3 == 0x69)
            goto label_407155;

        result = eax_3 - 0x6e;

        if (eax_3 == 0x6e)
        {
            result = sub_4077ca(esi);
            goto label_407192;
        }

        result = 0;
    }
    else if (eax_3 == 0x70)
    {
        result = sub_40786c(esi);
    label_407192:

        if (result)
        {
            if (!esi[0xb])
            {
                uint16_t eax_19 = esi[7] >> 4;
                int16_t var_24 = 0;
                int32_t* result_3 = nullptr;
                char var_22_1 = 0;
                int32_t* result_2 = nullptr;
                eax_19 &= 1;

                if (eax_19)
                {
                    eax_19 = esi[7] >> 6;
                    eax_19 &= 1;

                    if (!eax_19)
                    {
                        eax_19 = esi[7];
                        eax_19 &= 1;

                        if (!eax_19)
                        {
                            eax_19 = esi[7] >> 1;
                            eax_19 &= 1;

                            if (eax_19)
                            {
                                var_24 = 0x20;
                                result_3 = 1;
                                result_2 = 1;
                            }
                        }
                        else
                        {
                            var_24 = 0x2b;
                            result_3 = 1;
                            result_2 = 1;
                        }
                    }
                    else
                    {
                        var_24 = 0x2d;
                        result_3 = 1;
                        result_2 = 1;
                    }
                }

                char edx_1 = *(esi + 0x2d);

                if (edx_1 == 0x78 || edx_1 == 0x58)
                {
                    eax_19 = esi[7] >> 5;
                    *(&eax_19 + 1) = 1;
                    eax_19 &= 1;
                }

                if ((edx_1 != 0x78 && edx_1 != 0x58) || !eax_19)
                    *(&eax_19 + 1) = 0;

                if (edx_1 != 0x61)
                    eax_19 = 0;

                if (edx_1 == 0x61 || edx_1 == 0x41)
                    eax_19 = 1;

                if (*(&eax_19 + 1) || eax_19)
                {
                    *(&var_24 + result_3) = 0x30;
                    char eax_23;

                    eax_23 = edx_1 == 0x58 || edx_1 == 0x41 ? 0x58 : 0x78;

                    *((&var_24 + 1) + result_3) = eax_23;
                    result_3 += 2;
                    result_2 = result_3;
                }

                void* edx_4 = esi[8] - esi[0xd] - result_3;

                if (!(esi[7] & 0xc) && edx_4 > 0)
                {
                    int32_t ebx_1 = esi[5];
                    int32_t ecx_9 = 0;

                    do
                    {
                        void* edi_1 = esi[0x112];

                        if (*(edi_1 + 8) != *(edi_1 + 4))
                        {
                            esi[5] = ebx_1 + 1;
                            *(edi_1 + 8) += 1;
                            **esi[0x112] = 0x20;
                            int32_t* eax_28 = esi[0x112];
                            *eax_28 += 1;
                        }
                        else
                        {
                            int32_t ebx_2;

                            if (!*(edi_1 + 0xc))
                                ebx_2 = 0xffffffff;
                            else
                                ebx_2 = ebx_1 + 1;

                            esi[5] = ebx_2;
                        }

                        ebx_1 = esi[5];

                        if (ebx_1 == 0xffffffff)
                            break;

                        ecx_9 += 1;
                    } while (ecx_9 < edx_4);

                    result_3 = result_2;
                    ebx = 0;
                }

                int32_t var_48_3 = esi[2];
                int32_t* edi_2 = &esi[5];
                result_2 = &esi[0x112];
                sub_4079c7(&esi[0x112], &var_24, result_3, edi_2);
                int32_t ecx_11 = esi[7];

                if (ecx_11 >> 3 & 1 && !(ecx_11 >> 2 & 1))
                {
                    int32_t var_28_1 = 0;

                    if (edx_4 > 0)
                    {
                        int32_t esi_1 = *edi_2;
                        int32_t* result_4 = result_2;

                        do
                        {
                            void* edx_5 = *result_4;

                            if (*(edx_5 + 8) != *(edx_5 + 4))
                            {
                                *edi_2 = esi_1 + 1;
                                *(edx_5 + 8) += 1;
                                result_4 = result_2;
                                ***result_4 = 0x30;
                                int32_t* eax_36 = *result_4;
                                *eax_36 += 1;
                            }
                            else
                            {
                                int32_t esi_2;

                                if (!*(edx_5 + 0xc))
                                    esi_2 = 0xffffffff;
                                else
                                    esi_2 = esi_1 + 1;

                                *edi_2 = esi_2;
                                result_4 = result_2;
                            }

                            esi_1 = *edi_2;

                            if (esi_1 == 0xffffffff)
                                break;

                            ebx += 1;
                        } while (ebx < edx_4);

                        esi = var_1c;
                        ebx = 0;
                    }
                }

                int32_t var_8_1 = 0;

                if (!esi[0xe] || esi[0xd] <= 0)
                {
                    int32_t var_48_8 = esi[2];
                    result = sub_4079c7(&esi[0x112], esi[0xc], esi[0xd], edi_2);
                }
                else
                {
                    int32_t* eax_37 = esi[2];
                    var_1c = eax_37;

                    if (!eax_37[5])
                    {
                        __crt_cached_ptd_host::update_locale_slow(eax_37);
                        eax_37 = var_1c;
                    }

                    result = eax_37[3];
                    int16_t* ecx_15 = esi[0xc];
                    int32_t edx_6 = esi[0xd];

                    if (result[2] != 0xfde9)
                    {
                        int32_t* result_1 = nullptr;

                        if (edx_6)
                        {
                            while (true)
                            {
                                int32_t* var_48_6 = esi[2];
                                uint32_t var_4c_4 = *ecx_15;
                                result_2 = nullptr;
                                var_24 = &ecx_15[1];
                                result = sub_40b830(&result_2, edx_6, &ecx_15[1], &result_2,
                                    &var_1c, 6, var_48_6);

                                if (result)
                                    break;

                                if (result_2 == result)
                                    break;

                                int32_t var_48_7 = esi[2];
                                edx_6 = sub_4079c7(&esi[0x112], &var_1c, result_2, edi_2);
                                ecx_15 = var_24;
                                result = result_1 + 1;
                                result_1 = result;

                                if (result == esi[0xd])
                                    goto label_40743d;
                            }

                            *edi_2 = 0xffffffff;
                        }
                    }
                    else
                    {
                        result_2 = nullptr;
                        int64_t var_2c = 0;

                        if (edx_6)
                        {
                            while (true)
                            {
                                int16_t eax_38 = *ecx_15;
                                int32_t* var_48_4 = esi[2];
                                var_24 = &ecx_15[1];
                                result = sub_40bcbe(&var_1c, edx_6, &var_2c, &var_1c, eax_38,
                                    &var_2c, var_48_4);

                                if (result == 0xffffffff)
                                    break;

                                int32_t var_48_5 = esi[2];
                                edx_6 = sub_4079c7(&esi[0x112], &var_1c, result, edi_2);
                                ecx_15 = var_24;
                                result = result_2 + 1;
                                result_2 = result;

                                if (result == esi[0xd])
                                    goto label_40743d;
                            }

                            *edi_2 = 0xffffffff;
                        }
                    }
                }

            label_40743d:
                int32_t ecx_22 = esi[5];

                if (ecx_22 >= 0)
                {
                    result = esi[7] >> 2;

                    if (result & 1 && edx_4 > 0)
                    {
                        do
                        {
                            void* edx_7 = esi[0x112];

                            if (*(edx_7 + 8) != *(edx_7 + 4))
                            {
                                esi[5] = ecx_22 + 1;
                                *(edx_7 + 8) += 1;
                                **esi[0x112] = 0x20;
                                result = esi[0x112];
                                *result += 1;
                            }
                            else
                            {
                                result = &esi[5];
                                int32_t ecx_23;

                                if (!*(edx_7 + 0xc))
                                    ecx_23 = 0xffffffff;
                                else
                                    ecx_23 = ecx_22 + 1;

                                *result = ecx_23;
                            }

                            ecx_22 = esi[5];

                            if (ecx_22 == 0xffffffff)
                                break;

                            ebx += 1;
                        } while (ebx < edx_4);
                    }
                }
            }

            result = 1;
        }
        else
            result = 0;
    }
    else
    {
        if (eax_3 == 0x73)
        {
        label_407184:
            result = sub_407882(esi);
            goto label_407192;
        }

        if (eax_3 == 0x75)
            goto label_40715c;

        result = eax_3 - 0x78;

        if (eax_3 == 0x78)
        {
            var_48_2 = 0;
            goto label_407126;
        }

        result = 0;
    }
    fsbase->NtTib.ExceptionList = ExceptionList;
    sub_402910(eax_2 ^ &__saved_ebp);
    return result;
}

int32_t __crt_stdio_output::to_integer_size(int32_t arg1)
{
    switch (arg1)
    {
        case 0:
        case 3:
        case 6:
        case 7:
        case 9:
        case 0xa:
        {
            return 4;
            break;
        }
        case 1:
        {
            return 1;
            break;
        }
        case 2:
        {
            return 2;
            break;
        }
        case 4:
        case 5:
        case 0xb:
        {
            return 8;
            break;
        }
    }

    return 0;
}

uint32_t __fastcall sub_407514(int32_t* arg1)
{
    int32_t* var_8 = arg1;
    int32_t* var_c = arg1;
    int32_t edi;
    int32_t var_14 = edi;
    int32_t* edx = arg1[4];
    arg1[4] = &edx[1];
    int16_t* ebx = *edx;
    uint32_t result;

    if (!ebx || !*(ebx + 4))
    {
        result = 6;
        arg1[0xc] = "(null)";
        arg1[0xe] = 0;
    }
    else
    {
        int32_t ecx = arg1[0xa];
        edx = *(arg1 + 0x2d);
        int32_t eax_1 = arg1[1];
        int32_t esi_1 = *arg1;
        arg1[0xc] = *(ebx + 4);
        int32_t var_24_1 = eax_1;
        int32_t var_28_1 = esi_1;
        result = *ebx;

        if (!__crt_stdio_output::is_wide_character_specifier<char>(edx, ecx))
            arg1[0xe] = 0;
        else
        {
            arg1[0xe] = 1;
            result u>>= 1;
        }
    }

    arg1[0xd] = result;
    result = 1;
    return result;
}

uint8_t __fastcall sub_407587(int32_t* arg1)
{
    arg1[7] |= 0x10;
    int32_t eax = arg1[9];

    if (eax < 0)
    {
        char eax_1 = *(arg1 + 0x2d);
        int32_t var_2c_1;

        var_2c_1 = eax_1 == 0x61 || eax_1 == 0x41 ? 0xd : 6;

        eax = var_2c_1;
        arg1[9] = eax;
    }
    else if (!eax)
    {
        char ecx = *(arg1 + 0x2d);

        if (ecx == 0x67 || ecx == 0x47)
        {
            arg1[9] = 1;
            eax = 1;
        }
    }

    void* eax_5;

    if (sub_405e2a(&arg1[0xf], eax + 0x15d, arg1[2]))
        eax_5 = arg1[9];
    else
    {
        eax_5 = __crt_stdio_output::formatting_buffer::count<char>(&arg1[0xf]) - 0x15d;
        arg1[9] = eax_5;
    }

    char* eax_6 = arg1[0x110];

    if (!eax_6)
        eax_6 = &arg1[0xf];

    int32_t var_20 = 0;
    int32_t var_1c = 0;
    arg1[0xc] = eax_6;
    int32_t* ecx_4 = arg1[4];
    int32_t edi;
    int32_t var_2c_3 = edi;
    arg1[4] = &ecx_4[2];
    int32_t ecx_5 = ecx_4[1];
    var_20 = *ecx_4;
    int32_t ebx_1 = *(arg1 + 0x2d);
    int32_t var_1c_1 = ecx_5;
    uint32_t eax_10 = __crt_stdio_output::formatting_buffer::count<char>(&arg1[0xf]);
    char* eax_11 = __crt_stdio_output::formatting_buffer::scratch_data<char>(&arg1[0xf]);
    uint32_t eax_12 = __crt_stdio_output::formatting_buffer::count<char>(&arg1[0xf]);
    char* eax_13 = arg1[0x110];

    if (!eax_13)
        eax_13 = &arg1[0xf];

    int32_t var_38 = arg1[1];
    sub_40b6b0(&var_20, eax_13, eax_12, eax_11, eax_10, ebx_1, eax_5, *arg1, 1, arg1[2]);
    char* esi_2 = arg1 + 0x2d;
    int32_t* ecx_10 = &arg1[0xc];

    if (arg1[7] >> 5 & 1 && !arg1[9])
    {
        enum WIN32_ERROR edi_3 = arg1[2];

        if (!*(edi_3 + 0x14))
        {
            __crt_cached_ptd_host::update_locale_slow(edi_3);
            esi_2 = arg1 + 0x2d;
        }

        sub_406abf(arg1[0xc], edi_3 + 0xc);
        ecx_10 = &arg1[0xc];
    }

    uint8_t eax_15 = *esi_2;
    int32_t* esi_3;

    if (eax_15 != 0x67)
        esi_3 = ecx_10;

    if (eax_15 == 0x67 || eax_15 == 0x47)
    {
        esi_3 = ecx_10;

        if (!(arg1[7] >> 5 & 1))
        {
            enum WIN32_ERROR edi_4 = arg1[2];

            if (!*(edi_4 + 0x14))
            {
                __crt_cached_ptd_host::update_locale_slow(edi_4);
                esi_3 = &arg1[0xc];
            }

            sub_406a1a(arg1[0xc], edi_4 + 0xc);
        }
    }

    uint8_t* edx_3 = arg1[0xc];
    eax_15 = *edx_3;

    if (eax_15 == 0x2d)
    {
        arg1[7] |= 0x40;
        edx_3 = &edx_3[1];
        *esi_3 = edx_3;
        eax_15 = *edx_3;
    }

    if (eax_15 == 0x69 || eax_15 == 0x49 || eax_15 == 0x6e || eax_15 == 0x4e)
    {
        arg1[7] &= 0xfffffff7;
        *(arg1 + 0x2d) = 0x73;
    }

    uint8_t i;

    do
    {
        i = *edx_3;
        edx_3 = &edx_3[1];
    } while (i);
    arg1[0xd] = edx_3 - &edx_3[1];
    return 1;
}

void* __fastcall sub_40773e(int32_t* arg1)
{
    int32_t edi;
    int32_t var_8 = edi;
    int32_t var_14 = arg1[1];
    int32_t var_18 = *arg1;
    char eax_1 = __crt_stdio_output::is_wide_character_specifier<char>(*(arg1 + 0x2d), arg1[0xa]);
    int16_t* ecx = arg1[4];
    void* result = &ecx[2];

    if (!eax_1)
    {
        char* edx_1 = arg1[0x110];
        arg1[4] = result;
        result = *ecx;

        if (!edx_1)
            edx_1 = &arg1[0xf];

        *edx_1 = result;
        arg1[0xd] = 1;
    }
    else
    {
        arg1[4] = result;
        uint32_t esi_1 = *ecx;
        uint32_t eax_2 = __crt_stdio_output::formatting_buffer::count<char>(&arg1[0xf]);
        char* ecx_2 = arg1[0x110];
        uint32_t var_14_1 = esi_1;

        if (!ecx_2)
            ecx_2 = &arg1[0xf];

        int32_t edx;
        result = sub_40b830(&arg1[0xd], edx, ecx_2, &arg1[0xd], ecx_2, eax_2, arg1[2]);

        if (result)
            arg1[0xb] = 1;
    }

    char* ecx_3 = arg1[0x110];
    result = 1;

    if (!ecx_3)
        ecx_3 = &arg1[0xf];

    arg1[0xc] = ecx_3;
    return result;
}

int32_t __fastcall sub_4077ca(void* arg1)
{
    int32_t edi;
    int32_t var_8 = edi;
    int32_t* edx = *(arg1 + 0x10);
    *(arg1 + 0x10) = &edx[1];
    int32_t* edi_1 = *edx;
    int32_t result;

    if (__get_printf_count_output())
    {
        int32_t eax_3 = __crt_stdio_output::to_integer_size(*(arg1 + 0x28));
        result = eax_3 - 1;

        if (eax_3 == 1)
        {
            result = *(arg1 + 0x14);
            *edi_1 = result;
            *(arg1 + 0x2c) = 1;
            result = 1;
        }
        else
        {
            int32_t result_1 = result;
            result -= 1;

            if (result_1 == 1)
            {
                result = *(arg1 + 0x14);
                *edi_1 = result;
                *(arg1 + 0x2c) = 1;
                result = 1;
            }
            else if (result == 2)
            {
                result = *(arg1 + 0x14);
                *edi_1 = result;
                *(arg1 + 0x2c) = 1;
                result = 1;
            }
            else
            {
                if (result != 6)
                    goto label_4077e4;

                int32_t edx_1;
                edx_1 = HIGHD(*(arg1 + 0x14));
                result = LOWD(*(arg1 + 0x14));
                *edi_1 = result;
                edi_1[1] = edx_1;
                *(arg1 + 0x2c) = 1;
                result = 1;
            }
        }
    }
    else
    {
    label_4077e4:
        void* eax_2 = *(arg1 + 8);
        *(eax_2 + 0x1c) = 1;
        *(eax_2 + 0x18) = 0x16;
        result = __invalid_parameter_internal(0, 0, 0, 0, 0, *(arg1 + 8));
        result = 0;
    }

    return result;
}

uint32_t __fastcall sub_40784f(void* arg1)
{
    int32_t edx_1 = *(arg1 + 0x1c);

    if (edx_1 >> 5 & 1)
        *(arg1 + 0x1c) = edx_1 | 0x80;

    return sub_406140(arg1, 0);
}

uint32_t __fastcall sub_40786c(void* arg1)
{
    *(arg1 + 0x24) = 8;
    *(arg1 + 0x28) = 0xa;
    return sub_40645a(arg1, 1);
}

int32_t __fastcall sub_407882(int32_t* arg1)
{
    int32_t edi;
    int32_t var_c = edi;
    int32_t* edx = arg1[4];
    arg1[4] = &edx[1];
    uint32_t ebx = arg1[9];
    int32_t var_10 = arg1[0xa];
    wchar16 const* const esi = *edx;

    if (ebx == 0xffffffff)
        ebx = 0x7fffffff;

    char eax_1 = *(arg1 + 0x2d);
    int32_t var_18 = arg1[1];
    arg1[0xc] = esi;
    int32_t var_1c = *arg1;
    int32_t result;
    void invalid;

    if (!__crt_stdio_output::is_wide_character_specifier<char>(eax_1, var_10))
    {
        if (!esi)
        {
            esi = "(null)";
            arg1[0xc] = "(null)";
        }

        result = sub_40a910(invalid, esi, ebx);
    }
    else
    {
        if (!esi)
        {
            esi = u"(null)";
            arg1[0xc] = u"(null)";
        }

        arg1[0xe] = 1;
        result = sub_40aa70(invalid, esi, ebx);
    }
    arg1[0xd] = result;
    result = 1;
    return result;
}

char* __thiscall __crt_strtox::c_string_character_source<char>::unget(int32_t* arg1, char arg2)
{
    char* result = *arg1 - 1;
    *arg1 = result;

    if (!arg2 || *result == arg2)
        return result;

    *sub_40a844() = 0x16;
    return __invalid_parameter_noinfo();
}

int32_t __fastcall __crt_cached_ptd_host::update_locale_slow(enum WIN32_ERROR arg1)
{
    enum WIN32_ERROR var_8 = arg1;
    int32_t edi;
    int32_t var_14 = edi;
    int32_t eax = sub_406b80(arg1);
    void* var_18 = *(arg1 + 4);
    *(arg1 + 0xc) = *(eax + 0x4c);
    *(arg1 + 0x10) = *(eax + 0x48);
    ___acrt_update_locale_info_explicit(eax, arg1 + 0xc, var_18);
    ___acrt_update_multibyte_info_explicit(eax, arg1 + 0x10, *(arg1 + 4));
    int32_t result = *(eax + 0x350);

    if (!(result & 2))
    {
        result |= 2;
        *(eax + 0x350) = result;
        *(arg1 + 0x14) = 2;
    }

    return result;
}

int32_t __fastcall sub_40797b(int32_t* arg1)
{
    if (*arg1)
    {
        int32_t eax;
        eax = 1;
        return eax;
    }

    *sub_40a844() = 0x16;
    int32_t eax_2 = __invalid_parameter_noinfo();
    eax_2 = 0;
    return eax_2;
}

int32_t __thiscall sub_407996(int32_t* arg1, int32_t* arg2)
{
    int32_t result;

    if (*arg1)
        result = 1;
    else
    {
        arg2[7] = 1;
        arg2[6] = 0x16;
        result = __invalid_parameter_internal(0, 0, 0, 0, 0, arg2);
        result = 0;
    }

    return result;
}

void __thiscall sub_4079c7(int32_t* arg1, char* arg2, void* arg3, int32_t* arg4)
{
    if (!arg3)
        return;

    int32_t* eax_1 = *arg1;
    int32_t edx_1 = eax_1[1];

    if (eax_1[2] != edx_1)
    {
        void* edx_2 = edx_1 - eax_1[2];
        int32_t edi;
        int32_t var_10_1 = edi;
        void* edi_1 = arg3;

        if (edx_2 < arg3)
            edi_1 = edx_2;

        sub_4035c0(*eax_1, arg2, edi_1);
        int32_t* eax_2 = *arg1;
        *eax_2 += edi_1;
        void* eax_3 = *arg1;
        *(eax_3 + 8) += edi_1;

        if (*(*arg1 + 0xc))
            *arg4 += arg3;
        else if (edi_1 == arg3)
            *arg4 += edi_1;
        else
            *arg4 = 0xffffffff;
    }
    else if (!eax_1[3])
        *arg4 = 0xffffffff;
    else
        *arg4 += arg3;
}

int32_t ___acrt_locale_get_ctype_array_value(int32_t arg1, int32_t arg2, int32_t arg3)
{
    if (arg2 + 1 > 0x100)
        return 0;

    return *(arg1 + (arg2 << 1)) & arg3;
}

int32_t* ___stdio_common_vsprintf(int32_t arg1, int32_t arg2, int32_t* arg3, int32_t arg4, int32_t arg5, int32_t* arg6, int32_t arg7)
{
    void var_2c;
    __crt_cached_ptd_host::__crt_cached_ptd_host(&var_2c, arg6);
    int32_t* result = sub_405c9e(arg1, arg2, arg3, arg4, arg5, &var_2c, arg7);
    __crt_cached_ptd_host::~__crt_cached_ptd_host(&var_2c);
    return result;
}

uint32_t __convention("regparm") sub_407a99(int32_t arg1, int32_t arg2, int32_t arg3, uint32_t* arg4)
{
    FILETIME systemTimeAsFileTime = struct FILETIME {
        .dwHighDateTime = arg3,
        .dwLowDateTime = arg3
    };
    int32_t edi;
    int32_t var_14 = edi;
    __builtin_memset(&systemTimeAsFileTime, 0, 8);
    GetSystemTimeAsFileTime(&systemTimeAsFileTime);
    DWORD dwLowDateTime = systemTimeAsFileTime.dwLowDateTime;
    uint32_t result;
    int32_t edx;
    result = __alldiv(dwLowDateTime + 0x2ac18000, systemTimeAsFileTime.dwHighDateTime - 0x19db1de,
        0x989680, 0);

    if (edx > 7)
    {
        result = 0xffffffff;
        edx = 0xffffffff;
    }
    else if (edx >= 7 && result > 0x93582aff)
    {
        result = 0xffffffff;
        edx = 0xffffffff;
    }

    if (arg4)
    {
        *arg4 = result;
        arg4[1] = edx;
    }

    return result;
}

long double sub_407b10(int32_t arg1, int32_t arg2, int32_t arg3 @ 0x1c)
{
    void* const __return_addr_1 = __return_addr;
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    int32_t edi;
    int32_t var_a0 = edi;
    int32_t edi_1 = arg3;
    int32_t var_ac = arg1;
    double arg_14;
    int32_t eax_2 = sub_407c50(var_ac, &arg_14, edi_1);
    int64_t arg_c;

    if (!eax_2)
    {
        int32_t var_50;
        int32_t var_50_1 = var_50 & 0xfffffffe;
        void var_90;
        sub_407fb0(&var_90, &arg3, arg1, arg2, &arg_c, &arg_14, eax_2);
        /* no return */
    }

    char eax_3 = arg1;
    int32_t esi_1;

    if (eax_3 & 0x20)
        esi_1 = 5;
    else if (eax_3 & 8)
        esi_1 = 1;
    else if (eax_3 & 4)
        esi_1 = 2;
    else if (!(eax_3 & 1))
        esi_1 = (eax_3 & 2) * 2;
    else
        esi_1 = 3;

    if (!___acrt_has_user_matherr())
    {
        if (esi_1 == 1)
            *sub_40a844() = 0x21;
        else if (esi_1 == 2 || esi_1 == 3)
            *sub_40a844() = 0x22;
    }
    else if (esi_1)
    {
        int32_t var_a4_2 = edi_1;
        var_ac = arg_14;
        int32_t var_b4;
        var_b4 = {0};
        int32_t var_bc;
        var_bc = arg_c;
        int32_t var_b8;
        int32_t var_b0;
        int80_t st0 = sub_408320(esi_1, arg2, var_bc, var_b8, var_b4, var_b0, var_ac);
        sub_402910(eax_1 ^ &__saved_ebp);
        return st0;
    }

    int16_t x87control;
    sub_40c870(x87control, edi_1, 0xffff);
    long double x87_r7_1 = arg_14;
    sub_402910(eax_1 ^ &__saved_ebp);
    return x87_r7_1;
}

int32_t sub_407c50(int32_t arg1, int64_t* arg2, int32_t arg3)
{
    int32_t ecx = arg1;
    int32_t edx = arg3;
    int32_t edi;
    int32_t var_34 = edi;
    int32_t esi = 0;
    int32_t edi_2 = ecx & 0x1f;

    if (ecx & 8 && edx & 1)
    {
        esi = 1;
        edi_2 &= 0xfffffff7;
    }
    else if (ecx & edx & 4)
    {
        esi = 4;
        edi_2 &= 0xfffffffb;
    }
    else if (ecx & 1 && edx & 8)
    {
        esi = 8;
        int32_t eax_4 = edx & 0xc00;
        int64_t* eax_6;

        if (eax_4 > 0x800)
        {
            if (eax_4 != 0xc00)
                edi_2 &= 0xfffffffe;
            else
            {
                eax_6 = arg2;

                if (*eax_6 <= 0.0)
                {
                label_407d95:
                    *eax_6 = 0x7fefffffffffffff ^ data_416fc0;
                    edi_2 &= 0xfffffffe;
                }
                else
                {
                    edi_2 &= 0xfffffffe;
                    *eax_6 = 0x7fefffffffffffff;
                }
            }
        }
        else if (eax_4 == 0x800)
        {
            eax_6 = arg2;

            if (*eax_6 <= 0.0)
                goto label_407d95;

            edi_2 &= 0xfffffffe;
            *eax_6 = 0x7ff0000000000000;
        }
        else if (!eax_4)
        {
            int64_t xmm0_6 = 0x7ff0000000000000;

            if (*arg2 > 0.0)
            {
                *arg2 = xmm0_6;
                edi_2 &= 0xfffffffe;
            }
            else
            {
                edi_2 &= 0xfffffffe;
                *arg2 = xmm0_6 ^ data_416fc0;
            }
        }
        else if (eax_4 != 0x400)
            edi_2 &= 0xfffffffe;
        else if (*arg2 <= 0.0)
        {
            edi_2 &= 0xfffffffe;
            *arg2 = 0x7ff0000000000000 ^ data_416fc0;
        }
        else
        {
            edi_2 &= 0xfffffffe;
            *arg2 = 0x7fefffffffffffff;
        }
    }
    else if (ecx & 2 && edx & 0x10)
    {
        int64_t* eax_7 = arg2;
        int32_t esi_3 = ecx >> 4 & 1;
        double xmm0_13 = *eax_7;
        xmm0_13 - 0.0;
        *(&eax_7 + 1) = (xmm0_13 == 0.0 ? 1 : 0) << 6 | (FCMP_UO(xmm0_13, 0.0) ? 1 : 0) << 2
            | (xmm0_13 < 0.0 ? 1 : 0);

        if (__builtin_popcount(*(&eax_7 + 1) & 0x44) & 1)
            esi_3 = 1;
        else
        {
            int32_t var_20;
            double var_1c_1 = sub_40c5e0(xmm0_13, &var_20);
            double xmm0_14 = var_1c_1;
            double var_2c_1 = xmm0_14;
            *(&var_1c_1 + 4) = var_20 - 0x600;

            if (var_20 - 0x600 >= 0xfffffbce)
            {
                uint32_t edi_3 = var_2c_1;
                int32_t eax_9 = 0;
                eax_9 = 0 > xmm0_14;
                int32_t ecx_2;
                ecx_2 = 0;
                char var_5_1 = 0;
                uint32_t eax_12 = (*(&var_2c_1 + 6) & 0xf) | 0x10;
                *(&var_2c_1 + 6) = eax_12;
                eax_12 = 0;
                uint32_t var_10_1 = eax_12;

                if (var_20 - 0x600 < 0xfffffc03)
                {
                    int32_t i_1 = 0xfffffc03 - *(&var_1c_1 + 4);
                    *(&var_1c_1 + 4) = 1;
                    int32_t i;

                    do
                    {
                        ecx_2 = edi_3 & 1;

                        if (ecx_2 && !esi_3)
                            esi_3 = 1;

                        uint32_t eax_14 = var_10_1;

                        if (var_5_1)
                            eax_14 = 1;

                        edi_3 u>>= 1;
                        bool cond:5_1 = !(*(&var_2c_1 + 4) & 1);
                        var_10_1 = eax_14;
                        int32_t eax_15 = *(&var_2c_1 + 4);
                        var_5_1 = ecx_2;
                        var_2c_1 = edi_3;

                        if (!cond:5_1)
                        {
                            edi_3 |= 0x80000000;
                            var_2c_1 = edi_3;
                        }

                        *(&var_2c_1 + 4) = eax_15 >> 1;
                        i = i_1;
                        i_1 -= 1;
                    } while (i != 1);
                    eax_12 = var_10_1;
                    var_5_1 = ecx_2;
                }

                uint128_t xmm0_16 = var_2c_1;

                if (eax_9)
                {
                    xmm0_16 ^= data_416fc0;
                    var_2c_1 = xmm0_16;
                    edi_3 = var_2c_1;
                }

                uint64_t var_1c_2 = xmm0_16;

                if (ecx_2 || eax_12)
                {
                    int32_t eax_17 = sub_40c5d0();

                    if (eax_17 > 0x200)
                        xmm0_16 = var_1c_2;
                    else
                    {
                        char eax_18;
                        bool cond:7_1;

                        if (eax_17 == 0x200)
                        {
                            eax_18 = eax_9 ^ 1;
                        label_407f14:
                            cond:7_1 = !eax_18;
                        label_407f16:

                            if (cond:7_1)
                                xmm0_16 = var_1c_2;
                            else
                            {
                            label_407f1b:
                                var_2c_1 = edi_3 + 1;
                                *(&var_2c_1 + 4) = *(&var_2c_1 + 4) + 0;
                                xmm0_16 = var_2c_1;
                            }
                        }
                        else if (!eax_17)
                        {
                            if (var_5_1)
                            {
                                if (var_10_1)
                                    goto label_407f1b;

                                cond:7_1 = !(var_2c_1 & 1);
                                goto label_407f16;
                            }

                            xmm0_16 = var_1c_2;
                        }
                        else
                        {
                            if (eax_17 == 0x100)
                            {
                                eax_18 = eax_9;
                                goto label_407f14;
                            }

                            xmm0_16 = var_1c_2;
                        }
                    }
                }

                ecx = arg1;
                edx = arg3;
                *arg2 = xmm0_16;
            }
            else
            {
                esi_3 = 1;
                ecx = arg1;
                edx = arg3;
                *arg2 = xmm0_14 * 0.0;
            }
        }

        edi_2 &= 0xfffffffd;
        int32_t esi_4 = -(esi_3);
        esi = (esi_4 - esi_4) & 0x10;
    }

    if (ecx & 0x10 && edx & 0x20)
    {
        esi |= 0x20;
        edi_2 &= 0xffffffef;
    }

    long double x87_r0;

    if (esi)
        __set_statfp(x87_r0, esi);
    int32_t result = 0;
    result = !edi_2;
    return result;
}

void sub_407f80(uint32_t arg1, int32_t* arg2, char arg3, int32_t arg4, int64_t* arg5, int32_t* arg6) __noreturn
{
    sub_407fb0(arg1, arg2, arg3, arg4, arg5, arg6, 0);
    /* no return */
}

int32_t __stdcall sub_407f9e(int32_t arg1 @ 0x1c) __pure
{
    return;
}

void sub_407fb0(uint32_t arg1, int32_t* arg2, char arg3, int32_t arg4, int64_t* arg5, int32_t* arg6, int32_t arg7) __noreturn
{
    *(arg1 + 4) = 0;
    int32_t edi;
    int32_t var_10 = edi;
    uint32_t dwExceptionCode = 0xc000000d;
    *(arg1 + 8) = 0;
    *(arg1 + 0xc) = 0;

    if (arg3 & 0x10)
    {
        uint32_t eax_3 = arg1;
        dwExceptionCode = 0xc000008f;
        *(eax_3 + 4) |= 1;
    }

    if (arg3 & 2)
    {
        uint32_t eax_4 = arg1;
        dwExceptionCode = 0xc0000093;
        *(eax_4 + 4) |= 2;
    }

    if (arg3 & 1)
    {
        uint32_t eax_5 = arg1;
        dwExceptionCode = 0xc0000091;
        *(eax_5 + 4) |= 4;
    }

    if (arg3 & 4)
    {
        uint32_t eax_6 = arg1;
        dwExceptionCode = 0xc000008e;
        *(eax_6 + 4) |= 8;
    }

    if (arg3 & 8)
    {
        uint32_t eax_7 = arg1;
        dwExceptionCode = 0xc0000090;
        *(eax_7 + 4) |= 0x10;
    }

    uint32_t edx = arg1;
    *(edx + 8) ^= (~(*arg2 << 4) ^ *(edx + 8)) & 0x10;
    uint32_t edx_1 = arg1;
    *(edx_1 + 8) ^= (~(*arg2 * 2) ^ *(edx_1 + 8)) & 8;
    uint32_t edx_2 = arg1;
    *(edx_2 + 8) ^= (~(*arg2 >> 1) ^ *(edx_2 + 8)) & 4;
    uint32_t edx_3 = arg1;
    *(edx_3 + 8) ^= (~(*arg2 >> 3) ^ *(edx_3 + 8)) & 2;
    uint32_t edx_4 = arg1;
    *(edx_4 + 8) ^= (~(*arg2 >> 5) ^ *(edx_4 + 8)) & 1;
    char eax_13 = sub_40c900();

    if (eax_13 & 1)
    {
        uint32_t ecx_21 = arg1;
        *(ecx_21 + 0xc) |= 0x10;
    }

    if (eax_13 & 4)
    {
        uint32_t eax_14 = arg1;
        *(eax_14 + 0xc) |= 8;
    }

    if (eax_13 & 8)
    {
        uint32_t eax_15 = arg1;
        *(eax_15 + 0xc) |= 4;
    }

    if (eax_13 & 0x10)
    {
        uint32_t eax_16 = arg1;
        *(eax_16 + 0xc) |= 2;
    }

    if (eax_13 & 0x20)
    {
        uint32_t eax_17 = arg1;
        *(eax_17 + 0xc) |= 1;
    }

    int32_t eax_19 = *arg2 & 0xc00;

    if (eax_19 == 0xc00)
    {
        uint32_t eax_27 = arg1;
        *eax_27 |= 3;
    }

    if (eax_19 == 0x800)
    {
        uint32_t ecx_23 = arg1;
        *ecx_23 = (*ecx_23 & 0xfffffffe) | 2;
    }
    else if (!eax_19)
    {
        uint32_t eax_23 = arg1;
        *eax_23 &= 0xfffffffc;
    }
    else if (eax_19 == 0x400)
    {
        uint32_t ecx_22 = arg1;
        *ecx_22 = (*ecx_22 & 0xfffffffd) | 1;
    }

    int32_t eax_29 = *arg2 & 0x300;
    uint32_t ecx_24;

    if (!eax_29)
    {
        ecx_24 = arg1;
        *ecx_24 = (*ecx_24 & 0xffffffeb) | 8;
    }
    else if (eax_29 == 0x200)
    {
        ecx_24 = arg1;
        *ecx_24 = (*ecx_24 & 0xffffffe7) | 4;
    }
    else if (eax_29 == 0x300)
    {
        uint32_t eax_30 = arg1;
        *eax_30 &= 0xffffffe3;
    }
    uint32_t edx_6 = arg1;
    *edx_6 ^= (arg4 << 5 ^ *edx_6) & 0x1ffe0;
    uint32_t eax_36 = arg1;
    *(eax_36 + 0x20) |= 1;

    if (!arg7)
    {
        uint32_t ecx_31 = arg1;
        *(ecx_31 + 0x20) = (*(ecx_31 + 0x20) & 0xffffffe3) | 2;
        *(arg1 + 0x10) = *arg5;
        uint32_t eax_48 = arg1;
        *(eax_48 + 0x60) |= 1;
        uint32_t ecx_32 = arg1;
        *(ecx_32 + 0x60) = (*(ecx_32 + 0x60) & 0xffffffe3) | 2;
        *(arg1 + 0x50) = *arg6;
    }
    else
    {
        uint32_t eax_37 = arg1;
        *(eax_37 + 0x20) &= 0xffffffe1;
        *(arg1 + 0x10) = *arg5;
        uint32_t eax_40 = arg1;
        *(eax_40 + 0x60) |= 1;
        uint32_t eax_41 = arg1;
        *(eax_41 + 0x60) &= 0xffffffe1;
        *(arg1 + 0x50) = *arg6;
    }

    sub_40c850();
    RaiseException(dwExceptionCode, 0, 1, &arg1);
    /* no return */
}

int32_t* __set_errno_from_matherr(int32_t arg1)
{
    int32_t* eax_3;

    if (arg1 == 1)
    {
        eax_3 = sub_40a844();
        *eax_3 = 0x21;
    }
    else
    {
        if (arg1 != 2)
            eax_3 = arg1 - 3;

        if (arg1 == 2 || arg1 == 3)
        {
            int32_t* eax_4 = sub_40a844();
            *eax_4 = 0x22;
            return eax_4;
        }
    }

    return eax_3;
}

long double sub_408320(int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4, int32_t arg5, int32_t arg6, int32_t arg7, int32_t arg8, int16_t arg9)
{
    int32_t eax = 0;
    int16_t x87control;

    while (true)
    {
        if (*((eax << 3) + &data_416e08) == arg2)
        {
            int32_t eax_6 = (&data_416e0c)[eax * 2];
            int32_t var_20_1 = eax_6;

            if (!eax_6)
                break;

            int32_t var_1c = arg3;
            int32_t var_18 = arg4;
            int32_t var_14 = arg5;
            int32_t var_10 = arg6;
            int32_t var_24 = arg1;
            int32_t var_8 = arg8;
            sub_40c870(x87control, arg9, 0xffff);

            if (!sub_4085b0(&var_24))
            {
                if (arg1 == 1)
                    *sub_40a844() = 0x21;
                else if (arg1 == 2 || arg1 == 3)
                    *sub_40a844() = 0x22;
            }

            return arg7;
        }

        eax += 1;

        if (eax >= 0x1d)
        {
            int32_t var_20 = 0;
            break;
        }
    }

    sub_40c870(x87control, arg9, 0xffff);

    if (arg1 == 1)
        *sub_40a844() = 0x21;
    else if (arg1 == 2 || arg1 == 3)
        *sub_40a844() = 0x22;

    return arg7;
}

int32_t __seh_filter_exe(int32_t arg1, int32_t arg2)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    int32_t edi;
    int32_t var_10 = edi;
    int32_t* eax = sub_409bc5();

    if (eax)
    {
        int32_t* i_1 = *eax;
        int32_t* i = i_1;

        if (i_1 != &i_1[0x24])
        {
            do
            {
                if (*i == arg1)
                {
                    if (i)
                    {
                        int32_t edi_3 = i[2];

                        if (edi_3)
                        {
                            if (edi_3 == 5)
                            {
                                i[2] = 0;
                                return 1;
                            }

                            if (edi_3 != 1)
                            {
                                int32_t eax_3 = eax[1];
                                eax[1] = arg2;

                                if (i[1] != 8)
                                {
                                    i[2] = 0;
                                    edi_3(i[1]);
                                }
                                else
                                {
                                    void* j = &i_1[9];

                                    for (void* eax_5 = j + 0x6c; j != eax_5; j += 0xc)
                                        *(j + 8) = 0;

                                    int32_t ebx_1 = eax[2];
                                    int32_t temp0_1 = *i;
                                    int32_t eax_6;

                                    if (temp0_1 > 0xc0000091)
                                    {
                                        if (*i == 0xc0000092)
                                        {
                                            eax_6 = 0x8a;
                                            eax[2] = eax_6;
                                        }
                                        else if (*i == 0xc0000093)
                                        {
                                            eax_6 = 0x85;
                                            eax[2] = eax_6;
                                        }
                                        else if (*i == 0xc00002b4)
                                        {
                                            eax_6 = 0x8e;
                                            eax[2] = eax_6;
                                        }
                                        else
                                        {
                                            eax_6 = ebx_1;

                                            if (*i == 0xc00002b5)
                                            {
                                                eax_6 = 0x8d;
                                                eax[2] = eax_6;
                                            }
                                        }
                                    }
                                    else if (temp0_1 == 0xc0000091)
                                    {
                                        eax_6 = 0x84;
                                        eax[2] = eax_6;
                                    }
                                    else if (*i == 0xc000008d)
                                    {
                                        eax_6 = 0x82;
                                        eax[2] = eax_6;
                                    }
                                    else if (*i == 0xc000008e)
                                    {
                                        eax_6 = 0x83;
                                        eax[2] = eax_6;
                                    }
                                    else if (*i == 0xc000008f)
                                    {
                                        eax_6 = 0x86;
                                        eax[2] = eax_6;
                                    }
                                    else
                                    {
                                        eax_6 = ebx_1;

                                        if (*i == 0xc0000090)
                                        {
                                            eax_6 = 0x81;
                                            eax[2] = eax_6;
                                        }
                                    }

                                    edi_3(8, eax_6);
                                    eax[2] = ebx_1;
                                }

                                eax[1] = eax_3;
                            }

                            return 0xffffffff;
                        }
                    }

                    break;
                }

                i = &i[3];
            } while (i != &i_1[0x24]);
        }
    }

    return 0;
}

int32_t sub_408565()
{
    return data_41eb78;
}

int32_t sub_40856b(int32_t arg1)
{
    data_41eb78 = arg1;
    return arg1;
}

int32_t ___acrt_has_user_matherr()
{
    int32_t result;
    result = RORD(data_41eb7c ^ __security_cookie, __security_cookie & 0x1f);
    return result;
}

int32_t sub_4085a0(int32_t arg1)
{
    data_41eb7c = arg1;
    return arg1;
}

int32_t sub_4085b0(int32_t arg1)
{
    int32_t esi_2 = RORD(data_41eb7c ^ __security_cookie, __security_cookie & 0x1f);

    if (esi_2)
        return esi_2(arg1);

    return 0;
}

int32_t sub_4085f0(int32_t arg1)
{
    int32_t result = RORD(arg1, (0x20 - (__security_cookie & 0x1f)) & 0x1f) ^ __security_cookie;
    data_41eb7c = result;
    return result;
}

int32_t common_configure_argv<char>(int32_t arg1)
{
    int32_t edi;
    int32_t var_14 = edi;

    if (!arg1)
        return 0;

    if (arg1 != 2 && arg1 != 1)
    {
        *sub_40a844() = 0x16;
        __invalid_parameter_noinfo();
        return 0x16;
    }

    ___acrt_initialize_multibyte();
    ___acrt_GetModuleFileNameA(nullptr, &data_41eb80, 0x104);
    data_41ef80 = &data_41eb80;
    char* ebx_1 = data_41ef90;

    if (!ebx_1 || !*ebx_1)
        ebx_1 = &data_41eb80;

    int32_t var_8 = 0;
    int32_t var_10 = 0;
    sub_408753(ebx_1, nullptr, nullptr, &var_8, &var_10);
    int32_t* eax_1 = ___acrt_allocate_buffer_for_argv(var_8, var_10, 1);
    int32_t result;
    int32_t result_1;

    if (eax_1)
    {
        sub_408753(ebx_1, eax_1, &eax_1[var_8], &var_8, &var_10);

        if (arg1 == 1)
        {
            int32_t eax_6 = var_8 - 1;
            data_41ef88 = eax_1;
            data_41ef84 = eax_6;
            result_1 = 0;
            goto label_4086eb;
        }

        int32_t* var_c;
        int32_t* var_20_3 = &var_c;
        int32_t* var_24_3 = eax_1;
        var_c = nullptr;
        int32_t result_2 = sub_40d84e();

        if (!result_2)
        {
            int32_t* edx_1 = var_c;
            int32_t ecx_2 = 0;
            int32_t* eax_8 = edx_1;

            if (*edx_1)
            {
                do
                {
                    eax_8 = &eax_8[1];
                    ecx_2 += 1;
                } while (*eax_8);
            }

            int32_t* var_20_4 = nullptr;
            data_41ef84 = ecx_2;
            var_c = nullptr;
            data_41ef88 = edx_1;
            __free_base(0);
            result_2 = 0;
        }
        else
            __free_base(var_c);

        var_c = nullptr;
        __free_base(eax_1);
        result = result_2;
    }
    else
    {
        result_1 = 0xc;
        *sub_40a844() = 0xc;
    label_4086eb:
        int32_t* var_20_5 = nullptr;
        __free_base(0);
        result = result_1;
    }
    return result;
}

int32_t* sub_408753(char* arg1, int32_t* arg2, char* arg3, int32_t* arg4, int32_t* arg5)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    char* esi = arg3;
    int32_t edi;
    int32_t var_14 = edi;
    *arg5 = 0;
    char* edi_1 = arg1;
    *arg4 = 1;

    if (arg2)
    {
        *arg2 = esi;
        arg2 = &arg2[1];
    }

    bool ecx_1 = false;
    *(&var_8 + 3) = 0;

    while (true)
    {
        char eax_2;

        if (*edi_1 != 0x22)
        {
            *arg5 += 1;

            if (esi)
            {
                *esi = *edi_1;
                esi = &esi[1];
            }

            eax_2 = *edi_1;
            edi_1 = &edi_1[1];
            *(&var_8 + 2) = eax_2;

            if (__ismbblead(eax_2))
            {
                *arg5 += 1;

                if (esi)
                {
                    *esi = *edi_1;
                    esi = &esi[1];
                }

                edi_1 = &edi_1[1];
            }

            eax_2 = *(&var_8 + 2);

            if (!eax_2)
            {
                edi_1 -= 1;
                break;
            }

            ecx_1 = *(&var_8 + 3);
        }
        else
        {
            eax_2 = 0x22;
            ecx_1 = !ecx_1;
            edi_1 = &edi_1[1];
            *(&var_8 + 3) = ecx_1;
        }

        if (!ecx_1)
        {
            if (eax_2 != 0x20 && eax_2 != 9)
                continue;

            if (!esi)
                break;

            esi[0xffffffff] = 0;
            break;
        }
    }

    *(&var_8 + 3) = 0;

    while (true)
    {
        char i = *edi_1;

        if (!i)
            break;

        while (i == 0x20 || i == 9)
        {
            edi_1 = &edi_1[1];
            i = *edi_1;
        }

        if (!i)
            break;

        if (arg2)
        {
            *arg2 = esi;
            arg2 = &arg2[1];
        }

        *arg4 += 1;

        while (true)
        {
            int32_t edx_1 = 1;
            uint32_t i_1 = 0;
            char ecx_4;

            while (true)
            {
                ecx_4 = *edi_1;

                if (ecx_4 != 0x5c)
                    break;

                edi_1 = &edi_1[1];
                i_1 += 1;
            }

            if (ecx_4 == 0x22)
            {
                if (!(i_1 & 1))
                {
                    ecx_4 = *(&var_8 + 3);

                    if (!ecx_4)
                    {
                        edx_1 = 0;
                        *(&var_8 + 3) = !ecx_4;
                    }
                    else if (edi_1[1] != 0x22)
                    {
                        edx_1 = 0;
                        *(&var_8 + 3) = !*(&var_8 + 3);
                    }
                    else
                        edi_1 = &edi_1[1];
                }

                i_1 u>>= 1;
            }

            while (i_1)
            {
                i_1 -= 1;

                if (esi)
                {
                    *esi = 0x5c;
                    esi = &esi[1];
                }

                *arg5 += 1;
            }

            char eax_7 = *edi_1;

            if (!eax_7)
                break;

            if (!*(&var_8 + 3))
            {
                if (eax_7 == 0x20)
                    break;

                if (eax_7 == 9)
                    break;
            }

            if (edx_1)
            {
                if (esi)
                {
                    *esi = eax_7;
                    esi = &esi[1];
                }

                if (__ismbblead(*edi_1))
                {
                    edi_1 = &edi_1[1];
                    *arg5 += 1;

                    if (esi)
                    {
                        *esi = *edi_1;
                        esi = &esi[1];
                    }
                }

                *arg5 += 1;
            }

            edi_1 = &edi_1[1];
        }

        if (esi)
        {
            *esi = 0;
            esi = &esi[1];
        }

        *arg5 += 1;
    }

    if (arg2)
        *arg2 = 0;

    *arg4 += 1;
    return arg4;
}

int32_t ___acrt_allocate_buffer_for_argv(int32_t arg1, int32_t arg2, int32_t arg3)
{
    if (arg1 < 0x3fffffff && arg2 < COMBINE(0, 0xffffffff) / arg3)
    {
        int32_t ecx_2 = arg2 * arg3;
        int32_t esi_1 = arg1 << 2;

        if (~esi_1 > ecx_2)
        {
            int32_t result = sub_40cf40(esi_1 + ecx_2, 1);
            __free_base(0);
            return result;
        }
    }

    return 0;
}

int32_t sub_408914()
{
    /* tailcall */
    return common_configure_argv<char>();
}

int32_t common_initialize_environment_nolock<char>()
{
    if (data_41ec88)
        return 0;

    ___acrt_initialize_multibyte();
    PWSTR eax_1 = ___dcrt_get_narrow_environment_from_os();

    if (!eax_1)
    {
        __free_base(eax_1);
        return 0xffffffff;
    }

    char** eax_3 = sub_408979(eax_1);
    int32_t result;

    if (eax_3)
    {
        data_41ec94 = eax_3;
        result = 0;
        data_41ec88 = eax_3;
    }
    else
        result = 0xffffffff;

    __free_base(0);
    __free_base(eax_1);
    return result;
}

char** sub_408979(char* arg1)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    int32_t var_c = ecx;
    char* ebx = arg1;
    int32_t ecx_1 = 0;
    int32_t edi;
    int32_t var_18 = edi;
    char* esi = ebx;
    char edx = *ebx;
    int32_t eax_1;

    while (true)
    {
        eax_1 = ecx_1 + 1;

        if (!edx)
            break;

        char* edx_1 = esi;

        if (edx == 0x3d)
            eax_1 = ecx_1;

        ecx_1 = eax_1;
        char i;

        do
        {
            i = *edx_1;
            edx_1 = &edx_1[1];
        } while (i);
        esi = &esi[1] + edx_1 - &edx_1[1];
        edx = *esi;
    }

    char** result_3 = sub_40cf40(eax_1, 4);
    char** result_1 = result_3;
    char** result;

    if (result_1)
    {
        char** result_2 = result_1;

        while (true)
        {
            char edx_3 = *ebx;

            if (!edx_3)
                break;

            char* ecx_3 = ebx;
            char i_1;

            do
            {
                i_1 = *ecx_3;
                ecx_3 = &ecx_3[1];
            } while (i_1);
            result_3 = ecx_3 - &ecx_3[1] + 1;

            if (edx_3 != 0x3d)
            {
                char* eax_2 = sub_40cf40(result_3, 1);

                if (!eax_2)
                {
                    sub_408a5e(result_1);
                    __free_base(0);
                    __free_base(0);
                    return nullptr;
                }

                if (sub_409620(eax_2, result_3, ebx))
                {
                    int32_t var_2c;
                    __builtin_memset(&var_2c, 0, 0x14);
                    sub_40a6d6();
                    /* no return */
                }

                *result_2 = eax_2;
                result_2 = &result_2[1];
                __free_base(0);
            }

            ebx += result_3;
        }

        char** var_1c_1 = nullptr;
        __free_base(0);
        result = result_1;
    }
    else
    {
        __free_base(result_3);
        result = nullptr;
    }

    return result;
}

void sub_408a5e(int32_t* arg1)
{
    if (!arg1)
        return;

    int32_t i = *arg1;
    int32_t edi;
    int32_t var_c_1 = edi;
    int32_t* edi_1 = arg1;

    for (; i; i = *edi_1)
    {
        __free_base(i);
        edi_1 = &edi_1[1];
    }

    __free_base(arg1);
}

int32_t* sub_408a8d(int32_t* arg1)
{
    int32_t* result = *arg1;

    if (result != data_41ec94)
        result = sub_408a5e(result);

    return result;
}

int32_t* sub_408aa8(int32_t* arg1)
{
    int32_t* result = *arg1;

    if (result != data_41ec90)
        result = sub_408a5e(result);

    return result;
}

int32_t ___dcrt_uninitialize_environments_nolock()
{
    int32_t __saved_ebp_2 = 0;
    int32_t (* var_c)(void* arg1 @ 0x8) = sub_415694;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t __saved_ebp;
    int32_t var_20 = __security_cookie ^ &__saved_ebp;
    void* const var_24 = &data_408acf;
    int32_t var_8_2 = 0xffffffff;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t var_8 = 0;
    sub_408a8d(&data_41ec88);
    int32_t var_8_1 = 1;
    sub_408aa8(0x41ec8c);
    sub_408a5e(data_41ec94);
    int32_t result = sub_408a5e(data_41ec90);
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_1 = &data_408b0e;
    return result;
}

int32_t j_common_initialize_environment_nolock<char>()
{
    /* tailcall */
    return common_initialize_environment_nolock<char>();
}

char* sub_408b19()
{
    ___acrt_initialize_multibyte();
    char* result_1 = data_41ef90;
    char* result = &data_41ec98;

    if (result_1)
        result = result_1;

    bool ebx = false;

    while (true)
    {
        char i = *result;

        if (i <= 0x20)
        {
            if (!i)
                return result;

            if (!ebx)
            {
                while (i <= 0x20)
                {
                    result = &result[1];
                    i = *result;

                    if (!i)
                        break;
                }

                return result;
            }
        }

        if (i == 0x22)
            ebx = !ebx;

        char* result_2 = &result[1];

        if (!__ismbblead(i))
            result_2 = result;

        result = &result_2[1];
    }
}

void __initterm(int32_t* arg1, int32_t arg2)
{
    int32_t* esi = arg1;

    if (esi == arg2)
        return;

    int32_t edi;
    int32_t var_c_1 = edi;

    do
    {
        int32_t edi_1 = *esi;

        if (edi_1)
            edi_1();

        esi = &esi[1];
    } while (esi != arg2);
}

int32_t __initterm_e(int32_t* arg1, int32_t arg2)
{
    int32_t* i = arg1;
    int32_t edi;
    int32_t var_c = edi;

    for (; i != arg2; i = &i[1])
    {
        int32_t edi_1 = *i;

        if (edi_1)
        {
            int32_t result = edi_1();

            if (result)
                return result;
        }
    }

    return 0;
}

int32_t __stdcall __crt_seh_guarded_call<void>::operator()<class <lambda_03b1d95aef87969028cfba75ccab2455>,class <lambda_6e4b09c48022b2350581041d5f6b0c4c>&,class <lambda_22bdf7517842c4b3e53723af5aa32b9e> >(int32_t* arg1, int32_t* arg2)
{
    int32_t __saved_ebp_1 = 8;
    int32_t var_8 = 0x41cbd8;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41cbd8 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_2c = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_2c;
    void* const var_30_1 = &data_408bd6;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    ___acrt_lock(*arg1);
    int32_t var_8_1 = 0;
    <lambda_6e4b09c48022b2350581041d5f6b0c4c>::operator()(arg2);
    int32_t var_8_2 = 0xfffffffe;
    int32_t result = $LN15(&__saved_ebp);
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t $LN15(void* arg1 @ ebp)
{
    return ___acrt_unlock(**(arg1 + 0x10));
}

int32_t sub_408c17(int32_t arg1)
{
    return RORD(arg1 ^ __security_cookie, __security_cookie & 0x1f);
}

int32_t sub_408c32(int32_t arg1)
{
    return RORD(arg1, (0x20 - (__security_cookie & 0x1f)) & 0x1f) ^ __security_cookie;
}

struct _EXCEPTION_REGISTRATION_RECORD** __fastcall <lambda_6e4b09c48022b2350581041d5f6b0c4c>::operator()(int32_t* arg1)
{
    int32_t __saved_ebp_1 = 0x14;
    int32_t var_8 = 0x41cbb8;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_2 = __security_cookie;
    int32_t var_8_3 = 0x41cbb8 ^ __security_cookie_2;
    int32_t __saved_ebp;
    int32_t var_38 = __security_cookie_2 ^ &__saved_ebp;
    int32_t* var_1c = &var_38;
    void* const var_3c_2 = &data_408c5d;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    struct _EXCEPTION_REGISTRATION_RECORD** result = &ExceptionList;
    fsbase->NtTib.ExceptionList = &ExceptionList;

    if (!data_41eca4)
    {
        data_41ec9c = 1;
        int32_t var_8_1 = 0;
        int32_t eax_1 = **arg1;
        int32_t var_3c_1;

        if (!eax_1)
        {
            uint32_t __security_cookie_1 = __security_cookie;
            uint32_t __security_cookie_3 = __security_cookie_1;
            int32_t ecx = data_41eca0;

            if (ecx != __security_cookie_1)
                sub_408c17(ecx)(0, 0, 0);

            var_3c_1 = 0x41ecb4;
            __execute_onexit_table();
        }
        else if (eax_1 == 1)
        {
            var_3c_1 = 0x41ecc0;
            __execute_onexit_table();
        }
        int32_t var_8_2 = 0xfffffffe;

        if (!**arg1)
            __initterm(0x4161f4, 0x416204);

        __initterm(0x416208, 0x41620c);
        result = arg1[1];

        if (!*result)
        {
            data_41eca4 = 1;
            result = arg1[2];
            *result = 1;
        }
    }

    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t sub_408d15(void* arg1 @ ebp)
{
    int32_t eax_1 = ***(arg1 - 0x14);
    *(arg1 - 0x24) = eax_1;
    int32_t ecx = 0;
    ecx = eax_1 == 0xe06d7363;
    *(arg1 - 0x1c) = ecx;
    return *(arg1 - 0x1c);
}

void sub_408d30() __noreturn
{
    _terminate();
    /* no return */
}

int32_t sub_408d39(uint32_t arg1)
{
    int32_t var_8 = 0xffffffff;
    int32_t (* var_c)(void* arg1 @ 0x8) = sub_4156b1;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t __saved_ebp;
    int32_t var_2c = __security_cookie ^ &__saved_ebp;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t arg_c;

    if (!arg_c)
    {
        HMODULE eax_3;
        HMODULE ecx_1;
        int32_t edx_1;
        eax_3 = sub_403480();

        if (eax_3)
            try_cor_exit_process(eax_3, edx_1, ecx_1, arg1);
    }

    char var_11 = 0;
    void arg_8;
    void* var_28 = &arg_8;
    int32_t* var_24 = &arg_c;
    char* var_20 = &var_11;
    int32_t var_8_1 = 0;
    int32_t var_18 = 2;
    int32_t var_1c = 2;
    int32_t* var_30_2 = &var_18;
    int32_t result;
    int32_t ecx_3;
    result = __crt_seh_guarded_call<void>::operator()<class <lambda_03b1d95aef87969028cfba75ccab2455>,class <lambda_6e4b09c48022b2350581041d5f6b0c4c>&,class <lambda_22bdf7517842c4b3e53723af5aa32b9e> >(
        &var_1c, &var_28);

    if (!arg_c)
    {
        result = ___acrt_get_process_end_policy(ecx_3);

        if (result != 1)
        {
            result = sub_40e608();
            char temp0_1 = result;
            result = -(result);
            result = result - result;
            result += 1;
            var_18 = result;
        }
        else
            var_18 = 0;

        if (!arg_c)
        {
            sub_408df7(arg1, var_18);
            /* no return */
        }
    }

    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

void sub_408df7(uint32_t arg1, char arg2) __noreturn
{
    if (arg2)
    {
        TerminateProcess(GetCurrentProcess(), arg1);
        /* no return */
    }

    int32_t eax;
    HMODULE ecx;
    int32_t edx;
    try_cor_exit_process(eax, edx, ecx, arg1);
    ExitProcess(arg1);
    /* no return */
}

BOOL __convention("regparm") try_cor_exit_process(int32_t arg1, int32_t arg2, HMODULE arg3, int32_t arg4)
{
    int32_t var_8 = 0xffffffff;
    int32_t (* var_c)(void* arg1 @ 0x8) = sub_4156ce;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    HMODULE var_14 = arg3;
    int32_t __saved_ebp;
    int32_t var_1c = __security_cookie ^ &__saved_ebp;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    var_14 = nullptr;
    BOOL result = GetModuleHandleExW(0, u"mscoree.dll", &var_14);

    if (result)
    {
        result = GetProcAddress(var_14, "CorExitProcess");

        if (result)
            result = result(arg4);
    }

    if (var_14)
        result = FreeLibrary(var_14);

    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t sub_408ea7(int32_t arg1)
{
    data_41eca0 = arg1;
    return arg1;
}

int32_t sub_408eb6()
{
    int32_t var_4 = 1;
    int32_t var_8 = 2;
    return sub_408d39(0);
}

int32_t sub_408ec5()
{
    int32_t var_4 = 1;
    int32_t var_8 = 0;
    return sub_408d39(0);
}

int32_t sub_408ed4(uint32_t arg1)
{
    int32_t var_8 = 0;
    int32_t var_c = 2;
    return sub_408d39(arg1);
}

int32_t sub_408eea(int32_t arg1)
{
    if (data_41eca0 != __security_cookie)
        /* tailcall */
        return _terminate();

    int32_t result = sub_408c32(arg1);
    data_41eca0 = result;
    return result;
}

int32_t sub_408f10(uint32_t arg1)
{
    int32_t var_8 = 0;
    int32_t var_c = 0;
    return sub_408d39(arg1);
}

int32_t sub_408f26(int32_t arg1)
{
    if (arg1 == 0x4000 || arg1 == 0x8000 || arg1 == 0x10000)
    {
        data_41f104 = arg1;
        return 0;
    }

    *sub_40a844() = 0x16;
    __invalid_parameter_noinfo();
    return 0x16;
}

int32_t __stdcall __crt_seh_guarded_call<void>::operator()<class <lambda_e5124f882df8998aaf41531e079ba474>,class <lambda_3e16ef9562a7dcce91392c22ab16ea36>&,class <lambda_e25ca0880e6ef98be67edffd8c599615> >(int32_t* arg1)
{
    int32_t __saved_ebp_1 = 0xc;
    int32_t var_8 = 0x41cbf8;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41cbf8 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_1 = &data_408f6f;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    ___acrt_lock(*arg1);
    int32_t var_8_1 = 0;
    int32_t* esi = &data_41ed00;

    while (true)
    {
        int32_t* var_20_1 = esi;

        if (esi == 0x41ed04)
            break;

        if (*esi != &data_41e290)
            *esi = __updatetlocinfoEx_nolock(esi, &data_41e290);

        esi = &esi[1];
    }

    int32_t var_8_2 = 0xfffffffe;
    int32_t result = $LN29(&__saved_ebp);
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t $LN29(void* arg1 @ ebp)
{
    return ___acrt_unlock(**(arg1 + 0x10));
}

int32_t sub_408fd1()
{
    int32_t result = data_41eca8;
    data_41eca8 = 1;
    return result;
}

int32_t ___acrt_uninitialize_locale()
{
    int32_t var_c = 4;
    int32_t var_10 = 4;
    int32_t* var_14 = &var_c;
    void var_5;
    void* var_18 = &var_5;
    return __crt_seh_guarded_call<void>::operator()<class <lambda_e5124f882df8998aaf41531e079ba474>,class <lambda_3e16ef9562a7dcce91392c22ab16ea36>&,class <lambda_e25ca0880e6ef98be67edffd8c599615> >(
        &var_10);
}

int32_t __configthreadlocale(int32_t arg1)
{
    int32_t* eax = sub_409b74();
    int32_t eax_1 = 0;
    int32_t ecx = eax[0xd4];
    eax_1 = !(ecx & 2);

    if (arg1 == 0xffffffff)
        data_41e8d0 = 0xffffffff;
    else if (arg1)
    {
        int32_t ecx_1;

        if (arg1 == 1)
            ecx_1 = ecx | 2;
        else
        {
            if (arg1 != 2)
            {
                *sub_40a844() = 0x16;
                __invalid_parameter_noinfo();
                return 0xffffffff;
            }

            ecx_1 = ecx & 0xfffffffd;
        }

        eax[0xd4] = ecx_1;
    }

    return eax_1 + 1;
}

int32_t sub_409070()
{
    return data_41ecac;
}

int32_t __set_new_mode(int32_t arg1)
{
    if (arg1 && arg1 != 1)
    {
        *sub_40a844() = 0x16;
        __invalid_parameter_noinfo();
        return 0xffffffff;
    }

    int32_t result = data_41ecac;
    data_41ecac = arg1;
    return result;
}

int32_t sub_4090af() __pure
{
    return &data_41ecb0;
}

int32_t __stdcall sub_4090b5(int32_t* arg1, int32_t* arg2)
{
    int32_t __saved_ebp_1 = 0xc;
    int32_t var_8 = 0x41cc60;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41cc60 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_1 = &data_4090c1;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t var_20 = 0;
    ___acrt_lock(*arg1);
    int32_t var_8_1 = 0;
    int32_t result = sub_40927e(arg2);
    int32_t result_1 = result;
    int32_t var_8_2 = 0xfffffffe;
    $LN7(&__saved_ebp);
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t $LN7(void* arg1 @ ebp)
{
    return ___acrt_unlock(**(arg1 + 0x10));
}

int32_t __stdcall sub_409110(int32_t* arg1, int32_t* arg2)
{
    int32_t __saved_ebp_1 = 0xc;
    int32_t var_8 = 0x41cc40;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41cc40 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_1 = &data_40911c;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t var_20 = 0;
    ___acrt_lock(*arg1);
    int32_t var_8_1 = 0;
    int32_t result = sub_40916b(arg2);
    int32_t result_1 = result;
    int32_t var_8_2 = 0xfffffffe;
    $LN7(&__saved_ebp);
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t $LN7(void* arg1 @ ebp)
{
    return ___acrt_unlock(**(arg1 + 0x10));
}

int32_t __fastcall sub_40916b(int32_t* arg1)
{
    int32_t edi;
    int32_t var_1c = edi;
    int32_t* esi = **arg1;

    if (esi)
    {
        uint32_t __security_cookie_1 = __security_cookie;
        char ecx_1 = __security_cookie_1 & 0x1f;
        int32_t edx_3 = RORD(*esi ^ __security_cookie_1, ecx_1 & 0x1f);
        int32_t ebx_3 = RORD(esi[1] ^ __security_cookie_1, ecx_1 & 0x1f);
        int32_t esi_3 = RORD(esi[2] ^ __security_cookie_1, ecx_1 & 0x1f);
        int32_t var_8_1 = edx_3;

        if (ebx_3 != esi_3)
        {
        label_409245:
            *ebx_3 = sub_408c32(*arg1[1]);
            ***arg1 = sub_408c32(var_8_1);
            *(**arg1 + 4) = sub_408c32(ebx_3 + 4);
            *(**arg1 + 8) = sub_408c32(esi_3);
            return 0;
        }

        int32_t esi_5 = (esi_3 - edx_3) >> 2;
        int32_t edi_2 = esi_5;

        if (esi_5 > 0x200)
            edi_2 = 0x200;

        int32_t edi_3 = edi_2 + esi_5;

        if (edi_2 == -(esi_5))
            edi_3 = 0x20;

        if (edi_3 < esi_5)
            goto label_4091ee;

        int32_t ebx_4 = __recalloc_base(edx_3, edi_3, 4);
        int32_t var_c_1 = ebx_4;
        __free_base(0);

        if (ebx_4)
        {
        label_40920e:
            var_8_1 = ebx_4;
            ebx_3 = ebx_4 + (esi_5 << 2);
            esi_3 = var_c_1 + (edi_3 << 2);
            uint32_t ecx_5 = (esi_3 - ebx_3 + 3) >> 2;

            if (ebx_3 > esi_3)
                ecx_5 = 0;

            int32_t ecx_6;
            int32_t edi_5;

            if (ecx_5)
                edi_5 = __memfill_u32(ebx_3, __security_cookie, ecx_5);
            goto label_409245;
        }

        edx_3 = var_8_1;
    label_4091ee:
        edi_3 = esi_5 + 4;
        int32_t eax_2 = __recalloc_base(edx_3, edi_3, 4);
        ebx_4 = eax_2;
        var_c_1 = eax_2;
        __free_base(0);

        if (ebx_4)
            goto label_40920e;
    }

    return 0xffffffff;
}

int32_t __fastcall sub_40927e(int32_t* arg1)
{
    int32_t* ebx = arg1;
    int32_t edi;
    int32_t var_20 = edi;
    int32_t* var_18 = ebx;
    int32_t* edi_1 = **ebx;

    if (!edi_1)
        return 0xffffffff;

    uint32_t __security_cookie_1 = __security_cookie;
    char ecx_1 = __security_cookie_1 & 0x1f;
    int32_t esi_3 = RORD(*edi_1 ^ __security_cookie_1, ecx_1 & 0x1f);
    int32_t edi_4 = RORD(edi_1[1] ^ __security_cookie_1, ecx_1 & 0x1f);

    if (esi_3 && esi_3 != 0xffffffff)
    {
        uint32_t __security_cookie_2 = __security_cookie_1;
        int32_t var_10_1 = edi_4;

        while (true)
        {
            edi_4 -= 4;

            if (edi_4 < esi_3)
                break;

            int32_t eax_2 = *edi_4;

            if (eax_2 != __security_cookie_2)
            {
                *edi_4 = __security_cookie_2;
                RORD(eax_2 ^ __security_cookie_1, ecx_1 & 0x1f)();
                __security_cookie_1 = __security_cookie;
                ecx_1 = __security_cookie_1 & 0x1f;
                int32_t* eax_6 = **ebx;
                int32_t ebx_3 = RORD(*eax_6 ^ __security_cookie_1, ecx_1 & 0x1f);
                int32_t eax_9 = RORD(eax_6[1] ^ __security_cookie_1, ecx_1 & 0x1f);
                ebx = var_18;

                if (ebx_3 == esi_3 && eax_9 == var_10_1)
                    continue;

                esi_3 = ebx_3;
                edi_4 = eax_9;
                var_10_1 = eax_9;
            }
        }

        if (esi_3 != 0xffffffff)
        {
            __free_base(esi_3);
            __security_cookie_1 = __security_cookie;
        }

        ***ebx = __security_cookie_1;
        *(**ebx + 4) = __security_cookie_1;
        *(**ebx + 8) = __security_cookie_1;
    }

    return 0;
}

int32_t sub_409358(int32_t arg1)
{
    int32_t var_8 = arg1;
    int32_t var_c = 0x41ecb4;
    return __register_onexit_function();
}

int32_t __execute_onexit_table()
{
    int32_t __saved_ebp_2 = 0x10;
    int32_t (* var_c)(void* arg1 @ 0x8) = sub_4156eb;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie ^ &__saved_ebp;
    void* const var_34_2 = &data_40937a;
    int32_t var_8_1 = 0xffffffff;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    void arg_4;
    void* var_1c = &arg_4;
    int32_t var_8 = 0;
    int32_t var_34 = 2;
    int32_t var_18 = 2;
    int32_t var_20 = 2;
    int32_t* var_34_1 = &var_18;
    int32_t result = sub_4090b5(&var_20, &var_1c);
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_1 = &data_4093a6;
    return result;
}

int32_t __initialize_onexit_table(int32_t* arg1)
{
    if (!arg1)
        return 0xffffffff;

    if (*arg1 == arg1[2])
    {
        uint32_t __security_cookie_1 = __security_cookie;
        *arg1 = __security_cookie_1;
        arg1[1] = __security_cookie_1;
        arg1[2] = __security_cookie_1;
    }

    return 0;
}

int32_t __register_onexit_function()
{
    void arg_4;
    void* var_18 = &arg_4;
    void arg_8;
    void* var_14 = &arg_8;
    int32_t var_c = 2;
    int32_t var_10 = 2;
    int32_t* var_1c = &var_c;
    return sub_409110(&var_10, &var_18);
}

int32_t sub_409408()
{
    data_41ed00 = &data_41e290;
    int32_t result;
    result = 1;
    return result;
}

int32_t _initialize_c()
{
    __initialize_onexit_table(0x41ecb4);
    int32_t result = __initialize_onexit_table(0x41ecc0);
    result = 1;
    return result;
}

int32_t _uninitialize_environment()
{
    int32_t result = ___dcrt_uninitialize_environments_nolock();
    result = 1;
    return result;
}

int32_t _initialize_pointers()
{
    uint32_t __security_cookie_1 = __security_cookie;
    sub_40a603(__security_cookie_1);
    sub_40f220(__security_cookie_1);
    ___acrt_initialize_signal_handlers(__security_cookie_1);
    sub_4085a0(__security_cookie_1);
    int32_t result = sub_408ea7(__security_cookie_1);
    result = 1;
    return result;
}

int32_t _uninitialize_vcruntime()
{
    return ___vcrt_uninitialize(0);
}

int32_t* _uninitialize_allocated_memory()
{
    int32_t ecx;
    int32_t var_8 = ecx;
    int32_t* result = sub_4094d5(&data_41ef74);
    result = 1;
    return result;
}

int32_t sub_409487()
{
    __free_base(data_41ecf8);
    int32_t var_c = data_41ecfc;
    data_41ecf8 = 0;
    __free_base(var_c);
    int32_t var_10 = data_41ef88;
    data_41ecfc = 0;
    __free_base(var_10);
    int32_t var_14 = data_41ef8c;
    data_41ef88 = 0;
    int32_t result = __free_base(var_14);
    data_41ef8c = 0;
    result = 1;
    return result;
}

int32_t* __stdcall sub_4094d5(int32_t* arg1)
{
    int32_t* result = *arg1;
    bool cond:0 = *result != 1;
    *result;
    *result -= 1;

    if (!cond:0)
    {
        int32_t edi;
        int32_t var_c_1 = edi;

        if (*arg1 != 0x41e358)
        {
            result = __free_base(*arg1);
            *arg1 = 0x41e358;
        }
    }

    return result;
}

void* ___acrt_initialize()
{
    return ___acrt_execute_initializers(&data_417098, 0x417118);
}

int32_t ___acrt_uninitialize(char arg1)
{
    if (!arg1)
        return ___acrt_execute_uninitializers(&data_417098, 0x417118);

    int32_t result;

    if (data_41ecf0)
        result = sub_40f8cc();

    result = 1;
    return result;
}

int32_t sub_409550(int32_t* arg1, int32_t arg2, int32_t arg3)
{
    int32_t ecx_1 = arg3 & 0xfff7ffff;
    int32_t mxcsr;
    int16_t x87control;

    if (!(arg2 & ecx_1 & 0xfcf0fce0))
    {
        if (!arg1)
        {
            sub_40fad0(mxcsr, x87control, arg2, ecx_1);
            return 0;
        }

        *arg1 = sub_40fad0(mxcsr, x87control, arg2, ecx_1);
        return 0;
    }

    if (arg1)
        *arg1 = sub_40fad0(mxcsr, x87control, 0, 0);

    *sub_40a844() = 0x16;
    __invalid_parameter_noinfo();
    return 0x16;
}

void _terminate() __noreturn
{
    int32_t var_4 = 8;
    int32_t var_8 = 0x41cc80;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t ebp;
    var_4 = ebp;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41cc80 ^ __security_cookie_1;
    int32_t var_2c = __security_cookie_1 ^ &var_4;
    int32_t* var_1c = &var_2c;
    void* const var_30 = &data_4095c8;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t esi = sub_409b74()[3];

    if (esi)
    {
        int32_t var_8_1 = 0;
        esi();
        int32_t var_8_2 = 0xfffffffe;
    }

    sub_4096af();
    /* no return */
}

int32_t sub_4095e4() __pure
{
    return 1;
}

void j___free_base(int32_t arg1)
{
    /* tailcall */
    return __free_base(arg1);
}

int32_t sub_409610()
{
    /* tailcall */
    return sub_40a8b0();
}

int32_t sub_409620(char* arg1, int32_t arg2, int32_t arg3)
{
    int32_t edi;
    int32_t var_8 = edi;

    if (arg1)
    {
        int32_t edx_1 = arg2;

        if (edx_1)
        {
            if (!arg3)
            {
                *arg1 = 0;
                *sub_40a844() = 0x16;
                __invalid_parameter_noinfo();
                return arg3 + 0x16;
            }

            char* ecx = arg1;

            while (true)
            {
                char eax_3 = *(arg3 - arg1 + ecx);
                ecx = &ecx[1];
                ecx[0xffffffff] = eax_3;

                if (!eax_3)
                    break;

                int32_t temp0_1 = edx_1;
                edx_1 -= 1;

                if (temp0_1 == 1)
                {
                    if (edx_1)
                        break;

                    *arg1 = edx_1;
                    *sub_40a844() = 0x22;
                    __invalid_parameter_noinfo();
                    return 0x22;
                }
            }

            return 0;
        }
    }

    *sub_40a844() = 0x16;
    __invalid_parameter_noinfo();
    return 0x16;
}

void sub_4096af() __noreturn
{
    if (___acrt_get_sigabrt_handler())
        sub_40f434(0x16);

    if (data_41e1c0 & 2)
    {
        if (IsProcessorFeaturePresent(PF_FASTFAIL_AVAILABLE))
            trap(0xd);

        sub_40a4ca(3, 0x40000015, 1);
    }

    sub_408ed4(3);
    breakpoint();
}

int32_t sub_409700()
{
    /* tailcall */
    return sub_40cf40();
}

int32_t _strncmp(int32_t arg1, char* arg2, int32_t arg3)
{
    char* edx = arg2;
    int32_t ebx = arg3;

    if (!(ebx & 0xffffffff))
        return 0;

    int32_t* ecx_1 = arg1 - edx;

    if (edx & 3)
        goto label_409730;

    while (true)
    {
        if (((ecx_1 + edx) & 0xfff) <= 0xffc)
        {
            int32_t eax_4 = *(ecx_1 + edx);

            if (eax_4 == *edx)
            {
                int32_t temp1_1 = ebx;
                ebx -= 4;

                if (temp1_1 <= 4)
                    return 0;

                edx = &edx[4];

                if (~eax_4 & (eax_4 - 0x1010101) & 0x80808080)
                    return 0;

                continue;
            }
        }

    label_409730:
        uint32_t eax_1 = *(ecx_1 + edx);
        char temp0_1 = *edx;

        if (eax_1 != temp0_1)
            return (eax_1 - eax_1) | 1;

        if (!eax_1)
            return 0;

        edx = &edx[1];
        int32_t temp2_1 = ebx;
        ebx -= 1;

        if (temp2_1 <= 1)
            return 0;

        if (edx & 3)
            break;
    }
}

int32_t sub_409788()
{
    /* tailcall */
    return sub_4033b0();
}

int32_t __stdcall __crt_seh_guarded_call<void>::operator()<class <lambda_15ade71b0218206bbe3333a0c9b79046>,class <lambda_da44e0f8b0f19ba52fefafb335991732>&,class <lambda_207f2d024fc103971653565357d6cd41> >(int32_t* arg1, int32_t* arg2)
{
    int32_t __saved_ebp_1 = 8;
    int32_t var_8 = 0x41cca0;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41cca0 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_2c = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_2c;
    void* const var_30_1 = &data_40979a;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    ___acrt_lock(*arg1);
    int32_t var_8_1 = 0;
    int32_t* eax_4 = *(**arg2 + 0x48);
    *eax_4 += 1;
    int32_t var_8_2 = 0xfffffffe;
    int32_t result = $LN17(&__saved_ebp);
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t $LN17(void* arg1 @ ebp)
{
    return ___acrt_unlock(**(arg1 + 0x10));
}

int32_t __stdcall __crt_seh_guarded_call<void>::operator()<class <lambda_38edbb1296d33220d7e4dd0ed76b244a>,class <lambda_5ce1d447e08cb34b2473517608e21441>&,class <lambda_fb385d3da700c9147fc39e65dd577a8c> >(int32_t* arg1, int32_t* arg2)
{
    int32_t __saved_ebp_1 = 8;
    int32_t var_8 = 0x41cce0;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41cce0 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_2c = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_2c;
    void* const var_30_2 = &data_4097ec;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    ___acrt_lock(*arg1);
    int32_t var_8_1 = 0;
    int32_t* ecx = *(**arg2 + 0x48);

    if (ecx)
    {
        bool cond:0_1 = *ecx != 1;
        *ecx;
        *ecx -= 1;

        if (!cond:0_1 && ecx != 0x41e358)
            __free_base(ecx);
    }

    int32_t var_8_2 = 0xfffffffe;
    int32_t result = $LN20(&__saved_ebp);
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t $LN20(void* arg1 @ ebp)
{
    return ___acrt_unlock(**(arg1 + 0x10));
}

int32_t __stdcall __crt_seh_guarded_call<void>::operator()<class <lambda_6affb1475c98b40b75cdec977db92e3c>,class <lambda_b8d4b9c228a6ecc3f80208dbb4b4a104>&,class <lambda_608742c3c92a14382c1684fc64f96c88> >(int32_t* arg1, int32_t* arg2)
{
    int32_t __saved_ebp_1 = 8;
    int32_t var_8 = 0x41cd00;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41cd00 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_2c = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_2c;
    void* const var_30_1 = &data_409857;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    ___acrt_lock(*arg1);
    int32_t var_8_1 = 0;
    replace_current_thread_locale_nolock(**arg2, nullptr);
    int32_t var_8_2 = 0xfffffffe;
    int32_t result = $LN17(&__saved_ebp);
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t $LN17(void* arg1 @ ebp)
{
    return ___acrt_unlock(**(arg1 + 0x10));
}

int32_t __stdcall __crt_seh_guarded_call<void>::operator()<class <lambda_a7e850c220f1c8d1e6efeecdedd162c6>,class <lambda_46720907175c18b6c9d2717bc0d2d362>&,class <lambda_9048902d66e8d99359bc9897bbb930a8> >(int32_t* arg1, int32_t* arg2)
{
    int32_t __saved_ebp_1 = 8;
    int32_t var_8 = 0x41ccc0;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41ccc0 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_2c = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_2c;
    void* const var_30_2 = &data_4098ac;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    ___acrt_lock(*arg1);
    int32_t var_8_1 = 0;
    replace_current_thread_locale_nolock(**arg2, **arg2[1]);
    int32_t var_8_2 = 0xfffffffe;
    int32_t result = $LN17(&__saved_ebp);
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t $LN17(void* arg1 @ ebp)
{
    return ___acrt_unlock(**(arg1 + 0x10));
}

int32_t construct_ptd(int32_t* arg1)
{
    arg1[6] = 1;
    *arg1 = 0x416fd0;
    arg1[0xd4] = 1;
    arg1[0x12] = 0x41e358;
    arg1[0x1b] = 0x43;
    *(arg1 + 0x172) = 0x43;
    arg1[0xd3] = 0;
    int32_t** var_14 = &arg1;
    void* var_c = 5;
    int32_t var_18 = 5;
    int32_t* var_1c = &var_c;
    __crt_seh_guarded_call<void>::operator()<class <lambda_15ade71b0218206bbe3333a0c9b79046>,class <lambda_da44e0f8b0f19ba52fefafb335991732>&,class <lambda_207f2d024fc103971653565357d6cd41> >(
        &var_18, &var_14);
    int32_t** var_10 = &arg1;
    void arg_8;
    var_c = &arg_8;
    var_18 = 4;
    var_14 = 4;
    int32_t* var_1c_1 = &var_18;
    return __crt_seh_guarded_call<void>::operator()<class <lambda_a7e850c220f1c8d1e6efeecdedd162c6>,class <lambda_46720907175c18b6c9d2717bc0d2d362>&,class <lambda_9048902d66e8d99359bc9897bbb930a8> >(
        &var_14, &var_10);
}

void __stdcall destroy_fls(int32_t* arg1)
{
    if (arg1)
    {
        destroy_ptd(arg1);
        __free_base(arg1);
    }
}

int32_t destroy_ptd(int32_t* arg1)
{
    int32_t* eax = arg1;
    int32_t ecx = *eax;

    if (ecx != 0x416fd0)
    {
        __free_base(ecx);
        eax = arg1;
    }

    __free_base(eax[0xf]);
    __free_base(arg1[0xc]);
    __free_base(arg1[0xd]);
    __free_base(arg1[0xe]);
    __free_base(arg1[0xa]);
    __free_base(arg1[0xb]);
    __free_base(arg1[0x10]);
    __free_base(arg1[0x11]);
    __free_base(arg1[0xd8]);
    int32_t** var_10 = &arg1;
    int32_t var_c = 5;
    int32_t var_14 = 5;
    int32_t* var_18_3 = &var_c;
    __crt_seh_guarded_call<void>::operator()<class <lambda_38edbb1296d33220d7e4dd0ed76b244a>,class <lambda_5ce1d447e08cb34b2473517608e21441>&,class <lambda_fb385d3da700c9147fc39e65dd577a8c> >(
        &var_14, &var_10);
    var_10 = &arg1;
    var_14 = 4;
    var_c = 4;
    int32_t* var_18_4 = &var_14;
    return __crt_seh_guarded_call<void>::operator()<class <lambda_6affb1475c98b40b75cdec977db92e3c>,class <lambda_b8d4b9c228a6ecc3f80208dbb4b4a104>&,class <lambda_608742c3c92a14382c1684fc64f96c88> >(
        &var_c, &var_10);
}

int32_t* sub_409a81()
{
    int32_t edi;
    int32_t var_4 = edi;
    enum WIN32_ERROR dwErrCode = GetLastError();
    int32_t __saved_ebx = 0xffffffff;
    int32_t __saved_esi = data_41e1d0;

    if (!sub_40c49e())
    {
        SetLastError(dwErrCode);
        return 0;
    }

    int32_t* result_1 = sub_40cf40(1, 0x364);

    if (!result_1)
    {
        int32_t var_10 = 0;
        int32_t var_14 = data_41e1d0;
        sub_40c49e();
        __free_base(0);
        SetLastError(dwErrCode);
        return nullptr;
    }

    int32_t* result_2 = result_1;
    int32_t var_14_1 = data_41e1d0;
    int32_t* result;

    if (sub_40c49e())
    {
        int32_t* var_10_4 = &data_41ed00;
        construct_ptd(result_1);
        __free_base(0);
        result = result_1;
    }
    else
    {
        result = nullptr;
        int32_t var_10_2 = 0;
        int32_t var_14_2 = data_41e1d0;
        sub_40c49e();
        __free_base(result_1);
    }

    SetLastError(dwErrCode);
    return result;
}

void* replace_current_thread_locale_nolock(void* arg1, void* arg2)
{
    if (*(arg1 + 0x4c))
    {
        sub_40ef19(*(arg1 + 0x4c));
        void* eax_1 = *(arg1 + 0x4c);

        if (eax_1 != data_41ed00 && eax_1 != &data_41e290 && !*(eax_1 + 0xc))
            sub_40ed4e(eax_1);
    }

    void* result = arg2;
    *(arg1 + 0x4c) = result;

    if (result)
        result = sub_40ecd1(result);

    return result;
}

int32_t* sub_409b74()
{
    int32_t* result = sub_409bc5();

    if (!result)
        /* tailcall */
        return sub_4096af();

    return result;
}

int32_t* sub_409b82()
{
    int32_t __saved_ebp_2 = 0;
    int32_t (* var_c)(void* arg1 @ 0x8) = sub_415708;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t __saved_ebp;
    int32_t var_20 = __security_cookie ^ &__saved_ebp;
    void* const var_24_1 = &data_409b8e;
    int32_t var_8_1 = 0xffffffff;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t var_8 = 0;
    int32_t eax = data_41e1d0;
    int32_t* result;

    if (eax != 0xffffffff)
    {
        int32_t var_24 = eax;
        result = sub_40c492();
    }

    if (eax == 0xffffffff || !result)
    {
        result = sub_409a81();

        if (!result)
        {
            sub_4096af();
            /* no return */
        }
    }
    else if (result == 0xffffffff)
    {
        sub_4096af();
        /* no return */
    }

    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_1 = &data_409bb0;
    return result;
}

int32_t* sub_409bc5()
{
    int32_t __saved_ebp_2 = 0;
    int32_t (* var_c)(void* arg1 @ 0x8) = sub_415694;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t __saved_ebp;
    int32_t var_20 = __security_cookie ^ &__saved_ebp;
    void* const var_24_3 = &data_409bd1;
    int32_t var_8_2 = 0xffffffff;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t* result;

    if (!data_41eccc)
    {
        enum WIN32_ERROR dwErrCode = GetLastError();
        int32_t eax_3 = data_41e1d0;
        int32_t var_8_1 = 1;

        if (eax_3 != 0xffffffff)
        {
            int32_t var_24_1 = eax_3;
            result = sub_40c492();
        }

        if (eax_3 == 0xffffffff || !result)
            result = sub_409a81();
        else if (result == 0xffffffff)
            result = nullptr;

        SetLastError(dwErrCode);
    }
    else
    {
        int32_t var_8 = 0;
        int32_t eax = data_41e1d0;

        if (eax != 0xffffffff)
        {
            int32_t var_24 = eax;
            result = sub_40c485();
        }

        if (eax == 0xffffffff || !result)
            result = sub_409a81();
        else if (result == 0xffffffff)
            result = nullptr;
    }

    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_1 = &data_409c4b;
    return result;
}

void* sub_409c51(int32_t arg1 @ 0x8)
{
    int32_t __saved_ebp_2 = 0;
    int32_t (* var_c)(void* arg1 @ 0x8) = sub_415708;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t __saved_ebp;
    int32_t var_20 = __security_cookie ^ &__saved_ebp;
    void* const var_24_1 = &data_409c5d;
    int32_t var_8_1 = 0xffffffff;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t eax = data_41e1d0;
    void* result = nullptr;
    int32_t var_8 = 0;
    int32_t* eax_1;

    if (eax != 0xffffffff)
    {
        int32_t var_24 = eax;
        eax_1 = sub_40c492();
    }

    bool cond:0;

    if (eax == 0xffffffff || !eax_1)
    {
        eax_1 = sub_409a81();
        cond:0 = !eax_1;
    }
    else
        cond:0 = eax_1 == 0xffffffff;

    if (!cond:0)
        result = arg1 * 0x364 + eax_1;

    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_1 = &data_409c94;
    return result;
}

int32_t* sub_409c9a()
{
    void (__stdcall* var_4)(int32_t* arg1) = destroy_fls;
    data_41eccc = sub_40c567();
    int32_t eax = sub_40c46d();
    data_41e1d0 = eax;

    if (eax != 0xffffffff)
    {
        int32_t* eax_1 = sub_409bc5();

        if (eax_1)
        {
            eax_1 = 1;
            return eax_1;
        }

        int32_t* var_4_1 = eax_1;
        eax = ___acrt_uninitialize_ptd();
    }

    eax = 0;
    return eax;
}

int32_t ___acrt_uninitialize_ptd()
{
    int32_t result = data_41e1d0;

    if (result != 0xffffffff)
    {
        int32_t result_1 = result;
        result = sub_40c479();
        data_41e1d0 = 0xffffffff;
    }

    result = 1;
    return result;
}

int32_t sub_409cf0()
{
    data_41f148 = IsProcessorFeaturePresent(PF_XMMI64_INSTRUCTIONS_AVAILABLE);
    return 0;
}

int80_t sub_409d00(int32_t arg1 @ mxcsr, int16_t arg2 @ x87control, long double arg3 @ st0) __location("st0")
{
    int32_t var_4;

    if (data_41f148)
    {
        var_4 = arg1;
        int32_t eax_2 = var_4 & 0x7f80;
        bool cond:0_1 = eax_2 != 0x1f80;

        if (eax_2 == 0x1f80)
        {
            int16_t x87status_1;
            int16_t temp0_1;
            temp0_1 = __fnstcw_memmem16(arg2);
            int48_t var_c;
            *(&var_c + 4) = temp0_1;
            cond:0_1 = (*(&var_c + 4) & 0x7f) != 0x7f;
        }

        if (!cond:0_1)
            /* tailcall */
            return sub_409df0(arg3);
    }

    return sub_409d58(__checkTOS_withFB(arg3, var_4), arg2, arg3);
}

int80_t sub_409d4f() __location("st0")
{
    void arg_4;
    int32_t eax;
    int32_t ecx;
    long double st0;
    st0 = __fload_withFB(ecx, &arg_4);
    int16_t x87control;
    /* tailcall */
    return sub_409d58(eax, x87control, st0, arg_4);
}

void __convention("regparm") sub_409d58(int32_t arg1, int16_t arg2 @ x87control, long double arg3 @ st0, int32_t arg4 @ 0x4)
{
    int32_t edx;
    int32_t var_4 = edx;
    int16_t x87status;
    int16_t temp0;
    temp0 = __fnstcw_memmem16(arg2);
    var_4 = temp0;
    bool z;

    if (z)
    {
        if (arg1 & 0xfffff || arg4)
            return;

        if (!data_41f128)
        {
            __startOneArgErrorHandling(1, 0x12, data_418660, var_4);
            return;
        }
    }
    else
    {
        int16_t x87control;
        int16_t x87status_1;

        if (var_4 != 0x27f)
            x87control = __fldcw_memmem16(0x27f);
        long double st0_1;
        bool c1_1;
        bool c2_1;
        st0_1 = __fcos(arg3);
        long double x87_r0 = st0_1;
        bool c0;
        bool c3;

        if (TEST_BITB(
            *(&((c0 ? 1 : 0) << 8 | (c1_1 ? 1 : 0) << 9 | (c2_1 ? 1 : 0) << 0xa
                | (c3 ? 1 : 0) << 0xe) + 1),
            2))
        {
            bool c1_2 = false;
            long double x87_r7_2 = x87_r0;
            long double x87_r0_1 = data_41729a;
            bool c2_2;

            do
            {
                long double st0_2;
                uint8_t temp0_2;
                st0_2 = __fprem1(x87_r7_2, x87_r0_1);
                x87_r7_2 = st0_2;

                if (!c2_2)
                {
                    c0 = temp0_2 & 4;
                    c1_2 = temp0_2 & 1;
                    c3 = temp0_2 & 2;
                }
            } while (TEST_BITB(
                *(&((c0 ? 1 : 0) << 8 | (c1_2 ? 1 : 0) << 9 | (c2_2 ? 1 : 0) << 0xa
                    | (c3 ? 1 : 0) << 0xe | 0x3800) + 1),
                2));
            long double st0_3;
            st0_3 = __fcos(x87_r7_2);
            x87_r0 = st0_3;
        }

        if (!data_41f128)
        {
            int16_t eax = var_4;

            if (eax != 0x27f)
            {
                if (eax & 0x20 && ((c0 ? 1 : 0) << 8 | (c1_1 ? 1 : 0) << 9 | (c2_1 ? 1 : 0) << 0xa
                    | (c3 ? 1 : 0) << 0xe) & 0x20)
                {
                    __startOneArgErrorHandling(8, 0x12, x87_r0, var_4);
                    return;
                }

                int16_t x87control_2;
                int16_t x87status_3;
                x87control_2 = __fldcw_memmem16(var_4);
            }

            return;
        }
    }

    int16_t x87control_1;
    int16_t x87status_2;

    if (var_4 != 0x27f)
        x87control_1 = __fldcw_memmem16(var_4);
}

double* sub_409df0(long double arg1 @ st0)
{
    return sub_409e0e(arg1);
}

int32_t sub_409e08(int64_t arg1)
{
    /* tailcall */
    return sub_409e0e(arg1);
}

double* sub_409e0e(int32_t arg1[0x4] @ xmm0)
{
    int16_t eax = (_mm_extract_epi16(arg1, 3) & 0x7fff) - 0x3030;

    if (eax > 0x10c5)
    {
        if (eax > 0x10c5)
            /* tailcall */
            return sub_409d4f();

        uint32_t result = _mm_extract_epi16(arg1, 3);
        result &= 0x7fff;
        double var_c_1 = 1.0 - _mm_insert_epi16(arg1, result, 3);
        return result;
    }

    double xmm1 = 10.185916357881302 * arg1;
    double xmm1_2[0x2] = xmm1 + 6755399441055744.0 - 6755399441055744.0;
    double xmm2[0x2] = data_417180;
    double xmm3 = 0.098174770420882851 * xmm1_2;
    double xmm1_3[0x2] = _mm_unpacklo_pd(xmm1_2, xmm1_2);
    double xmm5[0x2] = data_417160;
    double xmm2_1[0x2] = _mm_mul_pd(xmm2, xmm1_3);
    double xmm0[0x2] = arg1 - xmm3;
    double xmm4_1 = arg1 - xmm3;
    double xmm7 = *((((xmm1 + 0x1c7610) & 0x3f) << 5) + 0x4186a8);
    double xmm0_1[0x2] = _mm_unpacklo_pd(xmm0, xmm0);
    double xmm4_2 = xmm4_1 - xmm2_1;
    double xmm5_1[0x2] = _mm_mul_pd(xmm5, xmm0_1);
    double xmm0_2[0x2] = _mm_sub_pd(xmm0_1, xmm2_1);
    double xmm6[0x2] = data_417140;
    double xmm5_2[0x2] = _mm_mul_pd(xmm5_1, xmm0_2);
    double xmm0_3[0x2] = _mm_mul_pd(xmm0_2, xmm0_2);
    double xmm3_4 = *((((xmm1 + 0x1c7610) & 0x3f) << 5) + 0x4186b8);
    double xmm2_3 = *(0x4186a0 + (((xmm1 + 0x1c7610) & 0x3f) << 5)) + xmm3_4;
    double xmm6_1[0x2] = _mm_mul_pd(xmm6, xmm0_3);
    double xmm3_5 = xmm3_4 * xmm4_2;
    double xmm2_5[0x2] = _mm_mul_pd(xmm2_3 * xmm4_2, xmm0_3);
    double xmm0_4[0x2] = _mm_mul_pd(xmm0_3, xmm0_3);
    double xmm5_3[0x2] = __addpd_xmmpd_mempd(xmm5_2, data_417150);
    double xmm4_3 = xmm4_2 * *(0x4186a0 + (((xmm1 + 0x1c7610) & 0x3f) << 5));
    double xmm6_2[0x2] = __addpd_xmmpd_mempd(xmm6_1, *data_417130);
    double xmm5_4[0x2] = _mm_mul_pd(xmm5_3, xmm0_4);
    double xmm3_6 = xmm3_5 + *((((xmm1 + 0x1c7610) & 0x3f) << 5) + 0x4186a8);
    double xmm4_4 = xmm4_3 + xmm3_6;
    double xmm6_3[0x2] = _mm_add_pd(xmm6_2, xmm5_4);
    double xmm5_6 = *((((xmm1 + 0x1c7610) & 0x3f) << 5) + 0x4186a8) - xmm3_6;
    double xmm1_7 =
        (xmm1_3 * 1.2639164054974691e-22 - (xmm4_1 - xmm4_2 - xmm2_1)) * (xmm7 * xmm4_2 - xmm2_3)
        + *((((xmm1 + 0x1c7610) & 0x3f) << 5) + 0x4186b0);
    double xmm6_4[0x2] = _mm_mul_pd(xmm6_3, xmm2_5);
    double var_c = xmm4_4 + xmm1_7 + xmm5_6 + xmm3_5 + xmm3_6 - xmm4_4 + xmm4_3 + xmm6_4
        + _mm_unpackhi_pd(xmm6_4, xmm6_4);
    return 0x4186a0 + (((xmm1 + 0x1c7610) & 0x3f) << 5);
}

int80_t sub_409fa0(int32_t arg1 @ mxcsr, int16_t arg2 @ x87control, long double arg3 @ st0) __location("st0")
{
    int32_t var_4;

    if (data_41f148)
    {
        var_4 = arg1;
        int32_t eax_2 = var_4 & 0x7f80;
        bool cond:0_1 = eax_2 != 0x1f80;

        if (eax_2 == 0x1f80)
        {
            int16_t x87status_1;
            int16_t temp0_1;
            temp0_1 = __fnstcw_memmem16(arg2);
            int48_t var_c;
            *(&var_c + 4) = temp0_1;
            cond:0_1 = (*(&var_c + 4) & 0x7f) != 0x7f;
        }

        if (!cond:0_1)
            /* tailcall */
            return sub_40a090(arg3);
    }

    return sub_409ff8(__checkTOS_withFB(arg3, var_4), arg2, arg3);
}

int80_t sub_409fef() __location("st0")
{
    void arg_4;
    int32_t eax;
    int32_t ecx;
    long double st0;
    st0 = __fload_withFB(ecx, &arg_4);
    int16_t x87control;
    /* tailcall */
    return sub_409ff8(eax, x87control, st0, arg_4);
}

void __convention("regparm") sub_409ff8(int32_t arg1, int16_t arg2 @ x87control, long double arg3 @ st0, int32_t arg4 @ 0x4)
{
    int32_t edx;
    int32_t var_4 = edx;
    int16_t x87status;
    int16_t temp0;
    temp0 = __fnstcw_memmem16(arg2);
    var_4 = temp0;
    bool z;

    if (z)
    {
        if (arg1 & 0xfffff || arg4)
            return;

        if (!data_41f128)
        {
            __startOneArgErrorHandling(1, 0x1e, data_418660, var_4);
            return;
        }
    }
    else
    {
        int16_t x87control;
        int16_t x87status_1;

        if (var_4 != 0x27f)
            x87control = __fldcw_memmem16(0x27f);
        long double st0_1;
        bool c1_1;
        bool c2_1;
        st0_1 = __fsin(arg3);
        long double x87_r0 = st0_1;
        bool c0;
        bool c3;

        if (TEST_BITB(
            *(&((c0 ? 1 : 0) << 8 | (c1_1 ? 1 : 0) << 9 | (c2_1 ? 1 : 0) << 0xa
                | (c3 ? 1 : 0) << 0xe) + 1),
            2))
        {
            bool c1_2 = false;
            long double x87_r7_2 = x87_r0;
            long double x87_r0_1 = data_41729a;
            bool c2_2;

            do
            {
                long double st0_2;
                uint8_t temp0_2;
                st0_2 = __fprem1(x87_r7_2, x87_r0_1);
                x87_r7_2 = st0_2;

                if (!c2_2)
                {
                    c0 = temp0_2 & 4;
                    c1_2 = temp0_2 & 1;
                    c3 = temp0_2 & 2;
                }
            } while (TEST_BITB(
                *(&((c0 ? 1 : 0) << 8 | (c1_2 ? 1 : 0) << 9 | (c2_2 ? 1 : 0) << 0xa
                    | (c3 ? 1 : 0) << 0xe | 0x3800) + 1),
                2));
            long double st0_3;
            st0_3 = __fsin(x87_r7_2);
            x87_r0 = st0_3;
        }

        if (!data_41f128)
        {
            int16_t eax = var_4;

            if (eax != 0x27f)
            {
                if (eax & 0x20 && ((c0 ? 1 : 0) << 8 | (c1_1 ? 1 : 0) << 9 | (c2_1 ? 1 : 0) << 0xa
                    | (c3 ? 1 : 0) << 0xe) & 0x20)
                {
                    __startOneArgErrorHandling(8, 0x1e, x87_r0, var_4);
                    return;
                }

                int16_t x87control_2;
                int16_t x87status_3;
                x87control_2 = __fldcw_memmem16(var_4);
            }

            return;
        }
    }

    int16_t x87control_1;
    int16_t x87status_2;

    if (var_4 != 0x27f)
        x87control_1 = __fldcw_memmem16(var_4);
}

double* sub_40a090(long double arg1 @ st0)
{
    return sub_40a0ae(arg1);
}

int32_t sub_40a0a8(int64_t arg1)
{
    /* tailcall */
    return sub_40a0ae(arg1);
}

double* sub_40a0ae(int32_t arg1[0x4] @ xmm0)
{
    uint32_t result = _mm_extract_epi16(arg1, 3);
    result &= 0x7fff;
    result -= 0x3030;

    if (result > 0x10c5)
    {
        if (result > 0x10c5)
            /* tailcall */
            return sub_409fef();

        result u>>= 4;

        if (result != 0xcfd)
        {
            double var_c_2 = arg1;
            return result;
        }

        double var_c_1 = arg1 * 0.99999999999999989;
        return result;
    }

    double xmm1 = 10.185916357881302 * arg1;
    double xmm1_2[0x2] = xmm1 + 6755399441055744.0 - 6755399441055744.0;
    double xmm2[0x2] = data_417240;
    double xmm3 = 0.098174770420882851 * xmm1_2;
    double xmm1_3[0x2] = _mm_unpacklo_pd(xmm1_2, xmm1_2);
    double xmm5[0x2] = data_417220;
    double xmm2_1[0x2] = _mm_mul_pd(xmm2, xmm1_3);
    double xmm0[0x2] = arg1 - xmm3;
    double xmm4_1 = arg1 - xmm3;
    double xmm7 = *((((xmm1 + 0x1c7600) & 0x3f) << 5) + 0x4186a8);
    double xmm0_1[0x2] = _mm_unpacklo_pd(xmm0, xmm0);
    double xmm4_2 = xmm4_1 - xmm2_1;
    double xmm5_1[0x2] = _mm_mul_pd(xmm5, xmm0_1);
    double xmm0_2[0x2] = _mm_sub_pd(xmm0_1, xmm2_1);
    double xmm6[0x2] = data_417200;
    double xmm5_2[0x2] = _mm_mul_pd(xmm5_1, xmm0_2);
    double xmm0_3[0x2] = _mm_mul_pd(xmm0_2, xmm0_2);
    double xmm3_4 = *((((xmm1 + 0x1c7600) & 0x3f) << 5) + 0x4186b8);
    double xmm2_3 = *(0x4186a0 + (((xmm1 + 0x1c7600) & 0x3f) << 5)) + xmm3_4;
    double xmm6_1[0x2] = _mm_mul_pd(xmm6, xmm0_3);
    double xmm3_5 = xmm3_4 * xmm4_2;
    double xmm2_5[0x2] = _mm_mul_pd(xmm2_3 * xmm4_2, xmm0_3);
    double xmm0_4[0x2] = _mm_mul_pd(xmm0_3, xmm0_3);
    double xmm5_3[0x2] = __addpd_xmmpd_mempd(xmm5_2, data_417210);
    double xmm4_3 = xmm4_2 * *(0x4186a0 + (((xmm1 + 0x1c7600) & 0x3f) << 5));
    double xmm6_2[0x2] = __addpd_xmmpd_mempd(xmm6_1, *data_4171f0);
    double xmm5_4[0x2] = _mm_mul_pd(xmm5_3, xmm0_4);
    double xmm3_6 = xmm3_5 + *((((xmm1 + 0x1c7600) & 0x3f) << 5) + 0x4186a8);
    double xmm4_4 = xmm4_3 + xmm3_6;
    double xmm6_3[0x2] = _mm_add_pd(xmm6_2, xmm5_4);
    double xmm5_6 = *((((xmm1 + 0x1c7600) & 0x3f) << 5) + 0x4186a8) - xmm3_6;
    double xmm1_7 =
        (xmm1_3 * 1.2639164054974691e-22 - (xmm4_1 - xmm4_2 - xmm2_1)) * (xmm7 * xmm4_2 - xmm2_3)
        + *((((xmm1 + 0x1c7600) & 0x3f) << 5) + 0x4186b0);
    double xmm6_4[0x2] = _mm_mul_pd(xmm6_3, xmm2_5);
    double var_c = xmm4_4 + xmm1_7 + xmm5_6 + xmm3_5 + xmm3_6 - xmm4_4 + xmm4_3 + xmm6_4
        + _mm_unpackhi_pd(xmm6_4, xmm6_4);
    return 0x4186a0 + (((xmm1 + 0x1c7600) & 0x3f) << 5);
}

long double __twoToTOS(long double arg1 @ st0)
{
    long double x87_r7 = roundl(arg1);
    long double st0;
    bool c1;
    st0 = __f2xm1(-((x87_r7 - arg1)));
    long double result;
    bool c1_1;
    result = __fscale(st0 + 1, x87_r7);
    return result;
}

int32_t __load_CW(int32_t arg1)
{
    *(&arg1 + 2) = (arg1 & 0x300) | 0x7f;
    int16_t x87control;
    int16_t x87status;
    x87control = __fldcw_memmem16(*(&arg1 + 2));
}

void __convention("regparm") __convertTOStoQNaN(int32_t arg1, long double arg2 @ st0) __pure
{
    return;
}

long double __fastcall __fload_withFB(int32_t arg1, double* arg2)
{
    if ((*(arg2 + 4) & 0x7ff00000) != 0x7ff00000)
        return *arg2;

    int32_t var_4 = *(arg2 + 4) | 0x7fff0000;
    int32_t ecx = *arg2;
    int32_t var_6 = *(arg2 + 4) << 0xb | ecx >> 0x15;
    *(arg2 + 4);
    return (ecx << 0xb);
}

int32_t __checkTOS_withFB(int32_t arg1 @ 0x8) __pure
{
    int32_t eax = arg1 & 0x7ff00000;

    if (eax == 0x7ff00000)
        return arg1;

    return eax;
}

void __fastcall __check_overflow_exit(int32_t arg1, int32_t arg2, long double arg3 @ st0)
{
    bool c1 = /* bool c1 = unknown  {fst qword [esp], st0} */;
    int32_t eax_3;

    if ((*(&arg3 + 4) & 0x7ff00000) == 0x7ff00000)
    {
        long double st0_3;
        bool c1_1;
        st0_3 = __fscale(arg3, -1536.0);
        arg3 = st0_3;
        long double x87_r7_5 = fabsl(arg3);
        long double temp1_1 = 1.7976931348623157e+308;
        x87_r7_5 - temp1_1;
        int16_t eax_4 = (x87_r7_5 < temp1_1 ? 1 : 0) << 8
            | (FCMP_UO(x87_r7_5, temp1_1) ? 1 : 0) << 0xa | (x87_r7_5 == temp1_1 ? 1 : 0) << 0xe;
        eax_3 = 3;

        if (!TEST_BITB(*(&eax_4 + 1), 6) && !TEST_BITB(*(&eax_4 + 1), 0))
            arg3 = arg3 * inf.0;
    }
    else
    {
        int16_t eax_2 = __return_addr;

        if (eax_2 == 0x27f)
            return;

        bool c0;
        bool c2;
        bool c3;

        if (eax_2 & 0x20 || !(((c0 ? 1 : 0) << 8 | (c1 ? 1 : 0) << 9 | (c2 ? 1 : 0) << 0xa
            | (c3 ? 1 : 0) << 0xe) & 0x20))
        {
            int16_t x87control_1;
            int16_t x87status_1;
            x87control_1 = __fldcw_memmem16(__return_addr);
            return;
        }

        eax_3 = 8;
    }

    if (arg2 == 0x1d)
    {
        __startTwoArgErrorHandling(eax_3, arg2, arg3);
        return;
    }

    __startOneArgErrorHandling(eax_3, arg2, arg3);
}

int80_t sub_40a3f0(long double arg1 @ st0) __location("st0")
{
    int16_t x87control;
    return sub_40a404(x87control, arg1);
}

void sub_40a404(int16_t arg1 @ x87control, long double arg2 @ st0, int32_t arg3, int32_t arg4)
{
    int32_t edx;
    int32_t var_4 = edx;
    int16_t x87status;
    int16_t temp0;
    temp0 = __fnstcw_memmem16(arg1);
    var_4 = temp0;
    bool z;

    if (z)
    {
        int32_t eax_1;

        if (!(arg4 & 0xfffff) && !arg3)
        {
            if (!(arg4 & 0x80000000))
                goto label_40a425;

        label_40a477:
            arg2 = data_418660;
            eax_1 = 1;
            goto label_40a482;
        }

        long double st0_1;
        st0_1 = __convertTOStoQNaN(arg4, arg2);
        arg2 = st0_1;
    label_40a482:

        if (!data_41f128)
        {
            __startOneArgErrorHandling(eax_1, 5, arg2, arg3, arg4);
            return;
        }
    }
    else
    {
        if (var_4 != 0x27f)
            __load_CW(var_4);

        bool c1;

        if (!(arg4 & 0x80000000))
        {
            arg2 = sqrtl(arg2);
            c1 = /* c1 = unknown  {fsqrt } */;
        }
        else if (arg4 & 0x7ff00000 || arg4 & 0xfffff || arg3)
            goto label_40a477;

    label_40a425:

        if (!data_41f128)
        {
            int16_t eax_2 = var_4;

            if (eax_2 != 0x27f)
            {
                bool c0;
                bool c2;
                bool c3;

                if (eax_2 & 0x20 && ((c0 ? 1 : 0) << 8 | (c1 ? 1 : 0) << 9 | (c2 ? 1 : 0) << 0xa
                    | (c3 ? 1 : 0) << 0xe) & 0x20)
                {
                    __startOneArgErrorHandling(8, 5, arg2, arg3, arg4);
                    return;
                }

                int16_t x87control_1;
                int16_t x87status_2;
                x87control_1 = __fldcw_memmem16(var_4);
            }

            return;
        }
    }

    int16_t x87control;
    int16_t x87status_1;

    if (var_4 != 0x27f)
        x87control = __fldcw_memmem16(var_4);
}

int32_t __fastcall __crt_cached_ptd_host::check_synchronize_global_state_index(void* arg1)
{
    if (*(arg1 + 8))
        return *(arg1 + 4);

    enum WIN32_ERROR dwErrCode = GetLastError();
    *(arg1 + 4) = 0;
    *(arg1 + 8) = 1;
    SetLastError(dwErrCode);
    return 0;
}

int32_t sub_40a4ca(int32_t arg1, int32_t arg2, int32_t arg3)
{
    int32_t ebp;
    int32_t var_4 = ebp;
    int32_t eax_1 = __security_cookie ^ &var_4;
    int32_t edi;
    int32_t var_330_1 = edi;

    if (arg1 != 0xffffffff)
    {
        int32_t var_334_1 = arg1;
        sub_403540();
    }

    int32_t var_324;
    _memset(&var_324, 0, 0x50);
    uint32_t var_2d4[0x4];
    int32_t ecx_2;
    int32_t edx;
    ecx_2 = _memset(&var_2d4, 0, 0x2cc);
    EXCEPTION_POINTERS ExceptionInfo = struct EXCEPTION_POINTERS {
        .ExceptionRecord = &var_324,
        .ContextRecord = &var_2d4
    };
    uint32_t (* var_224)[0x4] = &var_2d4;
    int32_t var_228 = ecx_2;
    int32_t var_22c = edx;
    int32_t ebx;
    int32_t var_230 = ebx;
    int32_t esi;
    int32_t var_234 = esi;
    int32_t var_238 = edi;
    int16_t ss;
    int16_t var_20c = ss;
    int16_t cs;
    int16_t var_218 = cs;
    int16_t ds;
    int16_t var_23c = ds;
    int16_t es;
    int16_t var_240 = es;
    int16_t fs;
    int16_t var_244 = fs;
    int16_t gs;
    int16_t var_248 = gs;
    int32_t var_348;
    int32_t var_330;
    bool d;
    int32_t var_334_2 = (&var_348 + 0x18 ? 1 : 0) << 0xb | (d ? 1 : 0) << 0xa
        | (&var_330 < 0 ? 1 : 0) << 7 | (&var_348 == 0xffffffe8 ? 1 : 0) << 6
        | ((&var_348 ^ 0x18 ^ &var_330) & 0x10 ? 1 : 0) << 4
        | (!(__builtin_popcount(&var_330) & 1) ? 1 : 0) << 2 | (&var_348 >= 0xffffffe8 ? 1 : 0);
    int32_t var_214 = var_334_2;
    void* const __return_addr_2 = __return_addr;
    var_2d4[0] = 0x10001;
    int32_t var_220 = var_4;
    var_324 = arg2;
    int32_t var_320 = arg3;
    void* const __return_addr_1 = __return_addr;
    BOOL eax_7 = IsDebuggerPresent();
    SetUnhandledExceptionFilter(nullptr);
    int32_t result = UnhandledExceptionFilter(&ExceptionInfo);

    if (!result && !eax_7 && arg1 != 0xffffffff)
    {
        int32_t var_334_4 = arg1;
        sub_403540();
    }

    sub_402910(eax_1 ^ &var_4);
    return result;
}

int32_t sub_40a603(int32_t arg1)
{
    data_41ecd0 = arg1;
    return arg1;
}

int32_t __invalid_parameter(int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4, int32_t arg5)
{
    void var_2c;
    __crt_cached_ptd_host::__crt_cached_ptd_host(&var_2c, nullptr);
    __invalid_parameter_internal(arg1, arg2, arg3, arg4, arg5, &var_2c);
    return __crt_cached_ptd_host::~__crt_cached_ptd_host(&var_2c);
}

int32_t __invalid_parameter_internal(int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4, int32_t arg5, int32_t* arg6)
{
    int32_t edi;
    int32_t var_c = edi;
    void* eax = *arg6;
    int32_t var_20;
    int32_t var_1c;
    int32_t var_18;
    int32_t var_14;
    int32_t var_10;
    int32_t esi_1;

    if (eax)
    {
    label_40a664:
        esi_1 = *(eax + 0x35c);

        if (!esi_1)
            goto label_40a695;

        var_10 = arg5;
        var_14 = arg4;
        var_18 = arg3;
        var_1c = arg2;
        var_20 = arg1;
    }
    else
    {
        eax = __crt_cached_ptd_host::force_synchronize_per_thread_data(arg6);

        if (eax)
            goto label_40a664;

    label_40a695:
        var_10 = arg5;
        var_14 = arg4;
        var_18 = arg3;
        var_1c = arg2;
        esi_1 = RORD(
            (&data_41ecd0)[__crt_cached_ptd_host::check_synchronize_global_state_index(arg6)]
                ^ __security_cookie,
            __security_cookie & 0x1f);
        var_20 = arg1;

        if (!esi_1)
        {
            sub_40a6d6();
            /* no return */
        }
    }

    return esi_1(var_20, var_1c, var_18, var_14, var_10);
}

int32_t __invalid_parameter_noinfo()
{
    return __invalid_parameter(0, 0, 0, 0, 0);
}

void sub_40a6d6() __noreturn
{
    if (IsProcessorFeaturePresent(PF_FASTFAIL_AVAILABLE))
        trap(0xd);

    sub_40a4ca(2, 0xc0000417, 1);
    TerminateProcess(GetCurrentProcess(), 0xc0000417);
    /* no return */
}

int32_t* sub_40a70a(int32_t arg1, int32_t arg2, uint32_t arg3)
{
    uint32_t ecx = arg3;
    int32_t edx = 0;
    int32_t esi = arg1;
    int32_t edi;
    int32_t var_1c = edi;
    int32_t var_10 = ecx - 1;
    int32_t ebx_3;

    do
    {
        uint32_t eax_2 = ecx >> 1;

        if (!eax_2)
        {
            if (!ecx)
                break;

            int32_t* eax_5 = arg2 + (edx << 3);

            if (esi != *eax_5)
                return nullptr;

            return eax_5;
        }

        uint32_t ebx_1 = eax_2 - 1;

        if (ecx & 1)
            ebx_1 = eax_2;

        int32_t ecx_1 = ebx_1 + edx;
        int32_t* ecx_2 = arg2 + (ecx_1 << 3);
        int32_t esi_1 = *ecx_2;
        esi = arg1;

        if (esi == *ecx_2)
            return ecx_2;

        ecx = eax_2;

        if (esi < esi_1)
            ecx = ebx_1;

        ebx_3 = ecx_1 - 1;

        if (esi >= esi_1)
            edx = ecx_1 + 1;

        if (esi >= esi_1)
            ebx_3 = var_10;

        var_10 = ebx_3;
    } while (edx <= ebx_3);
    return nullptr;
}

int32_t sub_40a789(int32_t arg1)
{
    if (arg1 >= 1)
    {
        if (arg1 <= 0xd)
            return *((arg1 << 3) + &data_4172e0[4]);

        if (arg1 <= 0x718)
        {
            int32_t* eax_2 = sub_40a70a(arg1, 0x4172e8, 0x2d);

            if (eax_2)
                return eax_2[1];
        }
    }

    if (arg1 - 0x13 > 0x11)
        return ((arg1 - 0xbc - (arg1 - 0xbc)) & 0xe) + 8;

    return 0xd;
}

int32_t* ___acrt_errno_map_os_error(int32_t arg1)
{
    *sub_40a82f() = arg1;
    int32_t eax_1 = sub_40a789(arg1);
    int32_t* result = sub_40a844();
    *result = eax_1;
    return result;
}

int32_t ___acrt_errno_map_os_error_ptd(int32_t arg1, void* arg2)
{
    *(arg2 + 0x24) = 1;
    *(arg2 + 0x20) = arg1;
    int32_t result = sub_40a789(arg1);
    *(arg2 + 0x1c) = 1;
    *(arg2 + 0x18) = result;
    return result;
}

void* sub_40a82f()
{
    int32_t* eax_1 = sub_409bc5();

    if (eax_1)
        return &eax_1[5];

    return &data_41e1e4;
}

void* sub_40a844()
{
    int32_t* eax_1 = sub_409bc5();

    if (eax_1)
        return &eax_1[4];

    return &data_41e1e0;
}

void __free_base(int32_t arg1)
{
    if (arg1 && !HeapFree(data_41f110, HEAP_NONE, arg1))
        *sub_40a844() = sub_40a789(GetLastError());
}

int32_t sub_40a8a0()
{
    return data_41f110;
}

int32_t sub_40a8b0(uint32_t arg1)
{
    uint32_t dwBytes = arg1;

    if (dwBytes <= 0xffffffe0)
    {
        if (!dwBytes)
            dwBytes = 1;

        int32_t i;

        do
        {
            int32_t result = HeapAlloc(data_41f110, HEAP_NONE, dwBytes);

            if (result)
                return result;

            if (!sub_409070())
                break;

            i = __callnewh(dwBytes);
        } while (i);
    }

    *sub_40a844() = 0xc;
    return 0;
}

void* sub_40a910(void arg1 @ invalid, char* arg2, void* arg3)
{
    int32_t eax = data_41eae8;
    int32_t edi;
    int32_t var_c = edi;
    void* result;
    char* edx_1;

    if (eax < 5)
    {
        if (eax < 1)
        {
            char* eax_17 = arg2;
            void* ecx_8 = arg3 + arg2;

            if (arg2 != ecx_8)
            {
                while (*eax_17)
                {
                    eax_17 = &eax_17[1];

                    if (eax_17 == ecx_8)
                        break;
                }
            }

            return eax_17 - arg2;
        }

        char* esi_1 = arg2;
        void* edi_11 = arg2 & 0xf;
        int32_t edi_12 = -(edi_11);
        void* edi_14 = (edi_12 - edi_12) & (0x10 - edi_11);

        if (arg3 < edi_14)
            edi_14 = arg3;

        void* eax_10 = edi_14 + arg2;

        if (arg2 != eax_10)
        {
            while (*esi_1)
            {
                esi_1 = &esi_1[1];

                if (esi_1 == eax_10)
                    break;
            }
        }

        result = esi_1 - arg2;

        if (result == edi_14)
        {
            edx_1 = esi_1;
            void* ecx_6 = arg3 - edi_14;
            void* edi_17 = esi_1 - (ecx_6 & 0xf) + ecx_6;

            if (esi_1 != edi_17)
            {
                do
                {
                    if (_mm_movemask_epi8(__pcmpeqb_xmmdq_memdq({0}, *edx_1)))
                        break;

                    edx_1 = &edx_1[0x10];
                } while (edx_1 != edi_17);
            }

            void* eax_15 = arg3 + arg2;

            if (edx_1 != eax_15)
            {
                while (*edx_1)
                {
                    edx_1 = &edx_1[1];

                    if (edx_1 == eax_15)
                        return edx_1 - arg2;
                }
            }

            return edx_1 - arg2;
        }
    }
    else
    {
        char* esi = arg2;
        void* edi_2 = arg2 & 0x1f;
        int32_t edi_3 = -(edi_2);
        void* edi_5 = (edi_3 - edi_3) & (0x20 - edi_2);

        if (arg3 < edi_5)
            edi_5 = arg3;

        void* eax_2 = edi_5 + arg2;

        if (arg2 != eax_2)
        {
            while (*esi)
            {
                esi = &esi[1];

                if (esi == eax_2)
                    break;
            }
        }

        result = esi - arg2;

        if (result == edi_5)
        {
            edx_1 = esi;
            void* ecx_2 = arg3 - edi_5;
            void* edi_8 = esi - (ecx_2 & 0x1f) + ecx_2;

            if (esi != edi_8)
            {
                do
                {
                    arg1 = __vpcmpeqb_ymmqq_ymmqq_memqq(arg1, *edx_1);
                    bool cond:0_1 = _mm256_movemask_epi8(arg1);
                    _mm256_zeroupper();

                    if (cond:0_1)
                        break;

                    edx_1 = &edx_1[0x20];
                } while (edx_1 != edi_8);
            }

            void* eax_7 = arg3 + arg2;

            if (edx_1 != eax_7)
            {
                while (*edx_1)
                {
                    edx_1 = &edx_1[1];

                    if (edx_1 == eax_7)
                        break;
                }
            }

            return edx_1 - arg2;
        }
    }
    return result;
}

int32_t sub_40aa70(void arg1 @ invalid, int16_t* arg2, uint32_t arg3)
{
    int32_t eax = data_41eae8;
    int32_t edi;
    int32_t var_c = edi;

    if (eax >= 5)
    {
        int16_t* edx = arg2;

        if (!(arg2 & 1))
        {
            void* edi_3 = arg2 & 0x1f;
            int32_t edi_4 = -(edi_3);
            uint32_t edi_7 = ((edi_4 - edi_4) & (0x20 - edi_3)) >> 1;

            if (arg3 < edi_7)
                edi_7 = arg3;

            void* eax_5 = &arg2[edi_7];

            if (arg2 != eax_5)
            {
                while (*edx)
                {
                    edx = &edx[1];

                    if (edx == eax_5)
                        break;
                }
            }

            int32_t edx_4 = (edx - arg2) >> 1;

            if (edx_4 != edi_7)
                return edx_4;

            uint16_t (* i)[0x10] = &arg2[edx_4];
            uint32_t ecx_2 = arg3 - edi_7;

            for (; i != &arg2[ecx_2 - (ecx_2 & 0x1f) + edx_4]; i = &i[1])
            {
                arg1 = __vpcmpeqw_ymmqq_ymmqq_memqq(arg1, *i);
                bool cond:0_1 = _mm256_movemask_epi8(arg1);
                _mm256_zeroupper();

                if (cond:0_1)
                    break;
            }

            void* eax_10 = &arg2[arg3];

            if (i != eax_10)
            {
                while (*i)
                {
                    i = &(*i)[1];

                    if (i == eax_10)
                        break;
                }
            }

            return (i - arg2) >> 1;
        }

        void* eax_2 = &arg2[arg3];

        if (arg2 != eax_2)
        {
            while (*edx)
            {
                edx = &edx[1];

                if (edx == eax_2)
                    break;
            }
        }

        return (edx - arg2) >> 1;
    }

    if (eax < 1)
    {
        void* ecx_8 = &arg2[arg3];
        int16_t* eax_24 = arg2;

        if (arg2 != ecx_8)
        {
            while (*eax_24)
            {
                eax_24 = &eax_24[1];

                if (eax_24 == ecx_8)
                    break;
            }
        }

        return (eax_24 - arg2) >> 1;
    }

    int16_t* i_3 = arg2;
    int16_t* i_2;

    if (!(i_3 & 1))
    {
        void* edi_13 = i_3 & 0xf;
        int32_t edi_14 = -(edi_13);
        int16_t* i_4 = i_3;
        uint32_t edi_17 = ((edi_14 - edi_14) & (0x10 - edi_13)) >> 1;

        if (arg3 < edi_17)
            edi_17 = arg3;

        void* edx_8 = &i_3[edi_17];

        if (i_3 != edx_8)
        {
            while (*i_4)
            {
                i_4 = &i_4[1];

                if (i_4 == edx_8)
                    break;
            }
        }

        int32_t eax_17 = (i_4 - i_3) >> 1;

        if (eax_17 != edi_17)
            return eax_17;

        int16_t* i_1 = &i_3[eax_17];
        uint32_t edx_10 = arg3 - edi_17;
        i_3 = arg2;

        for (; i_1 != &i_3[edx_10 - (edx_10 & 0xf) + eax_17]; i_1 = &i_1[8])
        {
            if (_mm_movemask_epi8(__pcmpeqw_xmmdq_memdq({0}, *i_1)))
                break;
        }

        void* eax_20 = &i_3[arg3];

        if (i_1 != eax_20)
        {
            while (*i_1)
            {
                i_1 = &i_1[1];

                if (i_1 == eax_20)
                    break;
            }
        }

        i_2 = i_1;
    }
    else
    {
        void* edx_7 = &i_3[arg3];
        i_2 = i_3;

        if (i_3 != edx_7)
        {
            while (*i_2)
            {
                i_2 = &i_2[1];

                if (i_2 == edx_7)
                    return (i_2 - i_3) >> 1;
            }
        }
    }

    return (i_2 - i_3) >> 1;
}

void* ___acrt_update_locale_info(void* arg1, int32_t* arg2)
{
    void* result = *arg2;

    if (result != data_41ed00)
    {
        result = data_41e8d0;

        if (!(*(arg1 + 0x350) & result))
        {
            result = ___acrt_update_thread_locale_data();
            *arg2 = result;
        }
    }

    return result;
}

void* ___acrt_update_locale_info_explicit(void* arg1, int32_t* arg2, void* arg3)
{
    void* result = arg3;

    if (*arg2 != (&data_41ed00)[result])
    {
        result = data_41e8d0;

        if (!(*(arg1 + 0x350) & result))
        {
            result = ___acrt_update_thread_locale_data();
            *arg2 = result;
        }
    }

    return result;
}

int32_t* ___acrt_update_multibyte_info(void* arg1, int32_t* arg2)
{
    int32_t* result = *arg2;

    if (result != data_41ef74)
    {
        result = data_41e8d0;

        if (!(*(arg1 + 0x350) & result))
        {
            result = ___acrt_update_thread_multibyte_data();
            *arg2 = result;
        }
    }

    return result;
}

int32_t* ___acrt_update_multibyte_info_explicit(void* arg1, int32_t* arg2, int32_t* arg3)
{
    int32_t* result = arg3;

    if (*arg2 != (&data_41ef74)[result])
    {
        result = data_41e8d0;

        if (!(*(arg1 + 0x350) & result))
        {
            result = ___acrt_update_thread_multibyte_data();
            *arg2 = result;
        }
    }

    return result;
}

int32_t __acrt_fp_classify(int32_t* arg1)
{
    int32_t edi;
    int32_t var_c = edi;
    int32_t edi_1 = *arg1;
    int32_t edx = arg1[1];

    if ((edx >> 0x14 & 0x7ff) != 0x7ff)
        return 0;

    int32_t esi_2 = edx & 0xfffff;
    int32_t eax_5 = edi_1 | esi_2;

    if (!eax_5)
        return eax_5 + 1;

    if (edx <= 0 && (edx < 0 || edi_1 < 0) && !edi_1 && esi_2 == 0x80000)
        return 4;

    if (!(edx & 0x80000))
        return 3;

    return 2;
}

uint32_t sub_40ad63(int32_t* arg1, int32_t arg2, int32_t arg3, int16_t arg4)
{
    int32_t result_1 = arg4;
    int32_t esi = arg1[1];
    int32_t edi;
    int32_t var_10 = edi;
    int32_t edi_1 = *arg1;
    uint32_t result = __aullshr(edi_1 & arg2, esi & arg3 & 0xfffff, result_1);

    if (result > 8)
        result = 1;
    else if (result >= 8)
    {
        int32_t ecx_1 = 0;
        char ebx = 0;
        result = result_1;
        int32_t edx_3 = 1 << (result % 0x20);

        if (result >= 0x20)
            ecx_1 = edx_3;

        int32_t edx_4 = edx_3 ^ ecx_1;

        if (result >= 0x40)
            ecx_1 = edx_4;

        if (((edx_4 - 1) & edi_1) | ((ecx_1 - 1) & esi & 0xfffff))
            result = 1;
        else
        {
            if (arg4 == 0x30)
            {
                result = esi & 0x7ff00000;

                if (result)
                    ebx = 1;
            }
            else
            {
                result = __aullshr((edi_1 >> 4 | esi << 0x1c) & arg2, esi >> 4 & arg3, arg4);
                ebx = result;
            }

            result = ebx & 1;
        }
    }
    else
        result = 0;

    return result;
}

int32_t sub_40ae15(int32_t* arg1, char* arg2, void* arg3, char* arg4, int32_t arg5, void* arg6, char arg7, int32_t arg8, int32_t arg9, int32_t* arg10)
{
    void* esi = nullptr;
    int32_t edi;
    int32_t var_38 = edi;

    if (arg6 >= 0)
        esi = arg6;

    char* edi_1 = arg2;
    *edi_1 = 0;

    if (arg3 <= esi + 0xb)
    {
        arg10[7] = 1;
        arg10[6] = 0x22;
        __invalid_parameter_internal(0, 0, 0, 0, 0, arg10);
        return 0x22;
    }

    int32_t* ebx_1 = arg1;

    if ((ebx_1[1] >> 0x14 & 0x7ff) != 0x7ff)
    {
        int32_t temp0_1 = ebx_1[1];

        if (temp0_1 <= 0 && (temp0_1 < 0 || *ebx_1 < 0))
        {
            *edi_1 = 0x2d;
            edi_1 = &edi_1[1];
        }

        char eax_5 = arg7 ^ 1;
        int32_t var_18_1 = 0;
        char* edx_1 = &edi_1[1];
        int32_t var_14_1 = 0x3ff;
        char* var_10_1 = edx_1;
        int64_t var_30;

        if (ebx_1[1] & 0x7ff00000)
            *edi_1 = 0x31;
        else
        {
            *edi_1 = 0x30;

            if (*ebx_1 | (ebx_1[1] & 0xfffff))
            {
                int32_t var_18_3 = 0;
                var_14_1 = 0x3fe;
            }
            else
            {
                var_30 = 0;
                int32_t var_18_2 = 0;
                var_14_1 = 0;
            }
        }

        char* edi_2 = &edx_1[1];
        char eax_12;

        if (esi)
        {
            int32_t* eax_13 = arg10;

            if (!eax_13[5])
            {
                __crt_cached_ptd_host::update_locale_slow(eax_13);
                eax_13 = arg10;
                edx_1 = var_10_1;
            }

            eax_12 = ***(eax_13[3] + 0x88);
        }
        else
            eax_12 = 0;

        *edx_1 = eax_12;
        int32_t eax_18 = ebx_1[1] & 0xfffff;
        *(&var_30 + 4) = eax_18;

        if (eax_18 > 0 || *ebx_1 > 0)
        {
            int32_t var_c_1 = 0x30;
            uint32_t ecx_8 = 0xf0000;
            int32_t eax_19 = 0;
            uint32_t var_20_1 = 0xf0000;
            int32_t var_1c_1 = 0;
            int32_t edx_7;

            do
            {
                int16_t ebx_2 = var_c_1;
                ebx_1 = arg1;
                *(&var_30 + 4) = edi_2;

                if (esi <= 0)
                {
                    if (!should_round_up(ebx_1, eax_19, ecx_8, ebx_2, arg9))
                        goto label_40b05d;

                    edi_2 = *(&var_30 + 4);
                    char* eax_26 = &edi_2[0xffffffff];
                    char ecx_12;

                    while (true)
                    {
                        ecx_12 = *eax_26;

                        if (ecx_12 != 0x66 && ecx_12 != 0x46)
                            break;

                        *eax_26 = 0x30;
                        eax_26 -= 1;
                    }

                    ebx_1 = arg1;

                    if (eax_26 == var_10_1)
                        eax_26[0xffffffff] += 1;
                    else
                    {
                        if (ecx_12 == 0x39)
                            ecx_12 += ((eax_5 << 5) + 7);

                        *eax_26 = ecx_12 + 1;
                    }

                    goto label_40b044;
                }

                uint32_t eax_23 =
                    __aullshr(eax_19 & *ebx_1, ebx_1[1] & ecx_8 & 0xfffff, ebx_2) + 0x30;

                if (eax_23 > 0x39)
                    eax_23 += (eax_5 << 5) + 7;

                *edi_2 = eax_23;
                edx_7 = var_c_1 - 4;
                edi_2 = &edi_2[1];
                eax_19 = var_1c_1 >> 4 | var_20_1 << 0x1c;
                var_c_1 = edx_7;
                ecx_8 = var_20_1 >> 4;
                esi -= 1;
                var_1c_1 = eax_19;
                var_20_1 = ecx_8;
            } while (edx_7 >= 0);
        }

    label_40b044:

        if (esi > 0)
        {
            _memset(edi_2, 0x30, esi);
            edi_2 += esi;
        }

    label_40b05d:

        if (!*var_10_1)
            edi_2 = var_10_1;

        *edi_2 = (eax_5 << 5) + 0x50;
        int32_t ebx_5 = __aullshr(*ebx_1, ebx_1[1], 0x34) & 0x7ff;
        uint32_t ebx_6 = ebx_5 - var_14_1;
        bool c_1 = ebx_5 < var_14_1;
        uint32_t esi_1 = 0 - 0;
        bool s_1 = 0 - 0 < 0;
        char eax_31;

        if (s_1 || ((!(0 - 0) || s_1) && ebx_6 < 0))
        {
            uint32_t temp5_1 = ebx_6;
            ebx_6 = -(ebx_6);
            esi_1 = -((esi_1 + 0));
            eax_31 = 0x2d;
        }
        else
            eax_31 = 0x2b;

        edi_2[1] = eax_31;
        char* edi_3 = &edi_2[2];
        edi_2[2] = 0x30;

        if (esi_1 >= 0)
        {
            if (esi_1 > 0 || ebx_6 >= 0x3e8)
            {
                uint32_t var_40_4 = ebx_6;
                char eax_32;
                uint32_t ecx_15;
                eax_32 = __alldvrm(ebx_6, esi_1, 0x3e8, 0);
                esi_1 = ebx_6;
                ebx_6 = ecx_15;
                edi_3 = &edi_2[3];
                edi_2[2] = eax_32 + 0x30;

                if (edi_3 == &edi_2[2])
                    goto label_40b0e2;

            label_40b102:
                *edi_3 = __alldiv(ebx_6, esi_1, 0x64, 0) + 0x30;
                edi_3 = &edi_3[1];
                uint32_t eax_36;
                uint32_t edx_9;
                eax_36 = __allrem(ebx_6, esi_1, 0x64, 0);
                ebx_6 = eax_36;
                esi_1 = edx_9;

                if (edi_3 != &edi_2[2])
                {
                label_40b134:
                    *edi_3 = __alldiv(ebx_6, esi_1, 0xa, 0) + 0x30;
                    edi_3 = &edi_3[1];
                    ebx_6 = __allrem(ebx_6, esi_1, 0xa, 0);
                }
                else
                {
                label_40b114:

                    if (esi_1 >= 0 && (esi_1 > 0 || ebx_6 >= 0xa))
                        goto label_40b134;
                }
            }
            else
            {
            label_40b0e2:

                if (esi_1 >= 0)
                {
                    if (esi_1 > 0 || ebx_6 >= 0x64)
                        goto label_40b102;

                    goto label_40b114;
                }
            }
        }

        *edi_3 = ebx_6 + 0x30;
        edi_3[1] = 0;
    }
    else
    {
        int32_t result = sub_40b151(ebx_1, edi_1, arg3, arg4, arg5, esi, 0, arg8, arg9, arg10);

        if (result)
        {
            *edi_1 = 0;
            return result;
        }

        char* eax_4 = _strrchr(edi_1, 0x65);

        if (eax_4)
        {
            *eax_4 = ((arg7 ^ 1) << 5) + 0x50;
            eax_4[3] = 0;
        }
    }

    return 0;
}

int32_t sub_40b151(int32_t* arg1, char* arg2, void* arg3, char* arg4, int32_t arg5, void* arg6, char arg7, int32_t arg8, int32_t arg9, int32_t* arg10)
{
    int32_t var_34 = *arg1;
    int32_t var_10;
    int32_t eax_1 = sub_4108a7(arg1[1], arg6 + 1, 1, &var_10, arg4, arg5);
    int32_t edx = 0;
    edx = var_10 == 0x2d;
    void* ecx = nullptr;
    ecx = arg6 > 0;
    void* eax_4 = arg3 - ecx - edx;

    if (arg3 == 0xffffffff)
        eax_4 = arg3;

    int32_t result = sub_4102d4(ecx + edx + arg2, eax_4, arg6 + 1, &var_10, eax_1, arg9, arg10);

    if (!result)
        return sub_40b1e1(arg2, arg3, arg6, arg7, arg8, &var_10, 0, arg10);

    *arg2 = 0;
    return result;
}

int32_t sub_40b1e1(char* arg1, void* arg2, int32_t arg3, char arg4, int32_t arg5, int32_t* arg6, char arg7, int32_t* arg8)
{
    int32_t eax = 0;

    if (arg3 > 0)
        eax = arg3;

    if (arg2 <= eax + 9)
    {
        arg8[7] = 1;
        arg8[6] = 0x22;
        __invalid_parameter_internal(0, 0, 0, 0, 0, arg8);
        return 0x22;
    }

    int32_t edi;
    int32_t var_10_1 = edi;

    if (arg7)
    {
        int32_t eax_3 = 0;
        eax_3 = arg3 > 0;
        void* eax_4 = nullptr;
        eax_4 = *arg6 == 0x2d;
        void* var_1c_1 = arg2;
        char* var_20_1 = arg1;
        shift_bytes(eax_4 + arg1, eax_3);
    }

    char* esi_1 = arg1;

    if (*arg6 == 0x2d)
    {
        *arg1 = 0x2d;
        esi_1 = &arg1[1];
    }

    if (arg3 > 0)
    {
        *esi_1 = esi_1[1];
        esi_1 = &esi_1[1];
        int32_t* eax_8 = arg8;

        if (!eax_8[5])
        {
            __crt_cached_ptd_host::update_locale_slow(eax_8);
            eax_8 = arg8;
        }

        *esi_1 = ***(eax_8[3] + 0x88);
    }

    char* esi_2 = &esi_1[(arg7 ^ 1) + arg3];
    void* edi_3 = arg1 - esi_2 + arg2;

    if (arg2 == 0xffffffff)
        edi_3 = arg2;

    int32_t eax_16 = sub_409620(esi_2, edi_3, "e+000");

    if (eax_16)
    {
        int32_t var_24;
        __builtin_memset(&var_24, 0, 0x14);
        sub_40a6d6();
        /* no return */
    }

    if (arg4 != eax_16)
        *esi_2 = 0x45;

    if (*arg6[2] != 0x30)
    {
        int32_t edx_2 = arg6[1];
        int32_t edx_3 = edx_2 - 1;

        if (edx_2 - 1 < 0)
        {
            edx_3 = -(edx_3);
            esi_2[1] = 0x2d;
        }

        if (edx_3 >= 0x64)
        {
            int32_t eax_19;
            int32_t edx_4;
            edx_4 = HIGHD(edx_3);
            eax_19 = LOWD(edx_3);
            edx_3 = COMBINE(edx_4, eax_19) % 0x64;
            esi_2[2] += COMBINE(edx_4, eax_19) / 0x64;
        }

        if (edx_3 >= 0xa)
        {
            int32_t eax_22;
            int32_t edx_5;
            edx_5 = HIGHD(edx_3);
            eax_22 = LOWD(edx_3);
            edx_3 = COMBINE(edx_5, eax_22) % 0xa;
            esi_2[3] += COMBINE(edx_5, eax_22) / 0xa;
        }

        esi_2[4] += edx_3;
    }

    if (arg5 == 2 && esi_2[2] == 0x30)
        sub_4035c0(&esi_2[2], &esi_2[3], 3);

    return 0;
}

int32_t sub_40b324(int32_t* arg1, char* arg2, void* arg3, char* arg4, int32_t arg5, void* arg6, int32_t arg7, enum WIN32_ERROR arg8)
{
    int32_t edi;
    int32_t var_1c = edi;
    int32_t var_10 = 0;
    void* var_c;
    int32_t* edi_1 = &var_c;
    *edi_1 = 0;
    edi_1[1] = 0;
    int32_t var_38 = *arg1;
    int32_t eax_1 = sub_4108a7(arg1[1], arg6, 0, &var_10, arg4, arg5);
    void* ecx = nullptr;
    ecx = var_10 == 0x2d;
    void* eax_5 = arg3 - ecx;

    if (arg3 == 0xffffffff)
        eax_5 = arg3;

    int32_t result = sub_4102d4(ecx + arg2, eax_5, var_c + arg6, &var_10, eax_1, arg7, arg8);

    if (!result)
        return sub_40b3ad(arg2, arg3, arg6, &var_10, 0, arg8);

    *arg2 = 0;
    return result;
}

int32_t sub_40b3ad(char* arg1, int32_t arg2, void* arg3, int32_t* arg4, char arg5, enum WIN32_ERROR arg6)
{
    int32_t ecx_1 = arg4[1] - 1;
    int32_t edi;
    int32_t var_10 = edi;
    void* edi_1 = arg3;

    if (arg5 && ecx_1 == edi_1)
    {
        void* eax_1 = nullptr;
        eax_1 = *arg4 == 0x2d;
        *(eax_1 + ecx_1 + arg1) = 0x30;
    }

    char* esi = arg1;

    if (*arg4 == 0x2d)
    {
        *arg1 = 0x2d;
        esi = &arg1[1];
    }

    int32_t eax_3 = arg4[1];
    char* esi_1;

    if (eax_3 > 0)
        esi_1 = &esi[eax_3];
    else
    {
        char eax_5;

        if (eax_3 || *arg4[2] != 0x30)
            eax_5 = 0;
        else
            eax_5 = 1;

        if (!arg5 || !eax_5)
        {
            int32_t var_1c_1 = arg2;
            char* var_20_1 = arg1;
            shift_bytes(esi, 1);
        }

        *esi = 0x30;
        esi_1 = &esi[1];
    }

    if (edi_1 > 0)
    {
        int32_t var_1c_2 = arg2;
        char* var_20_2 = arg1;
        shift_bytes(esi_1, 1);
        enum WIN32_ERROR eax_6 = arg6;

        if (!*(eax_6 + 0x14))
        {
            __crt_cached_ptd_host::update_locale_slow(eax_6);
            eax_6 = arg6;
        }

        *esi_1 = ***(*(eax_6 + 0xc) + 0x88);
        int32_t eax_12 = arg4[1];

        if (eax_12 < 0)
        {
            int32_t eax_13 = -(eax_12);

            if (arg5 || eax_13 < edi_1)
                edi_1 = eax_13;

            int32_t var_1c_3 = arg2;
            char* var_20_3 = arg1;
            shift_bytes(&esi_1[1], edi_1);
            _memset(&esi_1[1], 0x30, edi_1);
        }
    }

    return 0;
}

int32_t sub_40b48d(int32_t* arg1, char* arg2, void* arg3, char* arg4, int32_t arg5, void* arg6, char arg7, int32_t arg8, int32_t arg9, enum WIN32_ERROR arg10)
{
    int32_t edi;
    int32_t var_20 = edi;
    int32_t var_14 = 0;
    int32_t var_10;
    int32_t* edi_1 = &var_10;
    *edi_1 = 0;
    edi_1[1] = 0;
    int32_t var_3c = *arg1;
    int32_t eax_1 = sub_4108a7(arg1[1], arg6, 0, &var_14, arg4, arg5);
    void* edx = nullptr;
    edx = var_14 == 0x2d;
    int32_t ecx_1 = var_10 - 1;
    void* eax_3 = arg3 - edx;
    char* esi = edx + arg2;

    if (arg3 == 0xffffffff)
        eax_3 = arg3;

    int32_t result = sub_4102d4(esi, eax_3, arg6, &var_14, eax_1, arg9, arg10);

    if (result)
    {
        *arg2 = 0;
        return result;
    }

    if (var_10 - 1 < 0xfffffffc || var_10 - 1 >= arg6)
        return sub_40b1e1(arg2, arg3, arg6, arg7, arg8, &var_14, 1, arg10);

    if (ecx_1 < var_10 - 1)
    {
        char i;

        do
        {
            i = *esi;
            esi = &esi[1];
        } while (i);

        esi[0xfffffffe] = i;
    }

    return sub_40b3ad(arg2, arg3, arg6, &var_14, 1, arg10);
}

int32_t sub_40b554(int32_t arg1, char arg2, char* arg3, int32_t arg4, char arg5)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    int32_t edx = arg4;

    if (edx < arg2 + 4)
    {
        *arg3 = 0;
        return 0xc;
    }

    char* ecx_2 = arg3;

    if (arg2)
    {
        *ecx_2 = 0x2d;
        ecx_2 = &ecx_2[1];
        *ecx_2 = 0;

        if (edx != 0xffffffff)
            edx -= 1;
    }

    int32_t edi;
    int32_t var_14 = edi;
    int32_t edi_3 = (arg5 ^ 1) * 2;
    char* esi = (&data_417450)[(arg1 << 2) + 0xfffffffc + edi_3];
    void* eax_6 = &esi[1];
    void* var_8_1 = eax_6;

    do
    {
        eax_6 = *esi;
        esi = &esi[1];
    } while (eax_6);

    int32_t result =
        sub_409620(ecx_2, edx, (&data_417450)[eax_6 - eax_6 + (arg1 << 2) + 0xfffffffd + edi_3]);

    if (!result)
        return result;

    int32_t var_1c_1;
    __builtin_memset(&var_1c_1, 0, 0x14);
    sub_40a6d6();
    /* no return */
}

void shift_bytes(char* arg1 @ 0xc, int32_t arg2)
{
    if (!arg2)
        return;

    char* ecx_1 = arg1;
    int32_t edi;
    int32_t var_c_1 = edi;
    char i;

    do
    {
        i = *ecx_1;
        ecx_1 = &ecx_1[1];
    } while (i);
    sub_4035c0(&arg1[arg2], arg1, ecx_1 - &ecx_1[1] + 1);
}

uint32_t should_round_up(int32_t* arg1, int32_t arg2, int32_t arg3, int16_t arg4, int32_t arg5)
{
    int32_t edi;
    int32_t var_10 = edi;
    uint32_t result = __aullshr(arg2 & *arg1, arg1[1] & arg3 & 0xfffff, arg4);
    uint32_t edi_1 = result;

    if (arg5)
    {
        result = sub_40c5d0();

        if (!result)
            return sub_40ad63(arg1, arg2, arg3, arg4);

        if (result == 0x200)
        {
            result = 0;

            if (edi_1)
            {
                int32_t temp0_1 = arg1[1];

                if (temp0_1 >= 0 && (temp0_1 > 0 || *arg1 >= 0))
                    result = 1;
            }
        }
        else if (result != 0x100)
            result = 0;
        else
        {
            result = 0;

            if (edi_1)
            {
                int32_t temp1_1 = arg1[1];

                if (temp1_1 <= 0 && (temp1_1 < 0 || *arg1 < 0))
                    result = 1;
            }
        }
    }
    else
    {
        result = result - result;
        result += 1;
    }

    return result;
}

int32_t sub_40b6b0(int32_t* arg1, char* arg2, void* arg3, char* arg4, int32_t arg5, int32_t arg6, void* arg7, int32_t arg8, int32_t arg9 @ 0x28, int32_t* arg10)
{
    char ecx;
    char var_8 = ecx;
    char var_c = ecx;
    int32_t edi;
    int32_t var_18 = edi;
    int32_t* var_1c_1;

    if (!arg2)
    {
        var_1c_1 = arg10;
        arg10[7] = 1;
        arg10[6] = 0x16;
    }
    else if (arg3 > 0 && arg4)
    {
        int32_t ebx_1 = 0;

        if (arg5 > 0)
        {
            if (arg6 != 0x41 && arg6 != 0x45 && arg6 != 0x46)
                var_8 = 0;

            if (arg6 == 0x41 || arg6 == 0x45 || arg6 == 0x46 || arg6 == 0x47)
                var_8 = 1;

            int32_t ecx_2 = arg8;

            if (!(ecx_2 & 8))
            {
                int32_t eax_7 = __acrt_fp_classify(arg1);

                if (eax_7)
                {
                    int32_t temp0_1 = arg1[1];

                    if (temp0_1 > 0 || (temp0_1 >= 0 && *arg1 >= 0))
                        var_c = 0;
                    else
                        var_c = 1;

                    return sub_40b554(eax_7, var_c, arg2, arg3, var_8);
                }

                ecx_2 = arg8;
            }

            int32_t var_1c_4;

            var_1c_4 = !(ecx_2 & 0x10) ? 2 : 3;

            if (ecx_2 & 0x20)
                ebx_1 = arg9;

            int32_t esi_3;
            bool cond:3_1;

            if (arg6 > 0x61)
            {
                esi_3 = arg6 - 0x65;
                cond:3_1 = arg6 == 0x65;
            }
            else
            {
                if (arg6 == 0x61 || arg6 == 0x41)
                    return sub_40ae15(arg1, arg2, arg3, arg4, arg5, arg7, var_8, var_1c_4, ebx_1,
                        arg10);

                esi_3 = arg6 - 0x45;
                cond:3_1 = arg6 == 0x45;
            }

            enum WIN32_ERROR var_1c_6 = arg10;

            if (cond:3_1)
                return sub_40b151(arg1, arg2, arg3, arg4, arg5, arg7, var_8, var_1c_4, ebx_1,
                    var_1c_6);

            if (esi_3 == 1)
                return sub_40b324(arg1, arg2, arg3, arg4, arg5, arg7, ebx_1, var_1c_6);

            return sub_40b48d(arg1, arg2, arg3, arg4, arg5, arg7, var_8, var_1c_4, ebx_1, var_1c_6);
        }

        var_1c_1 = arg10;
        arg10[7] = 1;
        arg10[6] = 0x16;
    }
    else
    {
        var_1c_1 = arg10;
        arg10[7] = 1;
        arg10[6] = 0x16;
    }

    __invalid_parameter_internal(0, 0, 0, 0, 0, var_1c_1);
    return 0x16;
}

int32_t __convention("regparm") sub_40b830(int32_t arg1, int32_t arg2, int32_t arg3, int32_t* arg4, char* arg5, void* arg6, int32_t* arg7 @ 0x14)
{
    int32_t var_8 = arg3;
    int32_t var_c = arg3;
    void* eax = arg6;
    int32_t edi;
    int32_t var_18 = edi;

    if (!arg5 && eax)
    {
        if (arg4)
            *arg4 = 0;

        return 0;
    }

    if (arg4)
        *arg4 = 0xffffffff;

    int32_t result;

    if (eax <= 0x7fffffff)
    {
        if (!arg7[5])
        {
            __crt_cached_ptd_host::update_locale_slow(arg7);
            eax = arg6;
        }

        void* ecx_1 = arg7[3];
        uint32_t edx = *(ecx_1 + 8);
        wchar16 arg_10;

        if (edx == 0xfde9)
        {
            uint32_t eax_2 = arg_10;
            var_c = 0;
            int32_t eax_3 = sub_411d75(arg5, eax_2, &var_c, arg7);

            if (arg4)
                *arg4 = eax_3;

            if (eax_3 > 4 && arg7[7])
                return arg7[6];

            return 0;
        }

        if (*(ecx_1 + 0xa8))
        {
            var_8 = 0;
            int32_t eax_5 = sub_40e427(edx, 0, &arg_10, 1, arg5, eax, nullptr, &var_8);

            if (eax_5)
            {
                if (var_8)
                    goto label_40b8f0;

                if (arg4)
                    *arg4 = eax_5;

                return 0;
            }

            if (GetLastError() != ERROR_INSUFFICIENT_BUFFER)
            {
            label_40b8f0:
                arg7[6] = 0x2a;
                arg7[7] = 1;
                return 0x2a;
            }

            if (arg5 && arg6 > 0)
                _memset(arg5, 0, arg6);
        }
        else
        {
            wchar16 ecx_2 = arg_10;

            if (ecx_2 > 0xff)
            {
                if (arg5 && eax)
                    _memset(arg5, 0, eax);

                goto label_40b8f0;
            }

            if (!arg5)
                goto label_40b907;

            if (eax)
            {
                *arg5 = ecx_2;
            label_40b907:

                if (!arg4)
                    return 0;

                *arg4 = 1;
                return 0;
            }
        }

        result = 0x22;
    }
    else
        result = 0x16;

    arg7[6] = result;
    arg7[7] = 1;
    __invalid_parameter_internal(0, 0, 0, 0, 0, arg7);
    return result;
}

int32_t* sub_40b994(int16_t* arg1, char* arg2, void* arg3, enum WIN32_ERROR arg4)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    int32_t edi;
    int32_t var_14 = edi;

    if (!arg2 || !arg3)
        data_41ecd4 = 0;
    else
    {
        if (*arg2)
        {
            int32_t eax;

            if (!*(arg4 + 0x14))
                eax = __crt_cached_ptd_host::update_locale_slow(arg4);

            int32_t* edx_1 = *(arg4 + 0xc);
            int32_t* result;

            if (edx_1[2] != 0xfde9)
            {
                if (!edx_1[0x2a])
                {
                    if (arg1)
                        *arg1 = *arg2;

                    return 1;
                }

                if (*(*edx_1 + (*arg2 << 1)) >= 0)
                {
                    int32_t eax_9 = 0;
                    eax_9 = arg1;

                    if (___acrt_MultiByteToWideChar(edx_1[2], 9, arg2, 1, arg1, eax_9))
                        return 1;
                }
                else
                {
                    if (edx_1[1] > 1 && arg3 >= edx_1[1])
                    {
                        int32_t eax_4 = 0;
                        eax_4 = arg1;

                        if (___acrt_MultiByteToWideChar(edx_1[2], 9, arg2, edx_1[1], arg1, eax_4))
                            return *(*(arg4 + 0xc) + 4);
                    }

                    if (arg3 >= *(*(arg4 + 0xc) + 4) && arg2[1])
                        return *(*(arg4 + 0xc) + 4);
                }

                *(arg4 + 0x1c) = 1;
                result = 0xffffffff;
                *(arg4 + 0x18) = 0x2a;
            }
            else
            {
                result = __crt_mbstring::__mbrtowc_utf8(eax, edx_1, ecx, arg1, arg2, arg3,
                    &data_41ecd4, arg4);

                if (result < 0)
                    return 0xffffffff;
            }

            return result;
        }

        if (arg1)
            *arg1 = 0;
    }

    return nullptr;
}

int32_t sub_40bac4(char* arg1)
{
    char ecx = *arg1;

    if (ecx >= 0)
    {
        int32_t result = 0;
        result = ecx;
        return result;
    }

    if ((ecx & 0xe0) == 0xc0)
        return 2;

    if ((ecx & 0xf0) == 0xe0)
        return 3;

    if ((ecx & 0xf8) == 0xf0)
        return 4;

    return 0xffffffff;
}

int32_t* sub_40bb05(int32_t* arg1, char* arg2, void* arg3, int32_t* arg4, int32_t* arg5)
{
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    int32_t* ebx = arg5;
    int32_t edi;
    int32_t var_40 = edi;
    int32_t* edi_1 = &data_41ecdc;

    if (arg4)
        edi_1 = arg4;

    int32_t* var_28 = ebx;
    void* eax_3 = 1;

    if (arg2)
        eax_3 = arg3;

    void* var_1c = eax_3;
    char* eax_4 = &data_41672a;

    if (arg2)
        eax_4 = arg2;

    int32_t* result_1 = nullptr;
    char* var_20 = eax_4;

    if (arg2)
        result_1 = arg1;

    int32_t* result_2 = result_1;
    int32_t* result;

    if (!var_1c)
        result = 0xfffffffe;
    else
    {
        int32_t esi_3;

        if (*(edi_1 + 6))
        {
            result_1 = edi_1[1];
            esi_3 = *edi_1;
            ebx = *(edi_1 + 6);

            if (result_1 - 2 <= 2 && ebx >= 1 && ebx < result_1)
                goto label_40bbeb;

        label_40bca4:
            result = __crt_mbstring::return_illegal_sequence(edi_1, var_28);
        }
        else
        {
            result_1 = sub_40bac4(eax_4);
            char ecx_2 = *var_20;
            var_20 = &var_20[1];

            if (!result_1 || result_1 == 1)
            {
                if (result_2)
                    *result_2 = ecx_2;

                result = result_1;
            }
            else if (result_1 < 2 || result_1 > 4)
                result = __crt_mbstring::return_illegal_sequence(edi_1, ebx);
            else
            {
                ebx = result_1;
                esi_3 = ((1 << ((7 - result_1) & 0x1f)) - 1) & ecx_2;
            label_40bbeb:
                uint32_t ecx_4 = ebx;
                void* eax_12 = ecx_4;

                if (ecx_4 >= var_1c)
                    eax_12 = var_1c;

                char* eax_13 = var_20;
                void* edi_3 = eax_13 - arg2;
                var_1c = edi_3;

                if (edi_3 < eax_12)
                {
                    do
                    {
                        *(&ebx + 1) = *eax_13;
                        var_1c += 1;

                        if ((*(&ebx + 1) & 0xc0) != 0x80)
                            goto label_40bca4;

                        esi_3 = esi_3 << 6 | (*(&ebx + 1) & 0x3f);
                        eax_13 = &eax_13[1];
                    } while (var_1c < eax_12);
                }

                if (eax_12 >= ecx_4)
                {
                    if ((esi_3 >= 0xd800 && esi_3 <= 0xdfff) || esi_3 > 0x10ffff)
                        goto label_40bca4;

                    int32_t var_14_1 = 0x80;
                    int32_t var_10_1 = 0x800;
                    int32_t var_c_1 = 0x10000;

                    if (esi_3 < (&var_1c)[result_1])
                        goto label_40bca4;

                    if (result_2)
                        *result_2 = esi_3;

                    if (!esi_3)
                        ecx_4 = 0;

                    result = sub_411e23(ecx_4, edi_1);
                }
                else
                {
                    edi_1[1] = result_1;
                    *edi_1 = esi_3;
                    *(edi_1 + 6) = ebx - eax_12;
                    result = 0xfffffffe;
                }
            }
        }
    }

    sub_402910(eax_1 ^ &__saved_ebp);
    return result;
}

int32_t __convention("regparm") sub_40bcbe(int32_t arg1, int32_t arg2, int32_t arg3, char* arg4, int16_t arg5, int32_t* arg6, int32_t* arg7)
{
    int32_t var_8 = arg3;
    int32_t var_c = arg3;
    int32_t* esi = &data_41ece4;
    uint32_t ecx = arg5;

    if (arg6)
        esi = arg6;

    int32_t edi;
    int32_t var_14 = edi;
    int32_t* var_18_1;

    if (*esi)
    {
        var_18_1 = arg7;

        if (ecx + 0x2400 <= 0x3ff)
        {
            var_c = 0;
            return sub_411e23(sub_411d75(arg4, (arg5 & 0xffff23ff) + *esi, &var_c, var_18_1), esi);
        }
    }
    else
    {
        if (ecx + 0x2400 > 0x3ff)
        {
            if (arg5 + 0x2800 > 0x3ff)
                return sub_411d75(arg4, ecx, esi, arg7);

            *esi = ((ecx & 0xffff27ff) + 0x40) << 0xa;
            return 0;
        }

        var_18_1 = arg7;
    }

    return __crt_mbstring::return_illegal_sequence(esi, var_18_1);
}

int32_t __stdcall sub_40bd69(char* arg1)
{
    if (!*arg1)
        return 1;

    if (!arg1[1])
        return 2;

    int32_t eax_1 = 0;
    eax_1 = arg1[2];
    return eax_1 + 3;
}

int32_t* __convention("regparm") __crt_mbstring::__mbrtowc_utf8(int32_t arg1, int32_t arg2, int32_t arg3, int16_t* arg4, char* arg5, void* arg6, int32_t* arg7, int32_t* arg8)
{
    int32_t var_8 = arg3;
    int32_t* result = sub_40bb05(&var_8, arg5, arg6, arg7, arg8);

    if (result <= 4)
    {
        int32_t ecx = var_8;

        if (ecx > 0xffff)
            ecx = 0xfffd;

        if (arg4)
            *arg4 = ecx;
    }

    return result;
}

int32_t __convention("regparm") sub_40bdd8(int32_t arg1, int32_t arg2, int32_t arg3, int16_t* arg4, int32_t* arg5, int32_t arg6, int32_t* arg7, int32_t* arg8)
{
    int32_t var_8 = arg3;
    int32_t var_c = arg3;
    int32_t edi;
    int32_t var_18 = edi;
    char* edi_2 = *arg5;
    int32_t eax_5;

    if (!arg4)
    {
        int32_t ebx_1 = 0;
        void* eax_8 = sub_40bd69(edi_2);

        while (true)
        {
            eax_5 = sub_40bb05(nullptr, edi_2, eax_8, arg7, arg8);

            if (eax_5 == 0xffffffff)
            {
                arg8[7] = 1;
                arg8[6] = 0x2a;
                break;
            }

            if (!eax_5)
                return ebx_1;

            edi_2 = &edi_2[eax_5];
            int32_t eax_9 = ebx_1 + 1;

            if (eax_5 != 4)
                eax_9 = ebx_1;

            ebx_1 = eax_9 + 1;
            eax_8 = sub_40bd69(edi_2);
        }
    }
    else
    {
        int32_t i_1 = arg6;
        int16_t* esi = arg4;

        if (i_1)
        {
            int32_t i;

            do
            {
                int32_t* eax_1 = sub_40bb05(&var_c, edi_2, sub_40bd69(edi_2), arg7, arg8);

                if (eax_1 == 0xffffffff)
                {
                    *arg5 = edi_2;
                    arg8[7] = 1;
                    arg8[6] = 0x2a;
                    return 0xffffffff;
                }

                if (!eax_1)
                {
                    edi_2 = nullptr;
                    *esi = 0;
                    break;
                }

                int32_t ecx = var_c;

                if (ecx > 0xffff)
                {
                    if (i_1 <= 1)
                        break;

                    i_1 -= 1;
                    var_c = ecx - 0x10000;
                    *esi = (ecx - 0x10000) >> 0xa | 0xd800;
                    esi = &esi[1];
                    ecx = ((ecx - 0x10000) & 0x3ff) | 0xdc00;
                }

                *esi = ecx;
                edi_2 += eax_1;
                esi = &esi[1];
                i = i_1;
                i_1 -= 1;
            } while (i != 1);
        }

        eax_5 = (esi - arg4) >> 1;
        *arg5 = edi_2;
    }

    return eax_5;
}

int32_t __fileno(void* arg1)
{
    if (arg1)
        return *(arg1 + 0x10);

    *sub_40a844() = 0x16;
    __invalid_parameter_noinfo();
    return 0xffffffff;
}

int32_t ___acrt_initialize_stdio()
{
    int32_t eax = data_41ecec;

    if (!eax)
    {
        eax = 0x200;
        data_41ecec = eax;
    }
    else if (eax < 3)
    {
        eax = 3;
        data_41ecec = eax;
    }

    data_41ecf0 = sub_40cf40(eax, 4);
    __free_base(0);

    if (!data_41ecf0)
    {
        data_41ecec = 3;
        data_41ecf0 = sub_40cf40(3, 4);
        __free_base(0);

        if (!data_41ecf0)
            return 0xffffffff;
    }

    int32_t edi = 0;

    for (void* i = &data_41e1e8; i != &data_41e290; )
    {
        int32_t var_c_1 = 0;
        int32_t var_10_1 = 0xfa0;
        void* var_14_1 = i + 0x20;
        sub_40c4aa();
        *(data_41ecf0 + (edi << 2)) = i;
        int32_t eax_9 = *((&data_41ed08)[edi >> 6] + (edi & 0x3f) * 0x38 + 0x18);

        if (eax_9 == 0xffffffff || eax_9 == 0xfffffffe || !eax_9)
            *(i + 0x10) = 0xfffffffe;

        i += 0x38;
        edi += 1;
    }

    return 0;
}

int32_t sub_40bfda()
{
    sub_40f8cc();
    __fcloseall();

    for (int32_t* i = nullptr; i != 0xc; i = &i[1])
    {
        ___acrt_stdio_free_buffer_nolock(*(i + data_41ecf0));
        DeleteCriticalSection(*(i + data_41ecf0) + 0x20);
    }

    int32_t result = __free_base(data_41ecf0);
    data_41ecf0 = 0;
    return result;
}

int32_t __lock_file(void* arg1)
{
    return EnterCriticalSection(arg1 + 0x20);
}

int32_t __unlock_file(void* arg1)
{
    return LeaveCriticalSection(arg1 + 0x20);
}

int32_t __get_printf_count_output()
{
    int32_t result = 0;
    result = data_41ecf4 == (__security_cookie | 1);
    return result;
}

int32_t sub_40c063()
{
    STARTUPINFOW startupInfo;
    int32_t result = GetStartupInfoW(&startupInfo);

    if (startupInfo.cbReserved2)
    {
        int32_t edi;
        int32_t var_50_1 = edi;
        LPBYTE lpReserved2 = startupInfo.lpReserved2;

        if (lpReserved2)
        {
            int32_t result_2 = *lpReserved2;
            int32_t result_1 = 0x2000;
            int32_t* ebx_2 = &lpReserved2[4 + result_2];

            if (result_2 < 0x2000)
                result_1 = result_2;

            ___acrt_lowio_ensure_fh_exists(result_1);

            if (result_1 > data_41ef08)
                result_1 = data_41ef08;

            int32_t esi_1 = 0;
            result = result_1;

            if (result)
            {
                do
                {
                    if (*ebx_2 != 0xffffffff && *ebx_2 != 0xfffffffe)
                    {
                        char ecx_2 = lpReserved2[esi_1 + 4];

                        if (ecx_2 & 1)
                        {
                            enum FILE_TYPE eax;

                            if (!(ecx_2 & 8))
                                eax = GetFileType(*ebx_2);

                            if (ecx_2 & 8 || eax)
                            {
                                void* edx_2 = (esi_1 & 0x3f) * 0x38 + (&data_41ed08)[esi_1 >> 6];
                                *(edx_2 + 0x18) = *ebx_2;
                                *(edx_2 + 0x28) = lpReserved2[esi_1 + 4];
                            }

                            result = result_1;
                        }
                    }

                    esi_1 += 1;
                    ebx_2 = &ebx_2[1];
                } while (esi_1 != result);
            }
        }
    }

    return result;
}

uint32_t initialize_stdio_handles_nolock()
{
    int32_t edi;
    int32_t var_c = edi;
    uint32_t result;

    for (int32_t i = 0; i != 3; i += 1)
    {
        result = i & 0x3f;
        void* esi_2 = result * 0x38 + (&data_41ed08)[i >> 6];

        if (*(esi_2 + 0x18) == 0xffffffff || *(esi_2 + 0x18) == 0xfffffffe)
        {
            *(esi_2 + 0x28) = 0x81;
            enum STD_HANDLE nStdHandle;

            if (!i)
                nStdHandle = STD_INPUT_HANDLE;
            else if (i == 1)
                nStdHandle = STD_OUTPUT_HANDLE;
            else
                nStdHandle = STD_ERROR_HANDLE;

            HANDLE hFile = GetStdHandle(nStdHandle);
            enum FILE_TYPE eax_7;

            if (hFile != 0xffffffff && hFile)
                eax_7 = GetFileType(hFile);

            if (hFile == 0xffffffff || !hFile || !eax_7)
            {
                *(esi_2 + 0x28) |= 0x40;
                *(esi_2 + 0x18) = 0xfffffffe;
                result = data_41ecf0;

                if (result)
                {
                    result = *(result + (i << 2));
                    *(result + 0x10) = 0xfffffffe;
                }
            }
            else
            {
                result = eax_7;
                *(esi_2 + 0x18) = hFile;

                if (result == 2)
                    *(esi_2 + 0x28) |= 0x40;
                else if (result == 3)
                    *(esi_2 + 0x28) |= 8;
            }
        }
        else
            *(esi_2 + 0x28) |= 0x80;
    }

    return result;
}

int32_t ___acrt_initialize_lowio()
{
    int32_t __saved_ebp_1 = 0xc;
    int32_t var_8 = 0x41cd20;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41cd20 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34 = &data_40c1cf;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    ___acrt_lock(7);
    char ebx = 0;
    char var_1d = 0;
    int32_t var_8_1 = 0;

    if (!___acrt_lowio_ensure_fh_exists(0))
    {
        sub_40c063();
        initialize_stdio_handles_nolock();
        ebx = 1;
        char var_1d_1 = 1;
    }

    int32_t var_8_2 = 0xfffffffe;
    int32_t result = $LN8();
    result = ebx;
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t sub_40c217(void* arg1 @ ebp)
{
    int32_t ebx;
    ebx = *(arg1 - 0x19);
    /* tailcall */
    return $LN8();
}

int32_t $LN8()
{
    return ___acrt_unlock(7);
}

CRITICAL_SECTION* sub_40c225()
{
    CRITICAL_SECTION* result;

    for (int32_t i = 0; i < 0x200; i += 4)
    {
        result = *(i + &data_41ed08);

        if (result)
        {
            result = ___acrt_lowio_destroy_handle_array(result);
            *(i + &data_41ed08) = 0;
        }
    }

    result = 1;
    return result;
}

int32_t sub_40c24f()
{
    int32_t result = data_420000;

    if (result == 0xffffffff)
        return 0;

    if (result)
        return result;

    enum PAGE_PROTECTION_FLAGS ecx;
    int32_t edx;
    return sub_40c2cf(result, edx, ecx, result, "AreFileApisANSI", 0x417f50, "AreFileApisANSI");
}

int32_t sub_40c279()
{
    int32_t result = data_420048;

    if (result == 0xffffffff)
        return 0;

    if (result)
        return result;

    enum PAGE_PROTECTION_FLAGS ecx;
    int32_t edx;
    return sub_40c2cf(result, edx, ecx, 0x12, "LCMapStringEx", 0x417f7c, "LCMapStringEx");
}

int32_t sub_40c2a4()
{
    int32_t result = data_420050;

    if (result == 0xffffffff)
        return 0;

    if (result)
        return result;

    enum PAGE_PROTECTION_FLAGS ecx;
    int32_t edx;
    return sub_40c2cf(result, edx, ecx, 0x14, "LocaleNameToLCID", 0x417f94, "LocaleNameToLCID");
}

int32_t __convention("regparm") sub_40c2cf(int32_t arg1, int32_t arg2, enum PAGE_PROTECTION_FLAGS arg3, int32_t arg4, PSTR arg5, int32_t* arg6, int32_t arg7)
{
    enum PAGE_PROTECTION_FLAGS lpflOldProtect = arg3;
    int32_t edi;
    int32_t var_14 = edi;
    int32_t* edi_1 = arg6;
    int32_t result;

    while (true)
    {
        if (edi_1 == arg7)
        {
            result = 0;
            break;
        }

        int32_t eax = *edi_1;
        HMODULE esi_1 = *((eax << 2) + &data_41ef10);

        if (!esi_1)
        {
            esi_1 = try_load_library_from_system_directory((&data_417998)[eax]);

            if (esi_1)
            {
                int32_t temp0_2 = *((eax << 2) + &data_41ef10);
                *((eax << 2) + &data_41ef10) = esi_1;

                if (temp0_2)
                    FreeLibrary(esi_1);

                result = GetProcAddress(esi_1, arg5);
                break;
            }

            *((eax << 2) + &data_41ef10);
            *((eax << 2) + &data_41ef10) = 0xffffffff;
        }
        else if (esi_1 != 0xffffffff)
        {
            result = GetProcAddress(esi_1, arg5);
            break;
        }

        edi_1 = &edi_1[1];
    }

    ___acrt_lock(0xe);

    if (VirtualProtect(&data_420000, 0x80, PAGE_READWRITE, &lpflOldProtect))
    {
        int32_t result_1 = result;

        if (!result)
            result_1 = 0xffffffff;

        (&data_420000)[arg4] = result_1;

        if (VirtualProtect(&data_420000, 0x80, PAGE_READONLY, &lpflOldProtect))
        {
            ___acrt_unlock(0xe);
            return result;
        }
    }

    sub_4096af();
    /* no return */
}

HMODULE try_load_library_from_system_directory(PWSTR arg1)
{
    HMODULE result = LoadLibraryExW(arg1, nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);

    if (result)
        return result;

    if (GetLastError() == ERROR_INVALID_PARAMETER && sub_40eb70(arg1, u"api-ms-", 7)
            && sub_40eb70(arg1, u"ext-ms-", 7))
        return LoadLibraryExW(arg1, nullptr, 0);

    return nullptr;
}

int32_t __stdcall sub_40c3ff(int32_t arg1)
{
    int32_t esi = data_420068;

    if (esi != 0xffffffff)
    {
        if (esi)
            return esi(0xfffffffa, arg1);

        int32_t eax;
        enum PAGE_PROTECTION_FLAGS ecx;
        int32_t edx;
        esi = sub_40c2cf(eax, edx, ecx, 0x1a, "AppPolicyGetProcessTerminationMethod", 0x417fb0,
            "AppPolicyGetProcessTerminationMethod");

        if (esi)
            return esi(0xfffffffa, arg1);
    }

    return 0xc0000225;
}

int32_t ___acrt_AreFileApisANSI@0()
{
    int32_t eax = sub_40c24f();

    if (!eax)
        return 1;

    return eax();
}

int32_t sub_40c46d()
{
    /* tailcall */
    return FlsAlloc();
}

int32_t sub_40c479()
{
    /* tailcall */
    return FlsFree();
}

int32_t sub_40c485()
{
    /* tailcall */
    return data_42000c();
}

int32_t sub_40c492()
{
    /* tailcall */
    return FlsGetValue();
}

int32_t sub_40c49e()
{
    /* tailcall */
    return FlsSetValue();
}

int32_t sub_40c4aa()
{
    /* tailcall */
    return InitializeCriticalSectionEx();
}

int32_t __stdcall ___acrt_LCMapStringEx@36(void* arg1, uint32_t arg2, wchar16* arg3, int32_t arg4, PWSTR arg5, int32_t arg6, int32_t arg7, int32_t arg8, int32_t arg9)
{
    int32_t eax = sub_40c279();

    if (!eax)
        return LCMapStringW(___acrt_LocaleNameToLCID@8(arg1, 0), arg2, arg3, arg4, arg5, arg6);

    return eax(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

int32_t __stdcall ___acrt_LocaleNameToLCID@8(void* arg1, int32_t arg2)
{
    int32_t eax = sub_40c2a4();

    if (eax)
        return eax(arg1, arg2);

    return ___acrt_DownlevelLocaleNameToLCID(arg1);
}

BOOL __fastcall sub_40c544(enum PAGE_PROTECTION_FLAGS arg1)
{
    enum PAGE_PROTECTION_FLAGS lpflOldProtect = arg1;
    BOOL result = VirtualProtect(&data_420000, 0x80, PAGE_READONLY, &lpflOldProtect);
    result = result;
    return result;
}

int32_t sub_40c567()
{
    int32_t result = data_42000c;
    bool cond:0_1;

    if (result != 0xffffffff)
    {
        cond:0_1 = result;

        if (!result)
        {
            enum PAGE_PROTECTION_FLAGS ecx;
            int32_t edx;
            result = sub_40c2cf(result, edx, ecx, 3, "FlsGetValue2", 0x417f64, "FlsGetValue2");
            cond:0_1 = result;
        }
    }
    else
    {
        result = 0;
        cond:0_1 = result;
    }

    result = cond:0_1;
    return result;
}

BOOL ___acrt_uninitialize_winapi_thunks(char arg1)
{
    BOOL result;

    if (!arg1)
    {
        for (int32_t* i = &data_41ef10; i != &data_41ef6c; i = &i[1])
        {
            if (*i)
            {
                if (*i != 0xffffffff)
                    result = FreeLibrary(*i);

                *i = 0;
            }
        }
    }

    result = 1;
    return result;
}

int32_t sub_40c5d0()
{
    int32_t mxcsr;
    return sub_40c920(sub_40c950(mxcsr));
}

long double sub_40c5e0(double arg1, int32_t* arg2)
{
    arg1 - 0;
    int16_t eax;
    *(&eax + 1) =
        (arg1 == 0.0 ? 1 : 0) << 6 | (FCMP_UO(arg1, 0.0) ? 1 : 0) << 2 | (arg1 < 0.0 ? 1 : 0);

    if (__builtin_popcount(*(&eax + 1) & 0x44) & 1)
    {
        *arg2 = 0;
        return {0};
    }

    int32_t edx = *(&arg1 + 4);
    double var_14_1;
    double var_c;
    int32_t ecx_7;
    int32_t edx_5;

    if (edx & 0x7ff00000 || !(arg1 | (edx & 0xfffff)))
    {
        var_14_1 = arg1;
        ecx_7 = (*(&var_14_1 + 4) & 0xbfefffff) | 0x3fe00000;
        edx_5 = (edx >> 0x14 & 0x7ff) - 0x3fe;
    }
    else
    {
        int32_t ebx_1 = 0;
        int32_t edx_1 = arg1;
        int32_t edi;
        int32_t var_20_1 = edi;
        *(&var_c + 4) = 0;
        ebx_1 = 0.0 > arg1;
        int32_t edi_2 = *(&arg1 + 4) & 0xfffff;
        int32_t eflags_1;
        int32_t esi_1;
        esi_1 = _bit_scan_reverse(edi_2);
        int32_t esi_2;
        int32_t eflags_2;

        if (!edi_2)
            esi_2 = _bit_scan_reverse(edx_1);
        else
            esi_2 = esi_1 + 0x20;
        int32_t eax_7;
        int32_t edx_3;
        eax_7 = __allshl(edx_1, edi_2, 0x34 - esi_2);
        int32_t edx_4 = edx_3 & 0xffefffff;

        if (ebx_1)
            edx_4 |= 0x80000000;

        *(&arg1 + 4) = edx_4;
        edx_5 = esi_2 - 0x431;
        arg1 = eax_7;
        var_14_1 = arg1;
        ecx_7 = (*(&var_14_1 + 4) & 0xbfefffff) | 0x3fe00000;
    }

    var_c = var_14_1;
    *(&var_c + 4) = ecx_7;
    *arg2 = edx_5;
    return var_c;
}

int32_t sub_40c6f0(int32_t arg1, int32_t arg2) __pure
{
    if (!arg1)
    {
        if (arg2 == 0x7ff00000)
            return 1;

        if (!arg1 && arg2 == 0xfff00000)
            return 2;
    }

    if ((arg2 & 0x7ff80000) == 0x7ff80000)
        return 3;

    int32_t edx_3 = arg2 & 0x7ff00000;

    if (edx_3 == 0x7ff00000 && (arg1 || (arg2 & 0x7fffffff) != edx_3))
        return 4;

    return 0;
}

struct _EXCEPTION_REGISTRATION_RECORD** sub_40c770(struct _EXCEPTION_REGISTRATION_RECORD** arg1)
{
    int32_t var_8 = 0xfffffffe;
    int32_t var_c = 0x41cd40;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t edi;
    int32_t var_28 = edi;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_c_1 = var_c ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_2c = __security_cookie_1 ^ &__saved_ebp;
    struct _EXCEPTION_REGISTRATION_RECORD** eax_2 = &ExceptionList;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t* var_1c = &var_2c;

    if (data_41eae8 >= 1)
    {
        if (arg1 & 0x40 && data_41e354)
        {
            int32_t var_8_1 = 0;
            int32_t var_8_2 = 0xfffffffe;
            fsbase->NtTib.ExceptionList = ExceptionList;
            return arg1;
        }

        eax_2 = arg1 & 0xffffffbf;
        arg1 = eax_2;
    }

    fsbase->NtTib.ExceptionList = ExceptionList;
    return eax_2;
}

int32_t sub_40c7e6(void* arg1 @ ebp)
{
    int32_t eax_1 = ***(arg1 - 0x14);

    if (eax_1 != 0xc0000005 && eax_1 != 0xc000001d)
        return 0;

    return 1;
}

int32_t sub_40c804(int32_t* arg1 @ ebp)
{
    int32_t* esp_4 = arg1[-6];
    data_41e354 = 0;
    arg1[2] &= 0xffffffbf;
    arg1[2];
    arg1[-1] = 0xfffffffe;
    TEB* fsbase;
    fsbase->NtTib.ExceptionList = arg1[-4];
    *esp_4;
    esp_4[1];
    esp_4[2];
    esp_4[3];
    *arg1;
}

int32_t sub_40c850()
{
    int16_t ecx;
    int16_t var_8 = ecx;
    __fnclex();
    bool c0;
    bool c1;
    bool c2;
    bool c3;
    return (c0 ? 1 : 0) << 8 | (c1 ? 1 : 0) << 9 | (c2 ? 1 : 0) << 0xa | (c3 ? 1 : 0) << 0xe;
}

int32_t sub_40c870(int16_t arg1 @ x87control, int16_t arg2, int32_t arg3)
{
    int16_t x87status;
    int16_t temp0;
    temp0 = __fnstcw_memmem16(arg1);
    int16_t x87control;
    int16_t x87status_1;
    x87control = __fldcw_memmem16((~arg3 & temp0) | (arg3 & arg2));
    return temp0;
}

void __set_statfp(long double arg1 @ st0, char arg2)
{
    int16_t top;
    bool c1;

    if (arg2 & 1)
    {
        data_417ff8;
        int32_t var_8_1 = arg1;
        top = 1;
        c1 = /* c1 = unknown  {fistp dword [ebp-0x4], st0} */;
    }

    if (arg2 & 8)
    {
        int32_t eax;
        bool c0;
        bool c2;
        bool c3;
        eax = (c0 ? 1 : 0) << 8 | (c1 ? 1 : 0) << 9 | (c2 ? 1 : 0) << 0xa | (c3 ? 1 : 0) << 0xe
            | (top & 7) << 0xb;
        /* unimplemented  {fld st0, tword [&data_417ff8]} */
        double temp1_1 = /* double temp1_1 = unimplemented  {fstp qword [ebp-0xc], st0} */;
        /* unimplemented  {fstp qword [ebp-0xc], st0} */
        double var_10_1 = temp1_1;
        bool c1_1 = /* bool c1_1 = unknown  {fstp qword [ebp-0xc], st0} */;
        eax = (c0 ? 1 : 0) << 8 | (c1_1 ? 1 : 0) << 9 | (c2 ? 1 : 0) << 0xa | (c3 ? 1 : 0) << 0xe
            | (top & 7) << 0xb;
    }

    if (arg2 & 0x10)
    {
        /* unimplemented  {fld st0, tword [&data_418004]} */
        double var_10_2 = /* double var_10_2 = unimplemented  {fstp qword [ebp-0xc], st0} */;
        /* unimplemented  {fstp qword [ebp-0xc], st0} */
    }

    if (arg2 & 4)
    {
        /* unimplemented  {fldz } */
        /* unimplemented  {fld1 } */
        /* unimplemented  {fdivrp st1, st0} */
        /* unimplemented  {fdivrp st1, st0} */
        /* unimplemented  {fstp st0, st0} */
        /* unimplemented  {fstp st0, st0} */
    }

    if (!(arg2 & 0x20))
        return;

    /* unimplemented  {fldpi } */
    double var_10_3 = /* double var_10_3 = unimplemented  {fstp qword [ebp-0xc], st0} */;
    /* unimplemented  {fstp qword [ebp-0xc], st0} */
}

int32_t sub_40c900() __pure
{
    int16_t ecx;
    int16_t var_8 = ecx;
    bool c0;
    bool c1;
    bool c2;
    bool c3;
    return (c0 ? 1 : 0) << 8 | (c1 ? 1 : 0) << 9 | (c2 ? 1 : 0) << 0xa | (c3 ? 1 : 0) << 0xe;
}

int32_t sub_40c920(int32_t arg1) __pure
{
    int32_t result = arg1 >> 0xe & 0x300;

    if (result == (arg1 >> 0x16 & 0x300))
        return result;

    return 0xffffffff;
}

int32_t sub_40c950(int32_t arg1 @ mxcsr)
{
    int32_t edi;
    int32_t var_30 = edi;
    int128_t var_24;
    __builtin_memset(&var_24, 0, 0x1c);
    int16_t x87status;
    uint224_t temp0;
    temp0 = __fnstenv_memmem28();
    var_24 = temp0;
    __fldenv_memmem28(var_24);
    int32_t edx_1 = var_24 & 0x1f3f;
    int32_t ecx_1 = edx_1 & 0x300;
    int32_t var_8;

    if (!ecx_1)
        var_8 = 0x2000;
    else if (ecx_1 == 0x200)
        var_8 = 0x1000;
    else
        var_8 = 0;

    int32_t eax_1 = edx_1 & 0xc00;
    int32_t esi;

    if (eax_1 > 0x800)
    {
        if (eax_1 == 0xc00)
            esi = 0x300;
        else
            esi = 0;
    }
    else if (eax_1 == 0x800)
        esi = 0x200;
    else if (!eax_1 || eax_1 != 0x400)
        esi = 0;
    else
        esi = 0x100;

    int32_t edi_10 = (((edx_1 >> 2 & 8) | (edx_1 & 0x10)) >> 2 | (edx_1 & 8)) >> 1
        | (((edx_1 & 2) << 3 | (edx_1 & 4)) * 2) | (edx_1 & 1) << 4 | (edx_1 & 0x1000) << 2;
    int32_t edi_12 = edi_10 | var_8 | esi;
    int32_t ecx_7;

    if (data_41eae8 >= 1)
        ecx_7 = arg1 & 0xffc0;
    else
        ecx_7 = 0;

    int16_t eax_9 = ecx_7 & 0x8040;
    int32_t ebx_3;

    if (eax_9 == 0x8000)
        ebx_3 = 0xc00;
    else if (eax_9 != 0x40)
    {
        ebx_3 = 0;

        if (eax_9 == 0x8040)
            ebx_3 = 0x400;
    }
    else
        ebx_3 = 0x800;

    int32_t eax_11 = ecx_7 & 0x6000;
    int32_t edx_4;

    if (eax_11 > 0x4000)
    {
        if (eax_11 != 0x6000)
            edx_4 = 0;
        else
            edx_4 = 0x300;
    }
    else if (eax_11 == 0x4000)
        edx_4 = 0x200;
    else if (!eax_11 || eax_11 != 0x2000)
        edx_4 = 0;
    else
        edx_4 = 0x100;

    int32_t esi_13 = (((((ecx_7 >> 2 & 0x400) | (ecx_7 & 0x800)) >> 2 | (ecx_7 & 0x400)) >> 2
        | (ecx_7 & 0x200)) >> 3 | (ecx_7 & 0x180)) >> 3 | ebx_3 | edx_4;
    return ((((esi_13 & 0xffffff00) | (esi_13 & 0x3f) << 2) << 6 | (edi_12 & 0x3f)) << 2
        | (edi_12 & 0x300)) << 0xe | esi_13 | edi_12;
}

int32_t sub_40cb30(int32_t arg1 @ mxcsr)
{
    int16_t ecx;
    int16_t var_8 = ecx;
    int32_t edi;
    int32_t var_10 = edi;
    var_8 = 0;
    bool c0;
    bool c1;
    bool c2;
    bool c3;
    uint32_t edx =
        (c0 ? 1 : 0) << 8 | (c1 ? 1 : 0) << 9 | (c2 ? 1 : 0) << 0xa | (c3 ? 1 : 0) << 0xe;
    int32_t esi_8 = (((edx >> 2 & 8) | (edx & 0x10)) >> 2 | (edx & 8)) >> 1
        | (((edx & 2) << 3 | (edx & 4)) * 2) | (edx & 1) << 4;
    int32_t edi_1;

    if (data_41eae8 >= 1)
        edi_1 = arg1 & 0x3f;
    else
        edi_1 = 0;

    int32_t edx_11 = (((edi_1 >> 2 & 8) | (edi_1 & 0x10)) >> 2 | (edi_1 & 8)) >> 1
        | (((edi_1 & 2) << 3 | (edi_1 & 4)) * 2) | (edi_1 & 1) << 4;
    return (edx_11 << 8 | esi_8) << 0x10 | edx_11 | esi_8;
}

uint32_t sub_40cbe0(int32_t arg1 @ mxcsr, int32_t arg2)
{
    int32_t edi;
    int32_t var_34 = edi;
    int32_t edx_3 = (arg2 >> 0x10 & 0x3f) | (arg2 >> 0xe & 0x300);
    int32_t eax_4 = arg2 & 0x4000;
    int32_t ebx;

    if (!eax_4)
        ebx = 0;
    else
    {
        ebx = 0x1000;

        if (eax_4 != 0x4000)
            ebx = 0;
    }

    int32_t eax_6 = arg2 & 0x3000;
    int32_t var_8;

    if (!eax_6)
        var_8 = 0x300;
    else if (eax_6 == 0x1000)
        var_8 = 0x200;
    else
        var_8 = 0;

    int32_t eax_8 = edx_3 & 0x300;
    int32_t esi;

    if (eax_8 > 0x200)
    {
        if (eax_8 == 0x300)
            esi = 0xc00;
        else
            esi = 0;
    }
    else if (eax_8 == 0x200)
        esi = 0x800;
    else if (!eax_8 || eax_8 != 0x100)
        esi = 0;
    else
        esi = 0x400;

    int32_t eax_10 = edx_3 & 1;
    int32_t eax_11 = -(eax_10);
    int128_t var_28;
    __builtin_memset(&var_28, 0, 0x1c);
    int32_t eax_15 = edx_3 & 2;
    int32_t eax_16 = -(eax_15);
    int32_t eax_20 = edx_3 & 4;
    int32_t eax_21 = -(eax_20);
    int32_t eax_25 = edx_3 & 8;
    int32_t eax_26 = -(eax_25);
    int32_t ecx_3 = ((eax_11 - eax_11) & 0x20) | ((eax_16 - eax_16) & 0x10)
        | ((eax_21 - eax_21) & 8) | ((eax_26 - eax_26) & 4);
    int32_t eax_29 = 0;
    eax_29 = edx_3 & 0x10;
    int32_t edx_4 = edx_3 & 0x20;
    int32_t edx_5 = -(edx_4);
    int16_t x87status;
    uint224_t temp0;
    temp0 = __fnstenv_memmem28();
    var_28 = temp0;
    var_28 = (var_28 & 0xffffe0c0)
        | ((esi | ecx_3 | eax_29 | ((edx_5 - edx_5) & 2) | var_8 | ebx) & 0x1f3f);
    __fldenv_memmem28(var_28);
    int32_t edi_2 = arg2 & 0xc00;
    int32_t esi_8 = (arg2 >> 0x18 & 0x3f) | (arg2 >> 0x16 & 0x300);
    int16_t ebx_1;

    if (edi_2 == 0x400)
    {
        int32_t var_c_1 = 0x8040;
        ebx_1 = -0x7fc0;
    }
    else if (edi_2 == 0x800)
        ebx_1 = 0x40;
    else
    {
        ebx_1 = -0x8000;

        if (edi_2 != 0xc00)
            ebx_1 = 0;
    }

    int32_t eax_34 = esi_8 & 0x300;
    int16_t edx_8;

    if (eax_34 > 0x200)
    {
        if (eax_34 == 0x300)
            edx_8 = 0x6000;
        else
            edx_8 = 0;
    }
    else if (eax_34 == 0x200)
        edx_8 = 0x4000;
    else if (!eax_34 || eax_34 != 0x100)
        edx_8 = 0;
    else
        edx_8 = 0x2000;

    int32_t eax_36 = esi_8 & 1;
    int32_t eax_37 = -(eax_36);
    int32_t eax_41 = esi_8 & 2;
    int32_t eax_42 = -(eax_41);
    int32_t eax_46 = esi_8 & 4;
    int32_t eax_47 = -(eax_46);
    int32_t eax_51 = esi_8 & 8;
    int32_t eax_52 = -(eax_51);
    int16_t ecx_12 = ((eax_37 - eax_37) & 0x1000) | ((eax_42 - eax_42) & 0x800)
        | ((eax_47 - eax_47) & 0x400) | ((eax_52 - eax_52) & 0x200);
    int32_t eax_56 = esi_8 & 0x10;
    int32_t eax_57 = -(eax_56);
    int32_t esi_9 = esi_8 & 0x20;
    uint32_t result = (eax_57 - eax_57) & 0x80;
    int32_t esi_10 = -(esi_9);

    if (data_41eae8 >= 1)
    {
        result = (edx_8 | ecx_12 | result | ((esi_10 - esi_10) & 0x100) | ebx_1) & 0xffc0;
        int32_t var_8_2 = (arg1 & 0xffff003f) | result;
    }

    return result;
}

int32_t sub_40ce30(int32_t arg1 @ mxcsr, int32_t arg2)
{
    int32_t ecx_2 = arg2 >> 0x10 & 0x3f;
    int32_t edx_1 = ecx_2 & 1;
    int32_t edx_2 = -(edx_1);
    int128_t var_24;
    __builtin_memset(&var_24, 0, 0x1c);
    int32_t eax_1 = ecx_2 & 2;
    int32_t eax_2 = -(eax_1);
    int32_t eax_6 = ecx_2 & 4;
    int32_t eax_7 = -(eax_6);
    int32_t eax_11 = ecx_2 & 8;
    int32_t eax_12 = -(eax_11);
    int32_t edx_7 = ((edx_2 - edx_2) & 0x20) | ((eax_2 - eax_2) & 0x10) | ((eax_7 - eax_7) & 8)
        | ((eax_12 - eax_12) & 4);
    int32_t eax_15 = 0;
    eax_15 = ecx_2 & 0x10;
    int32_t ecx_3 = ecx_2 & 0x20;
    int32_t ecx_4 = -(ecx_3);
    int16_t x87status;
    uint224_t temp0;
    temp0 = __fnstenv_memmem28();
    var_24 = temp0;
    *(&var_24 + 4) =
        (*(&var_24 + 4) & 0xffffffc0) | ((edx_7 | eax_15 | ((ecx_4 - ecx_4) & 2)) & 0x3f);
    __fldenv_memmem28(var_24);
    int32_t esi_2 = arg2 >> 0x18 & 0x3f;
    int32_t ecx_8 = esi_2 & 1;
    int32_t ecx_9 = -(ecx_8);
    int32_t eax_20 = esi_2 & 2;
    int32_t eax_21 = -(eax_20);
    int32_t eax_25 = esi_2 & 4;
    int32_t eax_26 = -(eax_25);
    int32_t eax_30 = esi_2 & 8;
    int32_t eax_31 = -(eax_30);
    int32_t ecx_14 = ((ecx_9 - ecx_9) & 0x20) | ((eax_21 - eax_21) & 0x10) | ((eax_26 - eax_26) & 8)
        | ((eax_31 - eax_31) & 4);
    int32_t result = 0;
    result = esi_2 & 0x10;
    int32_t esi_3 = esi_2 & 0x20;
    int32_t esi_4 = -(esi_3);

    if (data_41eae8 >= 1)
    {
        result = (arg1 & 0xffffffc0) | ((ecx_14 | result | ((esi_4 - esi_4) & 2)) & 0x3f);
        int32_t result_1 = result;
    }

    return result;
}

int32_t sub_40cf40(int32_t arg1, int32_t arg2)
{
    if (!arg1 || COMBINE(0, 0xffffffe0) / arg1 >= arg2)
    {
        uint32_t dwBytes = arg1 * arg2;

        if (!dwBytes)
            dwBytes = 1;

        int32_t i;

        do
        {
            int32_t result = HeapAlloc(data_41f110, HEAP_ZERO_MEMORY, dwBytes);

            if (result)
                return result;

            if (!sub_409070())
                break;

            i = __callnewh(dwBytes);
        } while (i);
    }

    *sub_40a844() = 0xc;
    return 0;
}

int32_t sub_40cfa0(int32_t arg1, int32_t arg2) __pure
{
    bool c = arg2 < arg1;

    if (arg2 == arg1 || c)
        return -((arg2 - arg2));

    return 0xffffffff;
}

int32_t __acrt_convert_wcs_mbs_cp<char,wchar_t,class <lambda_62f6974d9771e494a5ea317cc32e971c>,struct __crt_win32_buffer_internal_dynamic_resizing>(char* arg1, void* arg2, uint32_t arg3 @ 0x10)
{
    int32_t edi;
    int32_t var_c = edi;

    if (!arg1)
    {
        sub_40d711(arg2);
        *(arg2 + 8) = 0;
        *(arg2 + 0xc) = 0;
        *(arg2 + 0x10) = 0;
    }
    else
    {
        int32_t result;

        if (*arg1)
        {
            int32_t eax_2 = ___acrt_MultiByteToWideChar(arg3, 9, arg1, 0xffffffff, nullptr, 0);
            int32_t eax_5;

            if (eax_2)
            {
                if (eax_2 > *(arg2 + 0xc))
                {
                    result = sub_40d767(arg2, eax_2);

                    if (result)
                        return result;
                }

                eax_5 = ___acrt_MultiByteToWideChar(arg3, 9, arg1, 0xffffffff, *(arg2 + 8),
                    *(arg2 + 0xc));
            }

            if (!eax_2 || !eax_5)
            {
                ___acrt_errno_map_os_error(GetLastError());
                return *sub_40a844();
            }

            *(arg2 + 0x10) = eax_5 - 1;
        }
        else
        {
            if (!*(arg2 + 0xc))
                result = sub_40d767(arg2, 1);

            if (!*(arg2 + 0xc) && result)
                return result;

            **(arg2 + 8) = 0;
            *(arg2 + 0x10) = 0;
        }
    }

    return 0;
}

int32_t sub_40d06a(int16_t* arg1, void* arg2, int32_t arg3, uint32_t arg4)
{
    void* esi_1;

    if (arg1)
    {
        int32_t result;

        if (*arg1)
        {
            uint32_t eax_2 = sub_40e427(arg4, 0, arg1, 0xffffffff, nullptr, 0, nullptr, nullptr);

            if (!eax_2)
            {
                ___acrt_errno_map_os_error(GetLastError());
                return *sub_40a844();
            }

            int32_t edi;
            int32_t var_10_2 = edi;

            if (eax_2 <= *(arg2 + 0xc))
            {
            label_40d106:
                int32_t eax_5 = sub_40d6ae(arg4, arg1, *(arg2 + 8), *(arg2 + 0xc));

                if (eax_5)
                {
                    *(arg2 + 0x10) = eax_5 - 1;
                    result = 0;
                }
                else
                {
                    ___acrt_errno_map_os_error(GetLastError());
                    result = *sub_40a844();
                }
            }
            else
            {
                result = sub_40d72b(arg2, eax_2);

                if (!result)
                    goto label_40d106;
            }

            return result;
        }

        esi_1 = arg2;

        if (!*(esi_1 + 0xc))
        {
            result = sub_40d72b(esi_1, 1);

            if (result)
                return result;
        }

        **(esi_1 + 8) = 0;
    }
    else
    {
        esi_1 = arg2;
        sub_40d711(esi_1);
        *(esi_1 + 8) = 0;
        *(esi_1 + 0xc) = 0;
    }

    *(esi_1 + 0x10) = 0;
    return 0;
}

int32_t __convention("regparm") __acrt_mbs_to_wcs_cp<struct __crt_win32_buffer_internal_dynamic_resizing>(int32_t arg1, int32_t arg2, int32_t arg3, char* arg4, void* arg5, uint32_t arg6)
{
    int32_t var_8 = arg3;
    void* var_10 = (&var_8 + 3);
    return __acrt_convert_wcs_mbs_cp<char,wchar_t,class <lambda_62f6974d9771e494a5ea317cc32e971c>,struct __crt_win32_buffer_internal_dynamic_resizing>(
        arg4, arg5, arg6);
}

int32_t sub_40d14d(int32_t* arg1, int32_t* arg2)
{
    if (!arg2)
    {
        *sub_40a844() = 0x16;
        __invalid_parameter_noinfo();
        return 0x16;
    }

    *arg2 = 0;
    int32_t ecx_1 = 0;
    int32_t var_1c_1 = 0;
    int32_t* ebx_1 = arg1;
    int32_t edi;
    int32_t var_30_1 = edi;
    int32_t* i_3 = nullptr;
    int32_t var_20_1 = 0;
    int32_t* i_4 = nullptr;
    char* i = *ebx_1;
    int16_t var_8;
    int32_t result_1;

    if (i)
    {
        do
        {
            var_8 = 0x3f2a;
            char var_6_1 = 0;
            char* eax_2 = _strpbrk(i, &var_8);

            if (eax_2)
            {
                int32_t result_2 = sub_40d37b(*ebx_1, eax_2, &i_4);

                if (result_2)
                {
                    result_1 = result_2;
                    goto label_40d237;
                }
            }
            else
            {
                result_1 = sub_40d2ca(*ebx_1, 0, nullptr, &i_4);

                if (result_1)
                    goto label_40d237;
            }

            ebx_1 = &ebx_1[1];
            i = *ebx_1;
        } while (i);

        i_3 = i_4;
        ecx_1 = var_20_1;
    }

    int32_t* i_1 = i_3;
    void* eax_4 = nullptr;

    for (; i_1 != ecx_1; i_1 = &i_1[1])
    {
        char* edx_1 = *i_1;
        char j;

        do
        {
            j = *edx_1;
            edx_1 = &edx_1[1];
        } while (j);
        eax_4 = eax_4 + 1 + edx_1 - &edx_1[1];
    }

    int32_t eax_8 = ___acrt_allocate_buffer_for_argv(((ecx_1 - i_3) >> 2) + 1, eax_4, 1);
    int32_t result;

    if (eax_8)
    {
        char* eax_9 = eax_8 + ((((ecx_1 - i_3) >> 2) + 1) << 2);
        char* edx_3 = eax_9;
        var_8 = edx_3;

        if (i_3 != var_20_1)
        {
            int32_t* eax_11 = eax_8 - i_3;

            do
            {
                char* ecx_5 = *i_3;
                void* eax_12 = &ecx_5[1];
                char i_2;

                do
                {
                    i_2 = *ecx_5;
                    ecx_5 = &ecx_5[1];
                } while (i_2);

                if (sub_412460(edx_3, eax_9 - edx_3 + eax_4, *i_3, ecx_5 - eax_12 + 1))
                {
                    int32_t var_44;
                    __builtin_memset(&var_44, 0, 0x14);
                    sub_40a6d6();
                    /* no return */
                }

                void* edx_4 = var_8;
                *(eax_11 + i_3) = edx_4;
                i_3 = &i_3[1];
                edx_3 = edx_4 + ecx_5 - eax_12 + 1;
                var_8 = edx_3;
            } while (i_3 != var_20_1);
        }

        *arg2 = eax_8;
        __free_base(0);
        sub_40d689(&i_4);
        result = 0;
    }
    else
    {
        __free_base(eax_8);
        result_1 = 0xffffffff;
    label_40d237:
        sub_40d689(&i_4);
        result = result_1;
    }

    return result;
}

int32_t sub_40d2ca(char* arg1, int32_t arg2, void* arg3, int32_t* arg4)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    char* ecx_1 = arg1;
    void* edx = &ecx_1[1];
    char i;

    do
    {
        i = *ecx_1;
        ecx_1 = &ecx_1[1];
    } while (i);
    int32_t edi;
    int32_t var_c = edi;

    if (ecx_1 - edx + 1 > ~arg3)
        return 0xc;

    void* ebx_2 = arg3 + 1 + ecx_1 - edx + 1;
    char* eax_4 = sub_40cf40(ebx_2, 1);

    if (!arg3)
    {
    label_40d32b:

        if (!sub_412460(eax_4 + arg3, ebx_2 - arg3, arg1, ecx_1 - edx + 1))
        {
            int32_t result_1 = sub_40d7c7(arg4);
            int32_t result;

            if (!result_1)
            {
                *arg4[1] = eax_4;
                result = 0;
                arg4[1] += 4;
            }
            else
            {
                __free_base(eax_4);
                result = result_1;
            }

            __free_base(0);
            return result;
        }
    }
    else if (!sub_412460(eax_4, ebx_2, arg2, arg3))
        goto label_40d32b;

    int32_t var_28;
    __builtin_memset(&var_28, 0, 0x14);
    sub_40a6d6();
    /* no return */
}

int32_t sub_40d37b(char* arg1, char* arg2, int32_t* arg3)
{
    int32_t __saved_ebp;
    char* var_8 = __security_cookie ^ &__saved_ebp;
    char* ecx = arg2;
    int32_t* edx = arg3;
    int32_t edi;
    int32_t var_2a4 = edi;
    int32_t* var_260 = edx;

    if (ecx != arg1)
    {
        do
        {
            char eax_2 = *ecx;

            if (eax_2 == 0x2f)
                break;

            if (eax_2 == 0x5c)
                break;

            if (eax_2 == 0x3a)
                break;

            ecx = __mbsdec(arg1, ecx);
        } while (ecx != arg1);

        edx = var_260;
    }

    char eax_4 = *ecx;
    char var_259 = eax_4;

    if (eax_4 != 0x3a)
        goto label_40d3fc;

    int32_t result;

    if (ecx == &arg1[1])
    {
        eax_4 = var_259;
    label_40d3fc:

        if (eax_4 == 0x2f || eax_4 == 0x5c)
            eax_4 = 1;
        else
        {
            bool cond:0_1 = eax_4 != 0x3a;
            eax_4 = 0;

            if (!cond:0_1)
                eax_4 = 1;
        }

        int32_t var_290 = 0;
        int32_t var_28c_1 = 0;
        void* edx_1 = nullptr;
        PWSTR lpFileName_1 = nullptr;
        int32_t var_284_1 = 0;

        if (eax_4)
            edx_1 = ecx - arg1 + 1;

        int32_t var_280_1 = 0;
        char var_27c_1 = 0;
        uint32_t eax_5;
        int32_t ecx_3;
        int32_t edx_2;
        eax_5 = __acrt_get_utf8_acp_compatibility_codepage();
        PWSTR lpFileName = lpFileName_1;

        if (__acrt_mbs_to_wcs_cp<struct __crt_win32_buffer_internal_dynamic_resizing>(&var_290,
                edx_2, ecx_3, arg1, &var_290, eax_5))
            lpFileName = nullptr;

        WIN32_FIND_DATAW findFileData;
        HANDLE hFindFile = FindFirstFileExW(lpFileName, FindExInfoStandard, &findFileData,
            FindExSearchNameMatch, nullptr, 0);

        if (hFindFile != 0xffffffff)
        {
            int32_t ecx_7 = (var_260[1] - *var_260) >> 2;

            while (true)
            {
                int32_t var_278;
                __builtin_memset(&var_278, 0, 0x15);
                char* var_270;
                char* ecx_8 = var_270;
                var_22c;

                if (sub_40d06a(&var_22c, &var_278, &var_259,
                        __acrt_get_utf8_acp_compatibility_codepage()))
                    ecx_8 = nullptr;

                char eax_11;

                if (*ecx_8 == 0x2e)
                    eax_11 = ecx_8[1];

                bool cond:3_1;
                char var_264;

                if (*ecx_8 != 0x2e || (eax_11 && (eax_11 != 0x2e || ecx_8[2])))
                {
                    int32_t result_2 = sub_40d2ca(ecx_8, arg1, edx_1, var_260);

                    if (result_2)
                    {
                        if (var_264)
                            __free_base(var_270);

                        FindClose(hFindFile);

                        if (var_27c_1)
                            __free_base(lpFileName_1);

                        result = result_2;
                        break;
                    }

                    cond:3_1 = !var_264;
                }
                else
                    cond:3_1 = !var_264;

                if (!cond:3_1)
                    __free_base(var_270);

                if (!FindNextFileW(hFindFile, &findFileData))
                {
                    int32_t edx_3 = *var_260;
                    int32_t eax_16 = (var_260[1] - edx_3) >> 2;

                    if (ecx_7 != eax_16)
                        sub_412020(edx_3 + (ecx_7 << 2), eax_16 - ecx_7, 4, sub_40cfa0);

                    FindClose(hFindFile);

                    if (var_27c_1)
                        __free_base(lpFileName_1);

                    result = 0;
                    break;
                }
            }
        }
        else
        {
            int32_t result_1 = sub_40d2ca(arg1, 0, nullptr, var_260);

            if (var_27c_1)
                __free_base(lpFileName_1);

            result = result_1;
        }
    }
    else
        result = sub_40d2ca(arg1, 0, nullptr, edx);

    sub_402910(var_8 ^ &__saved_ebp);
    return result;
}

void** __thiscall _LocaleUpdate::_LocaleUpdate(void** arg1, int32_t* arg2)
{
    int32_t edi;
    int32_t var_c = edi;
    arg1[3] = 0;
    void* ecx_1;

    if (arg2)
    {
        ecx_1 = arg2[1];
        arg1[1] = *arg2;
        arg1[2] = ecx_1;
    }
    else if (data_41eca8)
    {
        int32_t* eax_1 = sub_409b74();
        *arg1 = eax_1;
        arg1[1] = eax_1[0x13];
        arg1[2] = eax_1[0x12];
        ___acrt_update_locale_info(eax_1, &arg1[1]);
        ___acrt_update_multibyte_info(*arg1, &arg1[2]);
        void* ecx_4 = *arg1;
        int32_t eax_2 = *(ecx_4 + 0x350);

        if (!(eax_2 & 2))
        {
            *(ecx_4 + 0x350) = eax_2 | 2;
            arg1[3] = 1;
        }
    }
    else
    {
        ecx_1 = data_41e34c;
        arg1[1] = data_41e348;
        arg1[2] = ecx_1;
    }
    return arg1;
}

int32_t __fastcall sub_40d689(int32_t* arg1)
{
    int32_t edi;
    int32_t var_8 = edi;

    for (int32_t* i = *arg1; i != arg1[1]; i = &i[1])
        __free_base(*i);

    return __free_base(*arg1);
}

int32_t __stdcall sub_40d6ae(uint32_t arg1, wchar16* arg2, PSTR arg3, int32_t arg4)
{
    return sub_40e427(arg1, 0, arg2, 0xffffffff, arg3, arg4, nullptr, nullptr);
}

int32_t __acrt_get_utf8_acp_compatibility_codepage()
{
    void* var_14;
    _LocaleUpdate::_LocaleUpdate(&var_14, nullptr);
    int32_t result = 0xfde9;
    void* var_10;

    if (*(var_10 + 8) != 0xfde9)
    {
        result = 0;

        if (!___acrt_AreFileApisANSI@0())
            result = 1;
    }

    char var_8;

    if (var_8)
    {
        void* ecx_1 = var_14;
        *(ecx_1 + 0x350) &= 0xfffffffd;
    }

    return result;
}

void __fastcall sub_40d711(void* arg1)
{
    if (*(arg1 + 0x14))
    {
        __free_base(*(arg1 + 8));
        *(arg1 + 0x14) = 0;
    }
}

int32_t __thiscall sub_40d72b(void* arg1, uint32_t arg2)
{
    int32_t edi;
    int32_t var_c = edi;
    sub_40d711(arg1);
    void* var_10 = arg1;
    int32_t result = sub_40d7a6(arg1 + 8, arg2);

    if (!result)
    {
        *(arg1 + 0x14) = 1;
        result = 0;
        *(arg1 + 0xc) = arg2;
    }
    else
    {
        *(arg1 + 0xc) = 0;
        *(arg1 + 0x14) = 0;
    }

    return result;
}

int32_t __thiscall sub_40d767(void* arg1, int32_t arg2)
{
    int32_t edi;
    int32_t var_c = edi;
    sub_40d711(arg1);
    void* var_10 = arg1;
    int32_t result = sub_40d7a6(arg1 + 8, arg2 * 2);

    if (!result)
    {
        *(arg1 + 0x14) = 1;
        result = 0;
        *(arg1 + 0xc) = arg2;
    }
    else
    {
        *(arg1 + 0xc) = 0;
        *(arg1 + 0x14) = 0;
    }

    return result;
}

int32_t sub_40d7a6(int32_t* arg1, uint32_t arg2)
{
    int32_t eax = sub_40a8b0(arg2);
    *arg1 = eax;

    if (!eax)
        return 0xc;

    return 0;
}

int32_t __fastcall sub_40d7c7(int32_t* arg1)
{
    int32_t edi;
    int32_t var_8 = edi;
    int32_t edi_1 = arg1[2];

    if (arg1[1] == edi_1)
    {
        if (*arg1)
        {
            int32_t edi_3 = (edi_1 - *arg1) >> 2;

            if (edi_3 > 0x7fffffff)
                return 0xc;

            int32_t ebx_1 = edi_3 * 2;
            int32_t eax_5 = __recalloc_base(*arg1, ebx_1, 4);
            int32_t result;

            if (eax_5)
            {
                *arg1 = eax_5;
                arg1[1] = eax_5 + (edi_3 << 2);
                arg1[2] = eax_5 + (ebx_1 << 2);
                result = 0;
            }
            else
                result = 0xc;

            __free_base(0);
            return result;
        }

        *arg1 = sub_40cf40(4, 4);
        __free_base(0);
        int32_t eax_2 = *arg1;

        if (!eax_2)
            return 0xc;

        arg1[1] = eax_2;
        arg1[2] = eax_2 + 0x10;
    }

    return 0;
}

int32_t sub_40d84e()
{
    /* tailcall */
    return sub_40d14d();
}

int32_t __acrt_convert_wcs_mbs_cp<wchar_t,char,class <lambda_0fec1a7b3f42a53036604e18c2d5e07e>,struct __crt_win32_buffer_no_resizing>(int16_t* arg1, void* arg2, int32_t arg3, uint32_t arg4)
{
    if (!arg1)
    {
        sub_40d942(arg2);
        return 0;
    }

    int32_t result;

    if (*arg1)
    {
        int32_t eax_2 = sub_40e427(arg4, 0, arg1, 0xffffffff, nullptr, 0, nullptr, nullptr);

        if (!eax_2)
        {
            ___acrt_errno_map_os_error(GetLastError());
            return *sub_40a844();
        }

        int32_t edi;
        int32_t var_10_3 = edi;

        if (eax_2 <= *(arg2 + 0xc))
        {
            int32_t eax_5 = sub_40d6ae(arg4, arg1, *(arg2 + 8), *(arg2 + 0xc));

            if (eax_5)
            {
                *(arg2 + 0x10) = eax_5 - 1;
                result = 0;
            }
            else
            {
                ___acrt_errno_map_os_error(GetLastError());
                result = *sub_40a844();
            }
        }
        else
        {
            int32_t var_14_1 = eax_2;
            result = sub_40d91b(arg2);
        }
    }
    else
    {
        if (!*(arg2 + 0xc))
        {
            int32_t var_10_1 = 1;
            return sub_40d91b(arg2);
        }

        **(arg2 + 8) = 0;
        result = 0;
        *(arg2 + 0x10) = 0;
    }

    return result;
}

int32_t __fastcall sub_40d91b(void* arg1)
{
    if (*(arg1 + 0x14))
        *(arg1 + 0x14) = 0;

    *sub_40a844() = 0x22;
    *(arg1 + 0xc) = 0;
    *(arg1 + 0x14) = 0;
    return 0x22;
}

int32_t __fastcall sub_40d942(void* arg1)
{
    if (*(arg1 + 0x14))
        *(arg1 + 0x14) = 0;

    *(arg1 + 8) = 0;
    *(arg1 + 0xc) = 0;
    *(arg1 + 0x10) = 0;
    return 0;
}

int32_t ___acrt_GetModuleFileNameA(HMODULE arg1, int32_t arg2, int32_t arg3)
{
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    void filename;
    int32_t result;

    if (GetModuleFileNameW(arg1, &filename, 0x105))
    {
        int32_t result_1 = 0;
        int32_t var_230 = arg2;
        int32_t var_22c_1 = arg3;
        int32_t var_228_1 = arg2;
        int32_t var_224_1 = arg3;
        char var_21c_1 = 0;
        void var_215;
        __acrt_convert_wcs_mbs_cp<wchar_t,char,class <lambda_0fec1a7b3f42a53036604e18c2d5e07e>,struct __crt_win32_buffer_no_resizing>(
            &filename, &var_230, &var_215, __acrt_get_utf8_acp_compatibility_codepage());
        result = result_1;
    }
    else
    {
        ___acrt_errno_map_os_error(GetLastError());
        result = 0;
    }

    sub_402910(eax_1 ^ &__saved_ebp);
    return result;
}

int32_t __stdcall sub_40d9f7(int32_t* arg1, int32_t* arg2)
{
    int32_t __saved_ebp_1 = 8;
    int32_t var_8 = 0x41cd80;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41cd80 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_2c = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_2c;
    void* const var_30_1 = &data_40da03;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    ___acrt_lock(*arg1);
    int32_t var_8_1 = 0;
    sub_40da44(arg2);
    int32_t var_8_2 = 0xfffffffe;
    int32_t result = $LN15(&__saved_ebp);
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t $LN15(void* arg1 @ ebp)
{
    return ___acrt_unlock(**(arg1 + 0x10));
}

int32_t* __fastcall sub_40da44(int32_t* arg1)
{
    _memcpy_s(data_41ef6c, 0x101, *(**arg1 + 0x48) + 0x18, 0x101);
    _memcpy_s(data_41ef70, 0x100, *(**arg1 + 0x48) + 0x119, 0x100);
    int32_t* eax_10 = **arg1[1];
    bool cond:0 = *eax_10 != 1;
    *eax_10;
    *eax_10 -= 1;

    if (!cond:0)
    {
        int32_t* eax_12 = *arg1[1];

        if (*eax_12 != 0x41e358)
            __free_base(*eax_12);
    }

    **arg1[1] = *(**arg1 + 0x48);
    int32_t* result = *(**arg1 + 0x48);
    *result += 1;
    return result;
}

int32_t CPtoLocaleName(int32_t arg1) __pure
{
    if (arg1 == 0x3a4)
        return u"ja-JP";

    if (arg1 == 0x3a8)
        return u"zh-CN";

    if (arg1 == 0x3b5)
        return u"ko-KR";

    if (arg1 == 0x3b6)
        return u"zh-TW";

    return 0;
}

uint32_t getSystemCP(uint32_t arg1)
{
    void* var_14;
    _LocaleUpdate::_LocaleUpdate(&var_14, nullptr);
    data_41ef78 = 0;
    uint32_t result = arg1;

    if (result == 0xfffffffe)
    {
        data_41ef78 = 1;
        result = GetOEMCP();
    }
    else if (result == 0xfffffffd)
    {
        data_41ef78 = 1;
        result = GetACP();
    }
    else if (result == 0xfffffffc)
    {
        data_41ef78 = 1;
        void* var_10;
        result = *(var_10 + 8);
    }

    char var_8;

    if (var_8)
    {
        void* ecx_1 = var_14;
        *(ecx_1 + 0x350) &= 0xfffffffd;
    }

    return result;
}

int32_t setSBCS(void* arg1)
{
    int32_t edi;
    int32_t var_10 = edi;
    void* i_1 = nullptr;
    _memset(arg1 + 0x18, 0, 0x101);
    *(arg1 + 4) = 0;
    *(arg1 + 8) = 0;
    *(arg1 + 0x21c) = 0;
    *(arg1 + 0xc) = 0;
    int32_t* edi_2 = arg1 + 0x10;
    void* i = nullptr;
    *edi_2 = 0;
    edi_2[1] = 0;

    do
    {
        *(arg1 + i + 0x18) = *(i + 0x41e370);
        i += 1;
    } while (i < 0x101);

    char result;

    do
    {
        result = *(i_1 + 0x41e471);
        *(arg1 + i_1 + 0x119) = result;
        i_1 += 1;
    } while (i_1 < 0x100);

    return result;
}

char* setSBUpLow(void* arg1)
{
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    int32_t edi;
    int32_t var_730 = edi;
    char* result;

    if (*(arg1 + 4) == 0xfde9)
    {
    label_40dd15:
        char* ecx_2 = arg1 + 0x19;
        result = 0xffffffa6 - arg1;
        char* result_1 = result;

        do
        {
            char eax_6;

            if (result + ecx_2 <= 0x19)
            {
                *ecx_2 |= 0x10;
                eax_6 = ecx_2 + 0x20 + (0xffffffe7 - arg1);
            }
            else if (0xffffff86 - arg1 + ecx_2 > 0x19)
                eax_6 = 0;
            else
            {
                *ecx_2 |= 0x20;
                eax_6 = ecx_2 - 0x20 + (0xffffffe7 - arg1);
            }

            ecx_2[0x100] = eax_6;
            ecx_2 = &ecx_2[1];
            result = result_1;
        } while (ecx_2 + 0xffffffe7 - arg1 < 0x100);
    }
    else
    {
        CPINFO cPInfo;

        if (!GetCPInfo(*(arg1 + 4), &cPInfo))
            goto label_40dd15;

        int32_t i_3 = 0x100;
        uint8_t var_108[0x100];

        for (int32_t i = 0; i < 0x100; i += 1)
            var_108[i] = i;

        BYTE i_1 = cPInfo.LeadByte[0];
        var_716;
        BYTE* ecx = &var_716;
        var_108[0] = 0x20;

        for (; i_1; i_1 = *ecx)
        {
            uint32_t edx_1 = ecx[1];

            for (uint32_t j = i_1; j <= edx_1; j += 1)
            {
                if (j >= 0x100)
                    break;

                var_108[j] = 0x20;
            }

            ecx = &ecx[2];
        }

        uint16_t var_708[0x200];
        sub_40ebb3(nullptr, 1, &var_108, 0x100, &var_708, *(arg1 + 4), 0);
        WCHAR var_208[0x80];
        ___acrt_LCMapStringA(nullptr, *(arg1 + 0x21c), 0x100, &var_108, 0x100, &var_208, 0x100,
            *(arg1 + 4), 0);
        WCHAR var_308[0x80];
        ___acrt_LCMapStringA(nullptr, *(arg1 + 0x21c), 0x200, &var_108, 0x100, &var_308, 0x100,
            *(arg1 + 4), 0);
        result = arg1 + 0x19;
        int32_t ecx_1 = 0;
        int32_t i_2;

        do
        {
            char edx_2 = var_708[ecx_1];
            char edx_3;

            if (edx_2 & 1)
            {
                *result |= 0x10;
                edx_3 = *(&var_208 + ecx_1);
            }
            else if (!(edx_2 & 2))
                edx_3 = 0;
            else
            {
                *result |= 0x20;
                edx_3 = *(&var_308 + ecx_1);
            }

            ecx_1 += 1;
            result[0x100] = edx_3;
            result = &result[1];
            i_2 = i_3;
            i_3 -= 1;
        } while (i_2 != 1);
    }

    sub_402910(eax_1 ^ &__saved_ebp);
    return result;
}

int32_t setmbcp_internal(uint32_t arg1, char arg2, void* arg3, int32_t* arg4)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    int32_t var_c = ecx;
    void* const __return_addr_1 = __return_addr;
    int32_t edi;
    int32_t var_250 = edi;
    update_thread_multibyte_data_internal(arg3, arg4);
    uint32_t eax = getSystemCP(arg1);
    void* ecx_1 = arg3;
    uint32_t var_1c = eax;

    if (eax == *(*(ecx_1 + 0x48) + 4))
        return 0;

    int32_t* eax_1 = sub_40a8b0(0x220);
    int32_t* var_14 = eax_1;
    int32_t result;

    if (eax_1)
    {
        uint32_t var_258_1 = var_1c;
        void var_248;
        __builtin_memcpy(&var_248, *(arg3 + 0x48), 0x220);
        __builtin_memcpy(eax_1, &var_248, 0x220);
        *eax_1 = 0;
        int32_t result_1 = __setmbcp_nolock(var_258_1, eax_1);

        if (result_1 != 0xffffffff)
        {
            if (!arg2)
                sub_408fd1();

            int32_t* eax_5 = *(arg3 + 0x48);
            int32_t esi_3 = *eax_5;
            *eax_5 -= 1;

            if (esi_3 == 1)
            {
                void* eax_6 = arg3;

                if (*(eax_6 + 0x48) != 0x41e358)
                    __free_base(*(eax_6 + 0x48));
            }

            int32_t* eax_7 = var_14;
            *eax_7 = 1;
            *(arg3 + 0x48) = eax_7;

            if (!(*(arg3 + 0x350) & data_41e8d0))
            {
                void** var_24 = &arg3;
                int32_t** var_20_1 = &arg4;
                var_1c = 5;
                var_14 = 5;
                uint32_t* var_254_5 = &var_1c;
                sub_40d9f7(&var_14, &var_24);

                if (arg2)
                    data_41e34c = *arg4;
            }

            __free_base(nullptr);
            result = result_1;
        }
        else
        {
            *sub_40a844() = 0x16;
            __free_base(var_14);
            result = 0xffffffff;
        }
    }
    else
    {
        __free_base(eax_1);
        result = 0xffffffff;
    }

    return result;
}

int32_t* update_thread_multibyte_data_internal(void* arg1, int32_t* arg2)
{
    int32_t __saved_ebp_1 = 0xc;
    int32_t var_8 = 0x41cd60;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41cd60 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_1 = &data_40dedf;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t var_20 = 0;
    int32_t* result;

    if (!(*(arg1 + 0x350) & data_41e8d0) || !*(arg1 + 0x4c))
    {
        ___acrt_lock(5);
        int32_t var_8_1 = 0;
        result = *(arg1 + 0x48);
        int32_t* result_1 = result;

        if (result != *arg2)
        {
            if (result)
            {
                bool cond:0_1 = *result != 1;
                *result;
                *result -= 1;

                if (!cond:0_1 && result != 0x41e358)
                    __free_base(result);
            }

            result = *arg2;
            *(arg1 + 0x48) = result;
            int32_t* result_2 = result;
            *result += 1;
        }

        int32_t var_8_2 = 0xfffffffe;
        $LN13();
    }
    else
        result = *(arg1 + 0x48);

    if (!result)
    {
        sub_4096af();
        /* no return */
    }

    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t $LN13()
{
    return ___acrt_unlock(5);
}

int32_t ___acrt_initialize_multibyte()
{
    int32_t result;

    if (!data_41ef7c)
    {
        data_41ef74 = 0x41e358;
        data_41ef70 = 0x41e680;
        data_41ef6c = 0x41e578;
        result = setmbcp_internal(0xfffffffd, 1, sub_409b82(), &data_41ef74);
        data_41ef7c = 1;
    }

    result = 1;
    return result;
}

int32_t* ___acrt_update_thread_multibyte_data()
{
    return update_thread_multibyte_data_internal(sub_409b74(), &data_41ef74);
}

int32_t __setmbcp_nolock(uint32_t arg1, void* arg2)
{
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    int32_t edi;
    int32_t var_34 = edi;
    uint32_t CodePage = getSystemCP(arg1);
    int32_t result;

    if (!CodePage)
    {
        setSBCS(arg2);
        result = 0;
    }
    else
    {
        void* j = nullptr;
        int32_t ecx_1 = 0;
        void* i = nullptr;
        int32_t var_20_1 = 0;

        do
        {
            if (*(i + 0x41e788) == CodePage)
            {
                _memset(arg2 + 0x18, 0, 0x101);
                void* eax_10 = var_20_1 * 0x30;
                uint32_t eax_11 = eax_10 + 0x41e798;
                uint32_t var_20_2 = eax_11;

                do
                {
                    char* ecx_3 = eax_11;

                    if (*eax_11)
                    {
                        do
                        {
                            char eax_12 = ecx_3[1];

                            if (!eax_12)
                                break;

                            uint32_t k = *ecx_3;

                            if (k <= eax_12)
                            {
                                char* ebx_2 = arg2 + 0x19 + k;

                                while (k < 0x100)
                                {
                                    *ebx_2 |= *(j + 0x41e780);
                                    k += 1;
                                    ebx_2 = &ebx_2[1];

                                    if (k > ecx_3[1])
                                        break;
                                }
                            }

                            ecx_3 = &ecx_3[2];
                        } while (*ecx_3);

                        eax_11 = var_20_2;
                    }

                    j += 1;
                    eax_11 += 8;
                    var_20_2 = eax_11;
                } while (j < 4);

                *(arg2 + 4) = CodePage;
                *(arg2 + 8) = 1;
                *(arg2 + 0x21c) = CPtoLocaleName(CodePage);
                int16_t* ecx_4 = arg2 + 0xc;
                int16_t* edx_3 = eax_10 + 0x41e78c;
                int32_t j_2 = 6;
                int32_t j_1;

                do
                {
                    int16_t eax_16 = *edx_3;
                    edx_3 = &edx_3[1];
                    *ecx_4 = eax_16;
                    ecx_4 = &ecx_4[1];
                    j_1 = j_2;
                    j_2 -= 1;
                } while (j_1 != 1);
                goto label_40e1b4;
            }

            ecx_1 += 1;
            i += 0x30;
            var_20_1 = ecx_1;
        } while (i < 0xf0);

        if (CodePage == 0xfde8)
            result = 0xffffffff;
        else if (!IsValidCodePage(CodePage))
            result = 0xffffffff;
        else if (CodePage != 0xfde9)
        {
            CPINFO cPInfo;

            if (GetCPInfo(CodePage, &cPInfo))
            {
                _memset(arg2 + 0x18, 0, 0x101);
                *(arg2 + 4) = CodePage;
                bool cond:1_1 = cPInfo.MaxCharSize != 2;
                *(arg2 + 0x21c) = 0;

                if (!cond:1_1)
                {
                    var_16;
                    char* eax_6 = &var_16;

                    if (cPInfo.LeadByte[0])
                    {
                        do
                        {
                            char i_5 = eax_6[1];

                            if (!i_5)
                                break;

                            uint32_t edi_5 = *eax_6;
                            uint32_t i_3 = i_5;

                            if (edi_5 <= i_3)
                            {
                                char* edx_2 = arg2 + 0x19 + edi_5;
                                i_3 = i_3 - edi_5 + 1;
                                uint32_t i_1;

                                do
                                {
                                    *edx_2 |= 4;
                                    edx_2 = &edx_2[1];
                                    i_1 = i_3;
                                    i_3 -= 1;
                                } while (i_1 != 1);
                            }

                            eax_6 = &eax_6[2];
                        } while (*eax_6);
                    }

                    char* eax_7 = arg2 + 0x1a;
                    int32_t i_4 = 0xfe;
                    int32_t i_2;

                    do
                    {
                        *eax_7 |= 8;
                        eax_7 = &eax_7[1];
                        i_2 = i_4;
                        i_4 -= 1;
                    } while (i_2 != 1);
                    *(arg2 + 0x21c) = CPtoLocaleName(*(arg2 + 4));
                    j = 1;
                }

                goto label_40e056;
            }

            if (data_41ef78)
            {
                setSBCS(arg2);
                result = 0;
            }
            else
                result = 0xffffffff;
        }
        else
        {
            *(arg2 + 4) = 0xfde9;
            *(arg2 + 0x21c) = 0;
            *(arg2 + 0x18) = 0;
            *(arg2 + 0x1c) = 0;
        label_40e056:
            *(arg2 + 8) = j;
            *(arg2 + 0xc) = 0;
            int32_t* edi_2 = arg2 + 0x10;
            *edi_2 = 0;
            edi_2[1] = 0;
        label_40e1b4:
            setSBUpLow(arg2);
            result = 0;
        }
    }

    sub_402910(eax_1 ^ &__saved_ebp);
    return result;
}

int32_t _memcpy_s(uint32_t (* arg1)[0x4], void* arg2, char* arg3, void* arg4)
{
    if (!arg4)
        return 0;

    if (!arg1)
    {
        *sub_40a844() = 0x16;
        __invalid_parameter_noinfo();
        return 0x16;
    }

    int32_t edi;
    int32_t var_c_1 = edi;
    int32_t result;

    if (!arg3 || arg2 < arg4)
    {
        _memset(arg1, 0, arg2);
        int32_t result_1;
        int32_t* eax_2;

        if (arg3)
        {
            if (arg2 < arg4)
            {
                eax_2 = sub_40a844();
                result_1 = 0x22;
                goto label_40e242;
            }

            result = 0x16;
        }
        else
        {
            eax_2 = sub_40a844();
            result_1 = 0x16;
        label_40e242:
            *eax_2 = result_1;
            __invalid_parameter_noinfo();
            result = result_1;
        }
    }
    else
    {
        sub_4035c0(arg1, arg3, arg4);
        result = 0;
    }

    return result;
}

int32_t x_ismbbtype_l(int32_t* arg1, char arg2, int32_t arg3, char arg4)
{
    void* var_14;
    _LocaleUpdate::_LocaleUpdate(&var_14, arg1);
    uint32_t edx = arg2;
    int32_t* var_10;
    int32_t var_c;
    int32_t result;

    if (*(var_c + edx + 0x19) & arg4 || (arg3 && arg3 & *(*var_10 + (edx << 1))))
        result = 1;
    else
        result = 0;

    char var_8;

    if (var_8)
    {
        void* ecx_4 = var_14;
        *(ecx_4 + 0x350) &= 0xfffffffd;
    }

    return result;
}

int32_t __ismbblead(char arg1)
{
    return x_ismbbtype_l(nullptr, arg1, 0, 4);
}

PWSTR ___acrt_initialize_command_line()
{
    data_41ef90 = GetCommandLineA();
    PWSTR result = GetCommandLineW();
    data_41ef94 = result;
    result = 1;
    return result;
}

int32_t filter_mbtowcs_flags(int32_t arg1, int32_t arg2) __pure
{
    int32_t eax_9;
    bool cond:3_1;
    bool cond:4_1;

    if (arg1 > 0xdeac)
    {
        if (arg1 > 0xdeb1)
        {
            if (arg1 != 0xdeb2 && arg1 != 0xdeb3 && arg1 != 0xfde8)
            {
                if (arg1 == 0xfde9)
                    return arg2 & 8;

                return arg2;
            }
        }
        else if (arg1 != 0xdeb1 && arg1 != 0xdead && arg1 != 0xdeae)
        {
            eax_9 = arg1 - 0xdeaf;
            cond:3_1 = arg1 == 0xdeaf;
        label_40e325:

            if (!cond:3_1)
            {
                cond:4_1 = eax_9 != 1;
            label_40e30c:

                if (cond:4_1)
                    return arg2;
            }
        }
    }
    else if (arg1 != 0xdeac)
    {
        if (arg1 > 0xc433)
        {
            if (arg1 != 0xc435)
            {
                if (arg1 == 0xd698)
                    return arg2 & 8;

                eax_9 = arg1 - 0xdeaa;
                cond:3_1 = arg1 == 0xdeaa;
                goto label_40e325;
            }
        }
        else if (arg1 != 0xc433 && arg1 != 0x2a && arg1 != 0xc42c && arg1 != 0xc42d
            && arg1 != 0xc42e)
        {
            cond:4_1 = arg1 != 0xc431;
            goto label_40e30c;
        }
    }
    return 0;
}

int32_t ___acrt_MultiByteToWideChar(uint32_t arg1, int32_t arg2, uint8_t* arg3, int32_t arg4, wchar16* arg5, int32_t arg6)
{
    return MultiByteToWideChar(arg1, filter_mbtowcs_flags(arg1, arg2), arg3, arg4, arg5, arg6);
}

int32_t filter_wcstomb_flags(int32_t arg1, int32_t arg2) __pure
{
    int32_t eax_8;
    bool cond:3_1;
    bool cond:4_1;

    if (arg1 > 0xdeac)
    {
        if (arg1 > 0xdeb1)
        {
            if (arg1 != 0xdeb2 && arg1 != 0xdeb3)
            {
                eax_8 = arg1 - 0xfde8;
                cond:3_1 = arg1 == 0xfde8;
            label_40e412:

                if (!cond:3_1)
                {
                    cond:4_1 = eax_8 == 1;
                label_40e417:

                    if (!cond:4_1)
                        return arg2 & 0xffffff7f;
                }
            }
        }
        else if (arg1 != 0xdeb1 && arg1 != 0xdead && arg1 != 0xdeae)
        {
            eax_8 = arg1 - 0xdeaf;
            cond:3_1 = arg1 == 0xdeaf;
            goto label_40e412;
        }
    }
    else if (arg1 != 0xdeac)
    {
        if (arg1 > 0xc433)
        {
            if (arg1 != 0xc435 && arg1 != 0xd698)
            {
                eax_8 = arg1 - 0xdeaa;
                cond:3_1 = arg1 == 0xdeaa;
                goto label_40e412;
            }
        }
        else if (arg1 != 0xc433 && arg1 != 0x2a && arg1 != 0xc42c && arg1 != 0xc42d
            && arg1 != 0xc42e)
        {
            cond:4_1 = arg1 == 0xc431;
            goto label_40e417;
        }
    }
    return 0;
}

int32_t sub_40e427(uint32_t arg1, int32_t arg2, wchar16* arg3, int32_t arg4, PSTR arg5, int32_t arg6, PSTR arg7, int32_t* arg8)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    int32_t edi;
    int32_t var_14 = edi;
    char ebx;

    ebx = arg1 == 0xfde8 || arg1 == 0xfde9 ? 1 : 0;

    uint32_t dwFlags = filter_wcstomb_flags(arg1, arg2);
    int32_t* lpUsedDefaultChar = arg8;

    if (ebx)
        lpUsedDefaultChar = nullptr;

    PSTR lpDefaultChar = arg7;

    if (ebx)
        lpDefaultChar = nullptr;

    if (ebx && arg8)
        *arg8 = 0;

    return WideCharToMultiByte(arg1, dwFlags, arg3, arg4, arg5, arg6, lpDefaultChar,
        lpUsedDefaultChar);
}

void* find_end_of_double_null_terminated_sequence(int16_t* arg1)
{
    int16_t* edx = arg1;
    int32_t edi;
    int32_t var_8 = edi;

    while (*edx)
    {
        int16_t* ecx_1 = edx;
        int16_t i;

        do
        {
            i = *ecx_1;
            ecx_1 = &ecx_1[1];
        } while (i);
        edx = &edx[((ecx_1 - &ecx_1[1]) >> 1) + 1];
    }

    return &edx[1];
}

PWSTR ___dcrt_get_narrow_environment_from_os()
{
    int32_t ecx;
    int32_t var_8 = ecx;
    int32_t var_c = ecx;
    PWSTR penv = GetEnvironmentStringsW();

    if (penv)
    {
        PSTR penv_1 = nullptr;
        int32_t eax_2 = (find_end_of_double_null_terminated_sequence(penv) - penv) >> 1;
        int32_t eax_3 = sub_40e427(0, 0, penv, eax_2, nullptr, 0, nullptr, nullptr);

        if (!eax_3)
        {
            FreeEnvironmentStringsW(penv);
            return nullptr;
        }

        int32_t edi;
        int32_t var_18_3 = edi;
        PSTR penv_2 = sub_40a8b0(eax_3);

        if (penv_2)
        {
            if (sub_40e427(0, 0, penv, eax_2, penv_2, eax_3, nullptr, nullptr))
            {
                PSTR var_1c_3 = nullptr;
                __free_base(0);
                penv_1 = penv_2;
            }
            else
                __free_base(penv_2);

            FreeEnvironmentStringsW(penv);
            penv = penv_1;
        }
        else
        {
            __free_base(0);
            FreeEnvironmentStringsW(penv);
            penv = nullptr;
        }
    }

    return penv;
}

int32_t sub_40e568()
{
    int32_t edi;
    int32_t var_8 = edi;
    int32_t edi_1 = 0x41ef98;
    int32_t esi = 0;
    int32_t result;

    while (true)
    {
        int32_t var_c_1 = 0;
        int32_t var_10_1 = 0xfa0;
        int32_t var_14_1 = edi_1;
        result = sub_40c4aa();

        if (!result)
        {
            result = ___acrt_uninitialize_locks();
            result = 0;
            break;
        }

        data_41f100 += 1;
        esi += 0x18;
        edi_1 += 0x18;

        if (esi >= 0x168)
        {
            result = 1;
            break;
        }
    }

    return result;
}

int32_t ___acrt_lock(int32_t arg1)
{
    return EnterCriticalSection(arg1 * 0x18 + 0x41ef98);
}

int32_t ___acrt_uninitialize_locks()
{
    int32_t i_1 = data_41f100;
    int32_t result;

    if (i_1)
    {
        int32_t edi;
        int32_t var_8_1 = edi;
        CRITICAL_SECTION* lpCriticalSection = &(&data_41ef80)[i_1 * 6];
        int32_t i;

        do
        {
            result = DeleteCriticalSection(lpCriticalSection);
            data_41f100 -= 1;
            lpCriticalSection -= 0x18;
            i = i_1;
            i_1 -= 1;
        } while (i != 1);
    }

    result = 1;
    return result;
}

int32_t ___acrt_unlock(int32_t arg1)
{
    return LeaveCriticalSection(arg1 * 0x18 + 0x41ef98);
}

uint8_t sub_40e608()
{
    TEB* fsbase;
    return fsbase->NtTib.Self->ProcessEnvironmentBlock->NtGlobalFlag >> 8 & 1;
}

uint32_t sub_40e61a()
{
    TEB* fsbase;
    return fsbase->NtTib.Self->ProcessEnvironmentBlock->ProcessParameters->Flags >> 0x1f;
}

int32_t __fastcall ___acrt_get_process_end_policy(int32_t arg1)
{
    int32_t var_8 = arg1;
    var_8 = 0;

    if (!sub_40e61a())
        sub_40c3ff(&var_8);

    int32_t result = 0;
    result = var_8 != 1;
    return result;
}

void* ___acrt_lowio_create_handle_array()
{
    int32_t ecx;
    int32_t var_8 = ecx;
    int32_t var_c = ecx;
    void* result = sub_40cf40(0x40, 0x38);

    if (!result)
        result = nullptr;
    else if (result != result + 0xe00)
    {
        int32_t edi;
        int32_t var_18_1 = edi;
        int32_t* edi_1 = result + 0x20;

        do
        {
            int32_t var_1c_1 = 0;
            int32_t var_20_1 = 0xfa0;
            void* var_24_1 = &edi_1[-8];
            sub_40c4aa();
            edi_1[-2] = 0xffffffff;
            *(edi_1 + 0xd) &= 0xf8;
            *edi_1 = 0;
            edi_1 = &edi_1[0xe];
            edi_1[-0xd] = 0;
            edi_1[-0xc] = 0xa0a0000;
            edi_1[-0xb] = 0xa;
            *(edi_1 - 0x2a) = 0;
            *(edi_1 - 0x26) = 0;
        } while (&edi_1[-8] != result + 0xe00);
    }

    __free_base(0);
    return result;
}

void ___acrt_lowio_destroy_handle_array(CRITICAL_SECTION* arg1)
{
    if (!arg1)
        return;

    int32_t edi;
    int32_t var_10_1 = edi;
    CRITICAL_SECTION* lpCriticalSection = arg1;

    if (arg1 != arg1 + 0xe00)
    {
        do
        {
            DeleteCriticalSection(lpCriticalSection);
            lpCriticalSection += 0x38;
        } while (lpCriticalSection != arg1 + 0xe00);
    }

    __free_base(arg1);
}

int32_t ___acrt_lowio_ensure_fh_exists(int32_t arg1)
{
    int32_t __saved_ebp_1 = 0x10;
    int32_t var_8 = 0x41cda0;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41cda0 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_34 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_34;
    void* const var_38_2 = &data_40e710;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t result;

    if (arg1 < 0x2000)
    {
        result = 0;
        int32_t var_20_1 = 0;
        ___acrt_lock(7);
        int32_t var_8_1 = 0;
        int32_t edi_1 = 0;
        int32_t eax_2 = data_41ef08;

        while (true)
        {
            int32_t var_24_1 = edi_1;

            if (arg1 < eax_2)
                break;

            if (!(&data_41ed08)[edi_1])
            {
                void* eax_3 = ___acrt_lowio_create_handle_array();
                (&data_41ed08)[edi_1] = eax_3;

                if (!eax_3)
                {
                    int32_t var_38_1 = 0xc;
                    result = 0xc;
                    int32_t var_20_2 = 0xc;
                    break;
                }

                eax_2 = data_41ef08 + 0x40;
                data_41ef08 = eax_2;
            }

            edi_1 += 1;
        }

        int32_t var_8_2 = 0xfffffffe;
        $LN13();
    }
    else
    {
        int32_t var_38 = 9;
        result = 9;
        *sub_40a844() = 9;
        __invalid_parameter_noinfo();
    }

    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t $LN13()
{
    return ___acrt_unlock(7);
}

int32_t ___acrt_lowio_lock_fh(int32_t arg1)
{
    return EnterCriticalSection((arg1 & 0x3f) * 0x38 + (&data_41ed08)[arg1 >> 6]);
}

int32_t ___acrt_lowio_unlock_fh(int32_t arg1)
{
    return LeaveCriticalSection((arg1 & 0x3f) * 0x38 + (&data_41ed08)[arg1 >> 6]);
}

int32_t __free_osfhnd(int32_t arg1)
{
    int32_t edi;
    int32_t var_10 = edi;

    if (arg1 >= 0 && arg1 < data_41ef08)
    {
        uint32_t ebx_2 = arg1 >> 6;
        int32_t edi_1 = (arg1 & 0x3f) * 0x38;
        int32_t eax_3 = (&data_41ed08)[ebx_2];

        if (*(edi_1 + eax_3 + 0x28) & 1 && *(edi_1 + eax_3 + 0x18) != 0xffffffff)
        {
            if (sub_408565() == 1)
            {
                if (!arg1)
                {
                    int32_t var_14_3 = 0;
                    SetStdHandle(STD_INPUT_HANDLE, nullptr);
                }
                else if (arg1 == 1)
                {
                    int32_t var_14_2 = 0;
                    SetStdHandle(STD_OUTPUT_HANDLE, nullptr);
                }
                else if (arg1 == 2)
                {
                    int32_t var_14_1 = 0;
                    SetStdHandle(STD_ERROR_HANDLE, nullptr);
                }
            }

            *((&data_41ed08)[ebx_2] + edi_1 + 0x18) = 0xffffffff;
            return 0;
        }
    }

    *sub_40a844() = 9;
    *sub_40a82f() = 0;
    return 0xffffffff;
}

int32_t __get_osfhandle(int32_t arg1)
{
    if (arg1 != 0xfffffffe)
    {
        if (arg1 >= 0 && arg1 < data_41ef08)
        {
            int32_t ecx_2 = (arg1 & 0x3f) * 0x38;
            int32_t eax_5 = (&data_41ed08)[arg1 >> 6];

            if (*(eax_5 + ecx_2 + 0x28) & 1)
                return *(eax_5 + ecx_2 + 0x18);
        }

        *sub_40a82f() = 0;
        *sub_40a844() = 9;
        __invalid_parameter_noinfo();
    }
    else
    {
        *sub_40a82f() = 0;
        *sub_40a844() = 9;
    }

    return 0xffffffff;
}

int32_t ___acrt_initialize_fmode()
{
    if (!data_41f104)
        data_41f104 = 0x4000;

    return 0;
}

void ___acrt_locale_free_monetary(void* arg1)
{
    if (!arg1)
        return;

    int32_t eax_1 = *(arg1 + 0xc);

    if (eax_1 != data_41e884)
        __free_base(eax_1);

    int32_t eax_2 = *(arg1 + 0x10);

    if (eax_2 != data_41e888)
        __free_base(eax_2);

    int32_t eax_3 = *(arg1 + 0x14);

    if (eax_3 != data_41e88c)
        __free_base(eax_3);

    int32_t eax_4 = *(arg1 + 0x18);

    if (eax_4 != data_41e890)
        __free_base(eax_4);

    int32_t eax_5 = *(arg1 + 0x1c);

    if (eax_5 != data_41e894)
        __free_base(eax_5);

    int32_t eax_6 = *(arg1 + 0x20);

    if (eax_6 != data_41e898)
        __free_base(eax_6);

    int32_t eax_7 = *(arg1 + 0x24);

    if (eax_7 != data_41e89c)
        __free_base(eax_7);

    int32_t eax_8 = *(arg1 + 0x38);

    if (eax_8 != data_41e8b0)
        __free_base(eax_8);

    int32_t eax_9 = *(arg1 + 0x3c);

    if (eax_9 != data_41e8b4)
        __free_base(eax_9);

    int32_t eax_10 = *(arg1 + 0x40);

    if (eax_10 != data_41e8b8)
        __free_base(eax_10);

    int32_t eax_11 = *(arg1 + 0x44);

    if (eax_11 != data_41e8bc)
        __free_base(eax_11);

    int32_t eax_12 = *(arg1 + 0x48);

    if (eax_12 != data_41e8c0)
        __free_base(eax_12);

    int32_t eax = *(arg1 + 0x4c);

    if (eax != data_41e8c4)
        __free_base(eax);
}

void ___acrt_locale_free_numeric(int32_t* arg1)
{
    if (!arg1)
        return;

    int32_t eax_1 = *arg1;

    if (eax_1 != data_41e878)
        __free_base(eax_1);

    int32_t eax_2 = arg1[1];

    if (eax_2 != data_41e87c)
        __free_base(eax_2);

    int32_t eax_3 = arg1[2];

    if (eax_3 != data_41e880)
        __free_base(eax_3);

    int32_t eax_4 = arg1[0xc];

    if (eax_4 != data_41e8a8)
        __free_base(eax_4);

    int32_t eax = arg1[0xd];

    if (eax != data_41e8ac)
        __free_base(eax);
}

int32_t free_crt_array_internal(int32_t* arg1, int32_t arg2)
{
    int32_t result = arg2;
    int32_t* i = arg1;
    int32_t edi;
    int32_t var_c = edi;

    for (void* edi_1 = &i[result]; i != edi_1; i = &i[1])
        result = __free_base(*i);

    return result;
}

void ___acrt_locale_free_time(int32_t* arg1)
{
    if (!arg1)
        return;

    free_crt_array_internal(arg1, 7);
    free_crt_array_internal(&arg1[7], 7);
    free_crt_array_internal(&arg1[0xe], 0xc);
    free_crt_array_internal(&arg1[0x1a], 0xc);
    free_crt_array_internal(&arg1[0x26], 2);
    __free_base(arg1[0x28]);
    __free_base(arg1[0x29]);
    __free_base(arg1[0x2a]);
    free_crt_array_internal(&arg1[0x2d], 7);
    free_crt_array_internal(&arg1[0x34], 7);
    free_crt_array_internal(&arg1[0x3b], 0xc);
    free_crt_array_internal(&arg1[0x47], 0xc);
    free_crt_array_internal(&arg1[0x53], 2);
    __free_base(arg1[0x55]);
    __free_base(arg1[0x56]);
    __free_base(arg1[0x57]);
    __free_base(arg1[0x58]);
}

uint32_t sub_40eb70(int16_t* arg1, int16_t* arg2, int32_t arg3)
{
    if (!arg3)
        return 0;

    int16_t* ecx = arg2;
    int16_t* eax_1 = arg1;
    int32_t i_1 = arg3 - 1;

    if (arg3 != 1)
    {
        int32_t i;

        do
        {
            int16_t esi_1 = *eax_1;

            if (!esi_1)
                break;

            if (esi_1 != *ecx)
                break;

            eax_1 = &eax_1[1];
            ecx = &ecx[1];
            i = i_1;
            i_1 -= 1;
        } while (i != 1);
    }

    return *eax_1 - *ecx;
}

BOOL sub_40ebb3(int32_t* arg1, uint32_t arg2, uint8_t* arg3, int32_t arg4, uint16_t* arg5, uint32_t arg6, int32_t arg7)
{
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    int32_t edi;
    int32_t var_2c = edi;
    void* var_20;
    _LocaleUpdate::_LocaleUpdate(&var_20, arg1);
    uint32_t ebx = arg6;
    void* var_1c;

    if (!ebx)
        ebx = *(var_1c + 8);
    BOOL result = 0;
    int32_t eax_3 = 1;

    if (arg7)
        eax_3 = 9;

    int32_t eax_4 = ___acrt_MultiByteToWideChar(ebx, eax_3, arg3, arg4, nullptr, 0);

    if (eax_4)
    {
        int32_t eax_5 = eax_4 * 2;
        uint32_t eax_7 = (eax_5 - eax_5) & (eax_5 + 8);
        int32_t* lpSrcStr;

        if (!eax_7)
            lpSrcStr = nullptr;
        else if (eax_7 > 0x400)
        {
            lpSrcStr = sub_40a8b0(eax_7);

            if (lpSrcStr)
            {
                *lpSrcStr = 0xdddd;
            label_40ec48:
                lpSrcStr = &lpSrcStr[2];

                if (lpSrcStr)
                {
                    _memset(lpSrcStr, 0, eax_5);
                    int32_t cchSrc =
                        ___acrt_MultiByteToWideChar(ebx, 1, arg3, arg4, lpSrcStr, eax_4);

                    if (cchSrc)
                        result = GetStringTypeW(arg2, lpSrcStr, cchSrc, arg5);
                }
            }
        }
        else
        {
            __alloca_probe_16(eax_7);
            lpSrcStr = &var_2c;

            if (&var_2c)
            {
                var_2c = 0xcccc;
                goto label_40ec48;
            }
        }

        __freea_crt(lpSrcStr);
    }

    char var_14;

    if (var_14)
    {
        void* eax_10 = var_20;
        *(eax_10 + 0x350) &= 0xfffffffd;
    }

    sub_402910(eax_1 ^ &__saved_ebp);
    return result;
}

int32_t* __freea_crt(int32_t* arg1)
{
    int32_t* result = arg1;

    if (result)
    {
        result -= 8;

        if (*result == 0xdddd)
            result = __free_base(result);
    }

    return result;
}

int32_t sub_40ecd1(void* arg1)
{
    *(arg1 + 0xc) += 1;
    int32_t* ecx = *(arg1 + 0x7c);

    if (ecx)
        *ecx += 1;

    int32_t* ecx_1 = *(arg1 + 0x84);

    if (ecx_1)
        *ecx_1 += 1;

    int32_t* ecx_2 = *(arg1 + 0x80);

    if (ecx_2)
        *ecx_2 += 1;

    int32_t* ecx_3 = *(arg1 + 0x8c);

    if (ecx_3)
        *ecx_3 += 1;

    int32_t* ecx_4 = arg1 + 0x28;
    int32_t i_1 = 6;
    int32_t i;

    do
    {
        if (ecx_4[-2] != &data_41e350)
        {
            int32_t* edx_1 = *ecx_4;

            if (edx_1)
                *edx_1 += 1;
        }

        if (ecx_4[-3])
        {
            int32_t* edx_2 = ecx_4[-1];

            if (edx_2)
                *edx_2 += 1;
        }

        ecx_4 = &ecx_4[4];
        i = i_1;
        i_1 -= 1;
    } while (i != 1);
    return ___acrt_locale_add_lc_time_reference(*(arg1 + 0x9c));
}

int32_t sub_40ed4e(void* arg1)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    int32_t eax = *(arg1 + 0x88);

    if (eax && eax != &data_41e878)
    {
        int32_t* eax_1 = *(arg1 + 0x7c);

        if (eax_1 && !*eax_1)
        {
            int32_t* eax_2 = *(arg1 + 0x84);

            if (eax_2 && !*eax_2)
            {
                __free_base(eax_2);
                ___acrt_locale_free_monetary(*(arg1 + 0x88));
            }

            int32_t* eax_3 = *(arg1 + 0x80);

            if (eax_3 && !*eax_3)
            {
                __free_base(eax_3);
                ___acrt_locale_free_numeric(*(arg1 + 0x88));
            }

            __free_base(*(arg1 + 0x7c));
            __free_base(*(arg1 + 0x88));
        }
    }

    int32_t* eax_4 = *(arg1 + 0x8c);
    int32_t edi;
    int32_t var_14_4 = edi;

    if (eax_4 && !*eax_4)
    {
        __free_base(*(arg1 + 0x90) - 0xfe);
        __free_base(*(arg1 + 0x94) - 0x80);
        __free_base(*(arg1 + 0x98) - 0x80);
        __free_base(*(arg1 + 0x8c));
    }

    ___acrt_locale_free_lc_time_if_unreferenced(*(arg1 + 0x9c));
    int32_t i_1 = 6;
    int32_t* ebx = arg1 + 0xa0;
    int32_t i_2 = 6;
    int32_t* edi_1 = arg1 + 0x28;
    int32_t i;

    do
    {
        if (edi_1[-2] != &data_41e350)
        {
            int32_t* eax_11 = *edi_1;

            if (eax_11 && !*eax_11)
            {
                __free_base(eax_11);
                __free_base(*ebx);
            }

            i_1 = i_2;
        }

        if (edi_1[-3])
        {
            int32_t* eax_12 = edi_1[-1];

            if (eax_12 && !*eax_12)
                __free_base(eax_12);

            i_1 = i_2;
        }

        ebx = &ebx[1];
        edi_1 = &edi_1[4];
        i = i_1;
        i_1 -= 1;
        i_2 = i_1;
    } while (i != 1);
    return __free_base(arg1);
}

int32_t ___acrt_locale_add_lc_time_reference(void* arg1)
{
    if (!arg1 || arg1 == &data_4174d8)
        return 0x7fffffff;

    int32_t eax = *(arg1 + 0xb0);
    *(arg1 + 0xb0) += 1;
    return eax + 1;
}

void ___acrt_locale_free_lc_time_if_unreferenced(int32_t* arg1)
{
    if (arg1 && arg1 != &data_4174d8 && !arg1[0x2c])
    {
        ___acrt_locale_free_time(arg1);
        __free_base(arg1);
    }
}

int32_t ___acrt_locale_release_lc_time_reference(void* arg1)
{
    if (!arg1 || arg1 == &data_4174d8)
        return 0x7fffffff;

    int32_t eax = *(arg1 + 0xb0);
    *(arg1 + 0xb0) -= 1;
    return eax - 1;
}

void* sub_40ef19(void* arg1)
{
    void* result = arg1;

    if (result)
    {
        *(result + 0xc) -= 1;
        int32_t* ecx_1 = *(result + 0x7c);

        if (ecx_1)
            *ecx_1 -= 1;

        int32_t* ecx_2 = *(result + 0x84);

        if (ecx_2)
            *ecx_2 -= 1;

        int32_t* ecx_3 = *(result + 0x80);

        if (ecx_3)
            *ecx_3 -= 1;

        int32_t* ecx_4 = *(result + 0x8c);

        if (ecx_4)
            *ecx_4 -= 1;

        int32_t* ecx_5 = result + 0x28;
        int32_t i_1 = 6;
        int32_t i;

        do
        {
            if (ecx_5[-2] != &data_41e350)
            {
                int32_t* edx_1 = *ecx_5;

                if (edx_1)
                    *edx_1 -= 1;
            }

            if (ecx_5[-3])
            {
                int32_t* edx_2 = ecx_5[-1];

                if (edx_2)
                    *edx_2 -= 1;
            }

            ecx_5 = &ecx_5[4];
            i = i_1;
            i_1 -= 1;
        } while (i != 1);
        result = ___acrt_locale_release_lc_time_reference(*(result + 0x9c));
    }

    return result;
}

void* ___acrt_update_thread_locale_data()
{
    int32_t __saved_ebp_1 = 0xc;
    int32_t var_8 = 0x41cdc0;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41cdc0 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_1 = &data_40efa6;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t var_20 = 0;
    int32_t* eax = sub_409b74();
    void* result;

    if (eax[0xd4] & data_41e8d0)
        result = eax[0x13];

    if (!(eax[0xd4] & data_41e8d0) || !result)
    {
        ___acrt_lock(4);
        int32_t var_8_1 = 0;
        result = __updatetlocinfoEx_nolock(&eax[0x13], data_41ed00);
        void* result_1 = result;
        int32_t var_8_2 = 0xfffffffe;
        $LN11();

        if (!result)
        {
            sub_4096af();
            /* no return */
        }
    }

    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t $LN11()
{
    return ___acrt_unlock(4);
}

void* __updatetlocinfoEx_nolock(int32_t* arg1, void* arg2)
{
    int32_t edi;
    int32_t var_c = edi;

    if (!arg2 || !arg1)
        return nullptr;

    void* edi_1 = *arg1;

    if (edi_1 != arg2)
    {
        *arg1 = arg2;
        sub_40ecd1(arg2);

        if (edi_1)
        {
            sub_40ef19(edi_1);

            if (!*(edi_1 + 0xc) && edi_1 != &data_41e290)
                sub_40ed4e(edi_1);
        }
    }

    return arg2;
}

int32_t __recalloc_base(int32_t arg1, int32_t arg2, int32_t arg3)
{
    if (arg2 && COMBINE(0, 0xffffffe0) / arg2 < arg3)
    {
        *sub_40a844() = 0xc;
        return 0;
    }

    int32_t edi;
    int32_t var_10_1 = edi;
    uint32_t edi_1;

    if (!arg1)
        edi_1 = 0;
    else
        edi_1 = sub_412900(arg1);

    uint32_t esi_1 = arg2 * arg3;
    int32_t result = __realloc_base(arg1, esi_1);

    if (result && edi_1 < esi_1)
        _memset(result + edi_1, 0, esi_1 - edi_1);

    return result;
}

int32_t __recalloc()
{
    /* tailcall */
    return __recalloc_base();
}

int32_t sub_40f100()
{
    return data_41f110;
}

HANDLE ___acrt_initialize_heap()
{
    HANDLE result = GetProcessHeap();
    data_41f110 = result;
    result = result;
    return result;
}

int32_t sub_40f130()
{
    data_41f110 = 0;
    int32_t result;
    result = 1;
    return result;
}

int32_t sub_40f140()
{
    return data_41f110;
}

void* ___acrt_execute_initializers(int32_t* arg1, int32_t arg2)
{
    int32_t edi;
    int32_t var_10 = edi;
    void* result;

    if (arg1 == arg2)
        result = 1;
    else
    {
        int32_t* esi_1 = arg1;

        do
        {
            int32_t ebx_1 = *esi_1;

            if (ebx_1)
            {
                result = ebx_1();

                if (!result)
                    break;
            }

            esi_1 = &esi_1[2];
        } while (esi_1 != arg2);

        if (esi_1 == arg2)
            result = 1;
        else
        {
            if (esi_1 != arg1)
            {
                int32_t* esi_2 = &esi_1[-1];

                do
                {
                    if (esi_2[-1])
                    {
                        int32_t ebx_2 = *esi_2;

                        if (ebx_2)
                            ebx_2(0);
                    }

                    esi_2 -= 8;
                    result = &esi_2[1];
                } while (result != arg1);
            }

            result = 0;
        }
    }

    return result;
}

int32_t ___acrt_execute_uninitializers(int32_t arg1, void* arg2)
{
    void* esi = arg2;
    int32_t result;

    if (arg1 != esi)
    {
        int32_t edi;
        int32_t var_c_1 = edi;

        do
        {
            int32_t edi_1 = *(esi - 4);

            if (edi_1)
                result = edi_1(0);

            esi -= 8;
        } while (esi != arg1);
    }

    result = 1;
    return result;
}

int32_t __callnewh(int32_t arg1)
{
    int32_t eax = __query_new_handler();

    if (!eax)
        return 0;

    int32_t eax_1 = eax(arg1);
    int32_t eax_2 = -(eax_1);
    return -((eax_2 - eax_2));
}

int32_t sub_40f220(int32_t arg1)
{
    data_41f114 = arg1;
    return arg1;
}

int32_t __query_new_handler()
{
    int32_t __saved_ebp_1 = 0xc;
    int32_t var_8 = 0x41ce00;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41ce00 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_1 = &data_40f24c;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t var_20 = 0;
    ___acrt_lock(0);
    int32_t var_8_1 = 0;
    int32_t result = sub_408c17(data_41f114);
    int32_t result_1 = result;
    int32_t var_8_2 = 0xfffffffe;
    $LN7();
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t $LN7()
{
    return ___acrt_unlock(0);
}

int32_t __set_new_handler(int32_t arg1)
{
    int32_t __saved_ebp_1 = 0xc;
    int32_t var_8 = 0x41cde0;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41cde0 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_1 = &data_40f2ac;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t var_20 = 0;
    ___acrt_lock(0);
    int32_t var_8_1 = 0;
    int32_t result = sub_408c17(data_41f114);
    int32_t result_1 = result;
    data_41f114 = sub_408c32(arg1);
    int32_t var_8_2 = 0xfffffffe;
    $LN7();
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t sub_40f2f9(void* arg1 @ ebp)
{
    *(arg1 - 0x1c);
    /* tailcall */
    return $LN7();
}

int32_t $LN7()
{
    return ___acrt_unlock(0);
}

int32_t _set_new_handler()
{
    return __set_new_handler(__security_cookie);
}

int32_t __stdcall __crt_seh_guarded_call< void (__cdecl*)(int32_t)>::operator()<class <lambda_cbab9ec6f41b0180b23cc171c22676b0>,class <lambda_44731a7d0e6d81c3e6aa82d741081786>&,class <lambda_4b292cb8dd18144e164572427af410ab> >(int32_t* arg1)
{
    int32_t __saved_ebp_1 = 0xc;
    int32_t var_8 = 0x41ce40;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41ce40 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_1 = &data_40f329;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t var_20 = 0;
    ___acrt_lock(*arg1);
    int32_t var_8_1 = 0;
    int32_t result = RORD(data_41f120 ^ __security_cookie, __security_cookie & 0x1f);
    int32_t result_1 = result;
    int32_t var_8_2 = 0xfffffffe;
    $LN7(&__saved_ebp);
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t $LN7(void* arg1 @ ebp)
{
    return ___acrt_unlock(**(arg1 + 0x10));
}

int32_t get_global_action_nolock(int32_t arg1) __pure
{
    if (arg1 == 2)
        return &data_41f118;

    if (arg1 != 6)
    {
        if (arg1 == 0xf)
            return &data_41f124;

        if (arg1 == 0x15)
            return &data_41f11c;

        if (arg1 != 0x16)
            return 0;
    }

    return &data_41f120;
}

void* siglookup(int32_t arg1, void* arg2)
{
    void* i = arg2;

    for (void* ecx = 0x90 + i; i != ecx; i += 0xc)
    {
        if (*(i + 4) == arg1)
            return i;
    }

    return nullptr;
}

int32_t ___acrt_get_sigabrt_handler()
{
    int32_t var_c = 3;
    int32_t var_10 = 3;
    int32_t* var_14 = &var_c;
    void var_5;
    void* var_18 = &var_5;
    return __crt_seh_guarded_call< void (__cdecl*)(int32_t)>::operator()<class <lambda_cbab9ec6f41b0180b23cc171c22676b0>,class <lambda_44731a7d0e6d81c3e6aa82d741081786>&,class <lambda_4b292cb8dd18144e164572427af410ab> >(
        &var_10);
}

int32_t ___acrt_initialize_signal_handlers(int32_t arg1)
{
    data_41f118 = arg1;
    data_41f11c = arg1;
    data_41f120 = arg1;
    data_41f124 = arg1;
    return arg1;
}

int32_t sub_40f434(int32_t arg1)
{
    int32_t __saved_ebp_1 = 0x28;
    int32_t var_8 = 0x41ce20;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t ebx;
    int32_t var_40 = ebx;
    int32_t esi;
    int32_t var_44 = esi;
    int32_t edi;
    int32_t var_48 = edi;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41ce20 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_4c = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_4c;
    void* const var_50_6 = &data_40f440;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t* esp = &var_4c;
    int32_t* edi_1 = nullptr;
    int32_t var_2c = 0;
    int32_t var_38 = 0;
    ebx = 1;
    char var_1d = 1;
    int32_t result;
    int32_t* eax_8;

    if (arg1 <= 0xb)
    {
        if (arg1 != 0xb)
        {
            int32_t var_50 = 2;
            esp = &var_4c;

            if (arg1 == 2)
                goto label_40f4be;

            if (arg1 == 4)
                goto label_40f471;

            if (arg1 == 6)
                goto label_40f4be;

            if (arg1 != 8)
                goto label_40f495;

            goto label_40f471;
        }

    label_40f471:
        edi_1 = sub_409bc5();
        int32_t* var_2c_1 = edi_1;

        if (edi_1)
        {
            void* eax_6 = siglookup(arg1, *edi_1);
            esp = &var_4c;

            if (!eax_6)
                goto label_40f495;

            eax_8 = eax_6 + 8;
            ebx = 0;
            char var_1d_1 = 0;
            goto label_40f4c9;
        }

        result = 0xffffffff;
    }
    else if (arg1 == 0xf || arg1 == 0x15 || arg1 == 0x16)
    {
    label_40f4be:
        eax_8 = get_global_action_nolock(arg1);
        esp = &var_4c;
    label_40f4c9:
        int32_t var_34_1 = 0;

        if (ebx)
        {
            ___acrt_lock(3);
            esp = &var_4c;
        }

        int32_t var_30_1 = 0;
        char var_1e_1 = 0;
        int32_t var_8_1 = 0;
        int32_t ecx_3 = *eax_8;
        int32_t var_24_1 = ecx_3;

        if (ebx)
        {
            esp = &var_4c;
            ecx_3 = sub_408c17(ecx_3);
            var_24_1 = ecx_3;
        }

        int32_t var_30_2 = ecx_3;
        *(&ebx + 1) = ecx_3 == 1;
        char var_1e_2 = *(&ebx + 1);

        if (!*(&ebx + 1))
        {
            if (!ecx_3)
            {
                if (ebx)
                    ___acrt_unlock(3);

                sub_408ed4(3);
                breakpoint();
            }

            if (arg1 != 8 && arg1 != 0xb && arg1 != 4)
                goto label_40f54d;

            var_34_1 = edi_1[1];
            edi_1[1] = 0;

            if (arg1 != 8)
                *eax_8 = __security_cookie;
            else
            {
                var_38 = sub_409b74()[2];
                sub_409b74()[2] = 0x8c;
            label_40f54d:

                if (arg1 != 8)
                    *eax_8 = __security_cookie;
                else
                {
                    void* eax_19 = 0x24 + *edi_1;
                    void* edx_1 = 0x6c + eax_19;

                    while (true)
                    {
                        void* var_3c_1 = eax_19;

                        if (eax_19 == edx_1)
                            break;

                        *(eax_19 + 8) = 0;
                        eax_19 += 0xc;
                    }
                }
            }
        }

        int32_t var_8_2 = 0xfffffffe;
        $LN45(&__saved_ebp);

        if (!*(&ebx + 1))
        {
            if (arg1 != 8)
                var_24_1(arg1);
            else
            {
                int32_t var_50_4 = sub_409b74()[2];
                var_24_1(arg1);
            }

            esp = &var_48;

            if (arg1 == 8 || arg1 == 0xb || arg1 == 4)
            {
                edi_1[1] = var_34_1;

                if (arg1 == 8)
                    sub_409b74()[2] = var_38;
            }
        }

        result = 0;
    }
    else
    {
    label_40f495:
        *sub_40a844() = 0x16;
        __invalid_parameter_noinfo();
        result = 0xffffffff;
    }
    fsbase->NtTib.ExceptionList = ExceptionList;
    *esp;
    esp[1];
    esp[2];
    esp[3];
    return result;
}

void $LN45(void* arg1 @ ebp)
{
    char entry_ebx;

    if (entry_ebx)
    {
        ___acrt_unlock(3);
        *(arg1 - 0x20);
    }
}

int32_t __stdcall __crt_seh_guarded_call<void>::operator()<class <lambda_2866be3712abc81a800a822484c830d8>,class <lambda_39ca0ed439415581b5b15c265174cece>&,class <lambda_2b24c74d71094a6cd0cb82e44167d71b> >(int32_t* arg1, int32_t* arg2)
{
    int32_t __saved_ebp_1 = 8;
    int32_t var_8 = 0x41ce60;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41ce60 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_2c = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_2c;
    void* const var_30_3 = &data_40f632;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    __lock_file(*arg1);
    int32_t var_8_1 = 0;

    if (common_flush_all_should_try_to_flush_stream(**arg2, arg2[1])
        && (*arg2[2] || *(**arg2 + 0xc) >> 1 & 1))
    {
        if (__fflush_nolock(**arg2) == 0xffffffff)
            *arg2[3] = 0xffffffff;
        else
        {
            int32_t* eax_10 = arg2[1];
            *eax_10 += 1;
        }
    }

    int32_t var_8_2 = 0xfffffffe;
    int32_t result = sub_40f6a6(&__saved_ebp);
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t sub_40f6a6(void* arg1 @ ebp)
{
    return __unlock_file(**(arg1 + 0x10));
}

int32_t __stdcall __crt_seh_guarded_call<void>::operator()<class <lambda_2cc53f568c5a2bb6f192f930a45d44ea>,class <lambda_ab61a845afdef5b7c387490eaf3616ee>&,class <lambda_c2ffc0b7726aa6be21d5f0026187e748> >(int32_t* arg1, int32_t* arg2)
{
    int32_t __saved_ebp_1 = 0x2c;
    int32_t var_8 = 0x41ce80;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41ce80 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_50 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_50;
    void* const var_54_3 = &data_40f6be;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    ___acrt_lock(*arg1);
    int32_t var_8_1 = 0;
    int32_t* esi = data_41ecf0;
    void* ebx = &esi[data_41ecec];
    int32_t* edi = arg2;

    while (true)
    {
        int32_t* var_30_1 = esi;

        if (esi == ebx)
            break;

        int32_t* eax_2 = *esi;
        int32_t* var_24 = eax_2;

        if (common_flush_all_should_try_to_flush_stream(eax_2, *edi))
        {
            int32_t edx_1 = edi[2];
            int32_t ecx_2 = edi[1];
            int32_t eax_4 = *edi;
            int32_t* var_40 = &var_24;
            int32_t var_3c_1 = eax_4;
            int32_t var_38_1 = ecx_2;
            int32_t var_34_1 = edx_1;
            int32_t* eax_5 = var_24;
            int32_t* var_28 = eax_5;
            int32_t* var_2c = eax_5;
            int32_t* var_54_2 = &var_28;
            __crt_seh_guarded_call<void>::operator()<class <lambda_2866be3712abc81a800a822484c830d8>,class <lambda_39ca0ed439415581b5b15c265174cece>&,class <lambda_2b24c74d71094a6cd0cb82e44167d71b> >(
                &var_2c, &var_40);
            edi = arg2;
        }

        esi = &esi[1];
    }

    int32_t var_8_2 = 0xfffffffe;
    int32_t result = sub_40f752(&__saved_ebp);
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t sub_40f752(void* arg1 @ ebp)
{
    return ___acrt_unlock(**(arg1 + 0x10));
}

int32_t sub_40f75e()
{
    int32_t var_10 = 0;
    int32_t var_c = 0;
    int32_t* var_24 = &var_10;
    char arg_4;
    char* var_20 = &arg_4;
    int32_t* var_1c = &var_c;
    int32_t var_14 = 8;
    int32_t var_18 = 8;
    int32_t* var_28 = &var_14;
    __crt_seh_guarded_call<void>::operator()<class <lambda_2cc53f568c5a2bb6f192f930a45d44ea>,class <lambda_ab61a845afdef5b7c387490eaf3616ee>&,class <lambda_c2ffc0b7726aa6be21d5f0026187e748> >(
        &var_18, &var_24);

    if (arg_4)
        return var_10;

    return var_c;
}

int32_t* common_flush_all_should_try_to_flush_stream(int32_t* arg1, int32_t* arg2)
{
    int32_t* eax = arg1;

    if (eax)
    {
        int32_t ecx_1 = eax[3];
        eax = ecx_1 >> 0xd;

        if (eax & 1)
        {
            int32_t eax_2 = is_stream_flushable_or_commitable(ecx_1);

            if (eax_2)
            {
                eax_2 = 1;
                return eax_2;
            }

            eax = arg2;
            *eax += 1;
        }
    }

    eax = 0;
    return eax;
}

uint8_t is_stream_flushable_or_commitable(int32_t arg1) __pure
{
    uint8_t eax_1 = arg1 & 3;

    if (eax_1 == 2 && arg1 & 0xc0)
        return eax_1 - 1;

    return arg1 >> 0xb & 1;
}

int32_t ___acrt_stdio_flush_nolock(int32_t* arg1, int32_t* arg2)
{
    int32_t edi;
    int32_t var_10 = edi;
    char edx = arg1[3];

    if ((edx & 3) == 2 && edx & 0xc0)
    {
        int16_t* ebx_1 = arg1[1];
        uint32_t edi_2 = *arg1 - ebx_1;
        *arg1 = ebx_1;
        arg1[2] = 0;

        if (edi_2 > 0)
        {
            if (edi_2 != __write_internal(__fileno(arg1), ebx_1, edi_2, arg2))
            {
                arg1[3] |= 0x10;
                return 0xffffffff;
            }

            if (arg1[3] >> 2 & 1)
                arg1[3] &= 0xfffffffd;
        }
    }

    return 0;
}

int32_t __fflush_nolock(int32_t* arg1)
{
    int32_t edi;
    int32_t var_34 = edi;
    int32_t result = 0;
    void var_2c;
    __crt_cached_ptd_host::__crt_cached_ptd_host(&var_2c, nullptr);

    if (arg1)
    {
        if (___acrt_stdio_flush_nolock(arg1, &var_2c))
            result = 0xffffffff;
        else if (arg1[3] >> 0xb & 1 && __commit(__fileno(arg1)))
            result = 0xffffffff;
    }
    else
        result = sub_40f75e();

    __crt_cached_ptd_host::~__crt_cached_ptd_host(&var_2c);
    return result;
}

int32_t sub_40f8cc()
{
    return sub_40f75e();
}

int32_t sub_40f8e0(int32_t arg1) __pure
{
    char eax = arg1;
    int32_t result_6 = (arg1 & 0x10) << 3;
    int32_t result_5 = result_6 | 0x200;

    if (!(eax & 8))
        result_5 = result_6;

    int32_t result_4 = result_5 | 0x400;

    if (!(eax & 4))
        result_4 = result_5;

    int32_t result_3 = result_4 | 0x800;

    if (!(eax & 2))
        result_3 = result_4;

    int32_t result_2 = result_3 | 0x1000;

    if (!(eax & 1))
        result_2 = result_3;

    int32_t result_1 = result_2 | 0x100;

    if (!(arg1 & 0x80000))
        result_1 = result_2;

    int32_t ecx_5 = arg1 & 0x300;
    int32_t result = result_1;

    if (ecx_5 > 0x200)
    {
        if (ecx_5 == 0x300)
            result |= 0x6000;
    }
    else if (ecx_5 == 0x200)
        result |= 0x4000;
    else if (ecx_5 && ecx_5 == 0x100)
        result |= 0x2000;

    int32_t esi_1 = arg1 & 0x3000000;

    if (esi_1 == 0x1000000)
        return result | 0x8040;

    if (esi_1 == 0x2000000)
        return result | 0x40;

    if (esi_1 != 0x3000000)
        return result;

    return result | 0x8000;
}

int32_t sub_40f9b0(int32_t arg1 @ mxcsr)
{
    bool c0;
    bool c1;
    bool c2;
    bool c3;
    int16_t var_8 =
        (c0 ? 1 : 0) << 8 | (c1 ? 1 : 0) << 9 | (c2 ? 1 : 0) << 0xa | (c3 ? 1 : 0) << 0xe;
    __fnclex();

    if (data_41eae8 < 1)
    {
        int32_t result = 0;

        if (var_8 & 0x3f)
        {
            int32_t result_4 = (var_8 & 1) << 4;
            int32_t result_3 = result_4 | 8;

            if (!(var_8 & 4))
                result_3 = result_4;

            int32_t result_2 = result_3 | 4;

            if (!(var_8 & 8))
                result_2 = result_3;

            int32_t result_1 = result_2 | 2;

            if (!(var_8 & 0x10))
                result_1 = result_2;

            result = result_1 | 1;

            if (!(var_8 & 0x20))
                result = result_1;

            if (var_8 & 2)
                return result | 0x80000;
        }

        return result;
    }

    int32_t esi = 0;

    if (var_8 & 0x3f)
    {
        int32_t ecx_3 = (var_8 & 1) << 4;
        int32_t edx_2 = ecx_3 | 8;

        if (!(var_8 & 4))
            edx_2 = ecx_3;

        int32_t ecx_5 = edx_2 | 4;

        if (!(var_8 & 8))
            ecx_5 = edx_2;

        int32_t edx_4 = ecx_5 | 2;

        if (!(var_8 & 0x10))
            edx_4 = ecx_5;

        esi = edx_4 | 1;

        if (!(var_8 & 0x20))
            esi = edx_4;

        if (var_8 & 2)
            esi |= 0x80000;
    }

    int32_t var_10 = arg1 & 0xffffffc0;
    int32_t ecx_6 = 0;

    if (arg1 & 0x3f)
    {
        int32_t ecx_9 = (arg1 & 1) << 4;
        int32_t edx_6 = ecx_9 | 8;

        if (!(arg1 & 4))
            edx_6 = ecx_9;

        int32_t ecx_11 = edx_6 | 4;

        if (!(arg1 & 8))
            ecx_11 = edx_6;

        int32_t edx_8 = ecx_11 | 2;

        if (!(arg1 & 0x10))
            edx_8 = ecx_11;

        ecx_6 = edx_8 | 1;

        if (!(arg1 & 0x20))
            ecx_6 = edx_8;

        if (arg1 & 2)
            ecx_6 |= 0x80000;
    }

    return ecx_6 | esi;
}

int32_t sub_40fad0(int32_t arg1 @ mxcsr, int16_t arg2 @ x87control, int32_t arg3, int32_t arg4)
{
    int32_t edi;
    int32_t var_20 = edi;
    int16_t x87status;
    int16_t temp0;
    temp0 = __fnstcw_memmem16(arg2);
    int32_t ecx_2 = (temp0 & 1) << 4;
    int32_t edx_1 = ecx_2 | 8;

    if (!(temp0 & 4))
        edx_1 = ecx_2;

    int32_t ecx_4 = edx_1 | 4;

    if (!(temp0 & 8))
        ecx_4 = edx_1;

    int32_t edx_3 = ecx_4 | 2;

    if (!(temp0 & 0x10))
        edx_3 = ecx_4;

    int32_t ecx_6 = edx_3 | 1;

    if (!(temp0 & 0x20))
        ecx_6 = edx_3;

    int32_t esi_1 = ecx_6 | 0x80000;

    if (!(temp0 & 2))
        esi_1 = ecx_6;

    uint32_t ecx_7 = temp0;
    int32_t edx_4 = esi_1;
    int32_t eax_1 = ecx_7 & 0xc00;

    if (eax_1 > 0x800)
    {
        if (eax_1 == 0xc00)
            edx_4 |= 0x300;
    }
    else if (eax_1 == 0x800)
        edx_4 |= 0x200;
    else if (eax_1 && eax_1 == 0x400)
        edx_4 |= 0x100;

    int32_t ecx_8 = ecx_7 & 0x300;

    if (!ecx_8)
        edx_4 |= 0x20000;
    else if (ecx_8 == 0x200)
        edx_4 |= 0x10000;

    int32_t ecx_10 = edx_4 | 0x40000;

    if (!(temp0 & 0x1000))
        ecx_10 = edx_4;

    int32_t esi_5 = (~arg4 & ecx_10) | (arg3 & arg4);

    if (esi_5 != ecx_10)
    {
        int16_t x87control;
        int16_t x87status_1;
        x87control = __fldcw_memmem16(sub_40fe60(esi_5));
        int16_t x87status_2;
        int16_t temp0_1;
        temp0_1 = __fnstcw_memmem16(x87control);
        uint32_t esi_6 = temp0_1;
        int32_t ecx_13 = (temp0_1 & 1) << 4;
        int32_t edx_6 = ecx_13 | 8;

        if (!(temp0_1 & 4))
            edx_6 = ecx_13;

        int32_t ecx_15 = edx_6 | 4;

        if (!(temp0_1 & 8))
            ecx_15 = edx_6;

        int32_t edx_8 = ecx_15 | 2;

        if (!(temp0_1 & 0x10))
            edx_8 = ecx_15;

        int32_t ecx_17 = edx_8 | 1;

        if (!(temp0_1 & 0x20))
            ecx_17 = edx_8;

        int32_t edx_10 = ecx_17 | 0x80000;

        if (!(temp0_1 & 2))
            edx_10 = ecx_17;

        int32_t eax_7 = esi_6 & 0xc00;
        int32_t ecx_18 = edx_10;

        if (eax_7 > 0x800)
        {
            if (eax_7 == 0xc00)
                ecx_18 |= 0x300;
        }
        else if (eax_7 == 0x800)
            ecx_18 |= 0x200;
        else if (eax_7 && eax_7 == 0x400)
            ecx_18 |= 0x100;

        int32_t esi_7 = esi_6 & 0x300;

        if (!esi_7)
            ecx_18 |= 0x20000;
        else if (esi_7 == 0x200)
            ecx_18 |= 0x10000;

        esi_5 = ecx_18 | 0x40000;

        if (!(temp0_1 & 0x1000))
            esi_5 = ecx_18;
    }

    if (data_41eae8 < 1)
        return esi_5;

    int32_t edi_2 = arg4 & 0x308031f;
    int32_t ecx_21 = arg1 >> 3 & 0x10;
    int32_t edx_12 = ecx_21 | 8;

    if (!(arg1 & 0x200))
        edx_12 = ecx_21;

    int32_t ecx_23 = edx_12 | 4;

    if (!(arg1 & 0x400))
        ecx_23 = edx_12;

    int32_t edx_14 = ecx_23 | 2;

    if (!(arg1 & 0x800))
        edx_14 = ecx_23;

    int32_t ecx_25 = edx_14 | 1;

    if (!(arg1 & 0x1000))
        ecx_25 = edx_14;

    int32_t ebx_2 = ecx_25 | 0x80000;

    if (!(arg1 & 0x100))
        ebx_2 = ecx_25;

    int32_t eax_10 = arg1 & 0x6000;
    int32_t edx_15 = ebx_2;

    if (eax_10 > 0x4000)
    {
        if (eax_10 == 0x6000)
            edx_15 |= 0x300;
    }
    else if (eax_10 == 0x4000)
        edx_15 |= 0x200;
    else if (eax_10 && eax_10 == 0x2000)
        edx_15 |= 0x100;

    int32_t edi_4 = arg1 & 0x8040;

    if (edi_4 == 0x40)
        edx_15 |= 0x2000000;
    else if (edi_4 == 0x8000)
        edx_15 |= 0x3000000;
    else if (edi_4 == 0x8040)
        edx_15 |= 0x1000000;

    int32_t eax_14 = (~edi_2 & edx_15) | (edi_2 & arg3);

    if (eax_14 != edx_15)
    {
        int32_t eax_15 = sub_40f8e0(eax_14);
        int32_t var_10_1 = eax_15;
        int32_t mxcsr = sub_40c770(eax_15);
        int32_t ecx_30 = mxcsr >> 3 & 0x10;
        int32_t edx_17 = ecx_30 | 8;

        if (!(mxcsr & 0x200))
            edx_17 = ecx_30;

        int32_t ecx_32 = edx_17 | 4;

        if (!(mxcsr & 0x400))
            ecx_32 = edx_17;

        int32_t edx_19 = ecx_32 | 2;

        if (!(mxcsr & 0x800))
            edx_19 = ecx_32;

        int32_t ecx_34 = edx_19 | 1;

        if (!(mxcsr & 0x1000))
            ecx_34 = edx_19;

        int32_t ebx_4 = ecx_34 | 0x80000;

        if (!(mxcsr & 0x100))
            ebx_4 = ecx_34;

        int32_t eax_17 = mxcsr & 0x6000;
        edx_15 = ebx_4;

        if (eax_17 > 0x4000)
        {
            if (eax_17 == 0x6000)
                edx_15 |= 0x300;
        }
        else if (eax_17 == 0x4000)
            edx_15 |= 0x200;
        else if (eax_17 && eax_17 == 0x2000)
            edx_15 |= 0x100;

        int32_t edi_9 = mxcsr & 0x8040;

        if (edi_9 == 0x40)
            edx_15 |= 0x2000000;
        else if (edi_9 == 0x8000)
            edx_15 |= 0x3000000;
        else if (edi_9 == 0x8040)
            edx_15 |= 0x1000000;
    }

    int32_t eax_19 = edx_15 | esi_5;

    if ((edx_15 ^ esi_5) & 0x8031f)
        return eax_19 | 0x80000000;

    return eax_19;
}

uint32_t sub_40fe60(int32_t arg1) __pure
{
    int32_t edi;
    int32_t var_10 = edi;
    int16_t esi_2 = arg1 >> 4 & 1;
    int16_t ecx = esi_2 | 4;

    if (!(arg1 & 8))
        ecx = esi_2;

    int16_t ecx_1 = ecx | 8;

    if (!(arg1 & 4))
        ecx_1 = ecx;

    int16_t ecx_2 = ecx_1 | 0x10;

    if (!(arg1 & 2))
        ecx_2 = ecx_1;

    int16_t ecx_3 = ecx_2 | 0x20;

    if (!(arg1 & 1))
        ecx_3 = ecx_2;

    int16_t ecx_4 = ecx_3 | 2;

    if (!(arg1 & 0x80000))
        ecx_4 = ecx_3;

    int32_t edx_6 = arg1 & 0x300;
    uint32_t eax_15 = ecx_4;
    uint32_t ecx_5;

    if (edx_6 > 0x200)
    {
        ecx_5 = eax_15;

        if (edx_6 == 0x300)
            ecx_5 = eax_15 | 0xc00;
    }
    else if (edx_6 == 0x200)
        ecx_5 = eax_15 | 0x800;
    else
    {
        ecx_5 = eax_15;

        if (edx_6 && edx_6 == 0x100)
            ecx_5 = eax_15 | 0x400;
    }

    int32_t eax_18 = arg1 & 0x30000;

    if (!eax_18)
        ecx_5 |= 0x300;
    else if (eax_18 == 0x10000)
        ecx_5 |= 0x200;

    uint32_t result = ecx_5;

    if (!(arg1 & 0x40000))
        return result;

    return result | 0x1000;
}

int32_t __fastcall __trandisp1(int32_t arg1, void* arg2, void* arg3 @ ebp, long double arg4 @ st0)
{
    int16_t ebx;

    if (*(arg2 + 0xe) != 5)
        ebx = 0x133f;
    else
    {
        ebx = *(arg3 - 0xa4);
        *(&ebx + 1) |= 2;
        *(&ebx + 1) &= 0xfe;
        ebx = 0x3f;
    }

    *(arg3 - 0xa2) = ebx;
    int16_t x87control;
    int16_t x87status;
    x87control = __fldcw_memmem16(*(arg3 - 0xa2));
    bool c0;
    bool c1;
    bool c2;
    bool c3;
    c0 = __fxam(arg4);
    *(arg3 - 0x94) = arg2;
    *(arg3 - 0xa0) =
        (c0 ? 1 : 0) << 8 | (c1 ? 1 : 0) << 9 | (c2 ? 1 : 0) << 0xa | (c3 ? 1 : 0) << 0xe;
    *(arg3 - 0x90) = 0;
    arg1 = *(arg3 - 0x9f);
    arg1 <<= 1;
    arg1 s>>= 1;
    arg1 = ROLB(arg1, 1);
    int32_t eax;
    eax = arg1;
    eax &= 0xf;
    int32_t eax_2 = *(&data_41868e + eax);
    int32_t var_4 = eax_2;
    void* var_8 = arg2;
    int32_t var_c = arg1 & 0x404;
    *(arg2 + eax_2 + 0x10);
    /* jump -> *(arg2 + eax_2 + 0x10) */
}

int32_t sub_410084(int80_t arg1 @ st0) __location("st0") __pure
{
    return arg1;
}

int32_t sub_4100a8()
{
    /* tailcall */
    return sub_4100aa();
}

long double sub_4100aa() __pure
{
    return 0;
}

long double __fastcall __rtzerospop(int16_t arg1) __pure
{
    long double result = 0;

    if (!*(&arg1 + 1))
        return result;

    return -(result);
}

long double sub_4100bd() __pure
{
    return 1;
}

long double __tosnan1(void* arg1 @ ebp, int80_t arg2 @ st0)
{
    *(arg1 - 0x9e) = arg2;
    long double result = *(arg1 - 0x9e);

    if (!(*(arg1 - 0x97) & 0x40))
    {
        *(arg1 - 0x90) = 0;
        return result + 1.0;
    }

    *(arg1 - 0x90) = 0;
    return result;
}

long double sub_4100fb(void* arg1 @ ebp, long double arg2 @ st0, int80_t arg3 @ st1)
{
    *(arg1 - 0x9e) = arg3;
    long double x87_r0_1 = *(arg1 - 0x9e);

    if (!(*(arg1 - 0x97) & 0x40))
        *(arg1 - 0x90) = 0;
    else
        *(arg1 - 0x90) = 0;

    return arg2 + x87_r0_1;
}

long double __nan2(void* arg1 @ ebp, int80_t arg2 @ st0, long double arg3 @ st1)
{
    *(arg1 - 0x9e) = arg2;
    long double x87_r0 = *(arg1 - 0x9e);

    if (*(arg1 - 0x97) & 0x40)
    {
        long double x87_r0_1 = arg3;
        arg3 = x87_r0;
        *(arg1 - 0x9e) = x87_r0_1;
        x87_r0 = *(arg1 - 0x9e);
    }

    if (!(*(arg1 - 0x97) & 0x40) || !(*(arg1 - 0x97) & 0x40))
        *(arg1 - 0x90) = 1;
    else
        *(arg1 - 0x90) = 0;

    return arg3 + x87_r0;
}

int32_t sub_410180()
{
    char ecx;
    void* ebp;
    /* tailcall */
    return sub_410182(ecx, ebp);
}

int32_t __fastcall sub_410182(char arg1, void* arg2 @ ebp) __location("st0")
{
    if (*(arg2 - 0x90) <= 0)
        /* tailcall */
        return sub_410193(arg1, arg2);

    int32_t ecx_1;
    ecx_1 = arg1;
    return data_418660;
}

int32_t __fastcall sub_410193(char arg1, void* arg2 @ ebp)
{
    *(arg2 - 0x90) = 1;
    int32_t ecx;
    ecx = arg1;
}

long double __fastcall __rtatan2inf(int16_t arg1)
{
    long double result = data_418674;
    *(&arg1 + 1) = *(&arg1 + 1);

    if (*(&arg1 + 1))
        result = -(result);

    if (!arg1)
        return result;

    return result * 3.0;
}

void __fastcall sub_4101bd(char arg1, long double arg2 @ st0) __pure
{
    return;
}

long double __convention("regparm") __startTwoArgErrorHandling(int32_t arg1, int32_t arg2, long double arg3 @ st0, int32_t arg4 @ 0xc, int32_t arg5 @ 0x10, int32_t arg6 @ 0x14, int32_t arg7 @ 0x18)
{
    int32_t var_24 = arg1;
    int32_t var_14 = arg6;
    int32_t var_10 = arg7;
    double var_c = arg3;
    int32_t ecx;
    int32_t var_20 = ecx;
    int32_t var_1c = arg4;
    int32_t var_18 = arg5;
    int16_t arg_4;
    sub_4135b0(arg2, &var_24, &arg_4);
    int16_t x87control_1;
    int16_t x87status_1;

    if (arg_4 != 0x27f)
        x87control_1 = __fldcw_memmem16(arg_4);
    return var_c;
}

long double __convention("regparm") __startOneArgErrorHandling(int32_t arg1, int32_t arg2, long double arg3 @ st0, int32_t arg4 @ 0xc, int32_t arg5 @ 0x10)
{
    int32_t var_24 = arg1;
    double var_c = arg3;
    int32_t ecx;
    int32_t var_20 = ecx;
    int32_t var_1c = arg4;
    int32_t var_18 = arg5;
    int16_t arg_4;
    sub_4135b0(arg2, &var_24, &arg_4);
    int16_t x87control_1;
    int16_t x87status_1;

    if (arg_4 != 0x27f)
        x87control_1 = __fldcw_memmem16(arg_4);
    return var_c;
}

char* check_trailing(char* arg1, int32_t arg2)
{
    if (!arg2)
    {
        int32_t eax;
        eax = 1;
        return eax;
    }

    char* eax_1 = arg1;
    char ecx_1;

    while (true)
    {
        ecx_1 = *eax_1;

        if (ecx_1 != 0x30)
            break;

        eax_1 = &eax_1[1];
    }

    eax_1 = ecx_1;
    return eax_1;
}

char* should_round_up(int32_t arg1, char* arg2, int32_t arg3, int32_t arg4, int32_t arg5)
{
    if (!arg5)
    {
        char* eax = arg2;
        eax = *eax >= 0x35;
        return eax;
    }

    char* eax_1 = sub_40c5d0();

    if (!eax_1)
    {
        eax_1 = *arg2;

        if (eax_1 > 0x35)
        {
            eax_1 = 1;
            return eax_1;
        }

        if (eax_1 >= 0x35)
        {
            eax_1 = check_trailing(&arg2[1], arg4);

            if (eax_1)
            {
                eax_1 = 1;
                return eax_1;
            }

            if (arg2 != arg1)
            {
                eax_1 = arg2[0xffffffff];
                eax_1 &= 1;
                return eax_1;
            }
        }
    }
    else if (eax_1 == 0x200)
    {
        eax_1 = check_trailing(arg2, arg4);

        if (eax_1 && arg3 != 0x2d)
        {
            eax_1 = 1;
            return eax_1;
        }
    }
    else if (eax_1 == 0x100)
    {
        eax_1 = check_trailing(arg2, arg4);

        if (eax_1 && arg3 == 0x2d)
        {
            eax_1 = 1;
            return eax_1;
        }
    }

    eax_1 = 0;
    return eax_1;
}

int32_t sub_4102d4(char* arg1, int32_t arg2, int32_t arg3, int32_t* arg4, int32_t arg5, int32_t arg6, int32_t* arg7)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    int32_t edi;
    int32_t var_10 = edi;

    if (!arg1)
    {
        arg7[7] = 1;
        arg7[6] = 0x16;
        __invalid_parameter_internal(0, 0, 0, 0, 0, arg7);
        return 0x16;
    }

    int32_t result;

    if (arg2 <= 0)
        result = 0x16;
    else
    {
        int32_t i = arg3;
        int32_t i_2 = 0;
        *arg1 = 0;

        if (i > 0)
            i_2 = i;

        if (arg2 > i_2 + 1)
        {
            int32_t* ebx_1 = arg4;

            if (ebx_1)
            {
                char* eax_5 = ebx_1[2];
                char* esi_2 = &arg1[1];
                char* var_8_1 = eax_5;
                *arg1 = 0x30;

                if (i > 0)
                {
                    do
                    {
                        char ebx_2 = *eax_5;

                        if (!ebx_2)
                            ebx_2 = 0x30;
                        else
                            eax_5 = &eax_5[1];

                        *esi_2 = ebx_2;
                        esi_2 = &esi_2[1];
                        i -= 1;
                    } while (i > 0);

                    ebx_1 = arg4;
                }

                *esi_2 = 0;

                if (i >= 0 && should_round_up(var_8_1, eax_5, *ebx_1, arg5, arg6))
                {
                    char eax_7;

                    while (true)
                    {
                        esi_2 -= 1;
                        eax_7 = *esi_2;

                        if (eax_7 != 0x39)
                            break;

                        *esi_2 = 0x30;
                    }

                    *esi_2 = eax_7 + 1;
                }

                if (*arg1 != 0x31)
                {
                    char* ecx_1 = &arg1[1];
                    char i_1;

                    do
                    {
                        i_1 = *ecx_1;
                        ecx_1 = &ecx_1[1];
                    } while (i_1);
                    sub_4035c0(arg1, &arg1[1], ecx_1 - &ecx_1[1] + 1);
                }
                else
                    ebx_1[1] += 1;

                return 0;
            }

            result = 0x16;
        }
        else
            result = 0x22;
    }

    arg7[6] = result;
    arg7[7] = 1;
    __invalid_parameter_internal(0, 0, 0, 0, 0, arg7);
    return result;
}

uint32_t sub_4103d0(int32_t* arg1, int32_t* arg2)
{
    int32_t* ebx = arg1;
    int32_t edi;
    int32_t var_238 = edi;
    void* i_6 = *ebx;

    if (i_6)
    {
        void* i_10 = *arg2;

        if (i_10)
        {
            void* var_c_1 = i_6 - 1;

            if (i_10 == 1)
            {
                int32_t edx_1 = arg2[1];
                int32_t var_30_1 = edx_1;
                void var_228;

                if (edx_1 == 1)
                {
                    int32_t esi = ebx[1];
                    void* var_22c = i_10 - 1;
                    *ebx = i_10 - 1;
                    _memcpy_s(&ebx[1], 0x1cc, &var_228, i_10 - 1);
                    return esi;
                }

                if (!(i_6 - 1))
                {
                    int32_t esi_1 = ebx[1];
                    void* var_22c_1 = i_6 - 1;
                    *ebx = i_6 - 1;
                    _memcpy_s(&ebx[1], 0x1cc, &var_228, i_6 - 1);
                    int32_t edx_3 = 0;
                    uint32_t temp1 = COMBINE(edx_3, esi_1) % var_30_1;
                    ebx[1] = temp1;
                    *ebx = -((0 - 0));
                    return COMBINE(edx_3, esi_1) / var_30_1;
                }

                int64_t var_14 = 0;
                int64_t var_58_1 = 0;
                uint32_t edi_5 = 0;
                int32_t var_8 = 0;
                int32_t* var_2c_2;

                if (i_6 - 1 == 0xffffffff)
                    var_2c_2 = nullptr;
                else
                {
                    void* ecx_6 = &ebx[i_6];
                    void* var_c_2 = ecx_6;
                    void* i;

                    do
                    {
                        int32_t* var_23c_3 = ebx;
                        uint32_t eax_6;
                        uint32_t ecx_7;
                        eax_6 = __aulldvrm(*ecx_6, edi_5, edx_1, 0);
                        var_2c_2 = ebx;
                        edi_5 = ecx_7;
                        ebx = var_8 + 0;
                        var_8 = eax_6;
                        edx_1 = var_30_1;
                        ecx_6 = var_c_2 - 4;
                        var_c_2 = ecx_6;
                        i = i_6;
                        i_6 -= 1;
                    } while (i != 1);
                }

                int32_t var_22c_2 = 0;
                *arg1 = 0;
                _memcpy_s(&arg1[1], 0x1cc, &var_228, nullptr);
                arg1[1] = edi_5;
                arg1[2] = var_2c_2;
                *arg1 = -((0 - 0)) + 1;
                return var_8;
            }

            if (i_10 - 1 <= i_6 - 1)
            {
                void* eax_10 = i_6 - 1;
                void* edx_10 = i_6 - 1 - (i_10 - 1);
                int32_t edi_7;
                int32_t temp5_1;

                if (i_6 - 1 >= edx_10)
                {
                    int32_t* ecx_13 = &ebx[i_6];
                    int32_t* esi_5 = &arg2[i_10];

                    while (true)
                    {
                        edi_7 = *esi_5;
                        temp5_1 = *ecx_13;

                        if (edi_7 != temp5_1)
                            break;

                        eax_10 -= 1;
                        esi_5 -= 4;
                        ecx_13 -= 4;

                        if (eax_10 < edx_10)
                            goto label_410575;
                    }
                }

                if (i_6 - 1 < edx_10 || edi_7 < temp5_1)
                {
                label_410575:
                    edx_10 += 1;
                }

                if (edx_10)
                {
                    int32_t ebx_2 = arg2[i_10];
                    int32_t var_8_1 = arg2[i_10 - 1];
                    int32_t eflags;
                    int32_t eax_12;
                    eax_12 = _bit_scan_reverse(ebx_2);
                    int32_t var_3c = ebx_2;
                    int32_t ecx_14;

                    ecx_14 = !edx_10 ? 0x20 : 0x1f - eax_12;

                    if (ecx_14)
                    {
                        char ecx_16 = ecx_14;
                        var_3c = ebx_2 << (ecx_16 & 0x1f) | var_8_1 >> ((0x20 - ecx_14) & 0x1f);
                        int32_t ebx_6 = var_8_1 << (ecx_16 & 0x1f);
                        var_8_1 = ebx_6;

                        if (i_10 > 2)
                            var_8_1 = ebx_6 | arg2[i_10 - 2] >> ((0x20 - ecx_14) & 0x1f);
                    }

                    int64_t var_14_1 = 0;
                    int64_t var_58;
                    *(&var_58 + 4) = edx_10 - 1;
                    int32_t edi_14;

                    if (edx_10 - 1 < 0)
                        edi_14 = 0;
                    else
                    {
                        void* edx_11 = edx_10 - 1 + i_10;
                        void* var_44_1 = edx_11;
                        int32_t* var_48_1 = &arg1[edx_10];
                        int32_t* ecx_21 = &arg1[-1 + edx_11];
                        int32_t* var_30_2 = ecx_21;
                        int32_t var_5c_1 = 0;

                        while (true)
                        {
                            uint32_t edx_12;

                            if (edx_11 > var_c_1)
                                edx_12 = 0;
                            else
                                edx_12 = ecx_21[2];

                            int32_t eax_19 = ecx_21[1];
                            int32_t ebx_9 = *ecx_21;
                            int32_t var_20_1 = 0;
                            uint32_t var_4c_1 = edx_12;
                            int32_t var_1c_1 = eax_19;
                            uint32_t var_20_2 = edx_12;
                            int32_t var_28_1 = ebx_9;

                            if (ecx_14 > 0)
                            {
                                int32_t eax_20;
                                int32_t edx_13;
                                eax_20 = __allshl(eax_19, edx_12, ecx_14);
                                eax_19 = eax_20 | ebx_9 >> ((0x20 - ecx_14) & 0x1f);
                                edx_12 = edx_13;
                                int32_t ebx_10 = ebx_9 << (ecx_14 & 0x1f);
                                var_1c_1 = eax_19;
                                var_20_2 = edx_12;
                                var_28_1 = ebx_10;

                                if (var_44_1 >= 3)
                                {
                                    eax_19 = var_1c_1;
                                    var_28_1 = ebx_10 | var_30_2[-1] >> ((0x20 - ecx_14) & 0x1f);
                                }
                            }

                            uint32_t eax_24;
                            int32_t edx_14;
                            eax_24 = __aulldiv(eax_19, edx_12, var_3c, 0);
                            uint32_t ebx_12 = eax_24;
                            int32_t var_18_1 = edx_14;
                            uint32_t var_40_1 = ebx_12;
                            var_14_1 = ebx_12;
                            *(&var_14_1 + 4) = edx_14;
                            uint32_t edi_11 = __aullrem(var_1c_1, var_20_2, var_3c, 0);
                            int32_t esi_8 = 0;
                            int32_t eax_26 = var_18_1;
                            int32_t var_1c_2 = 0;

                            if (eax_26 || ebx_12 > 0xffffffff)
                            {
                                int32_t eax_28;
                                int32_t edx_15;
                                eax_28 = __allmul(ebx_12 + 1, eax_26 - 1, var_3c, 0);
                                uint32_t temp10_1 = edi_11;
                                edi_11 += eax_28;
                                esi_8 = 0 + edx_15;
                                ebx_12 = 0xffffffff;
                                eax_26 = 0;
                                var_1c_2 = esi_8;
                                var_40_1 = 0xffffffff;
                                var_14_1 = 0xffffffff;
                                var_18_1 = 0;
                                *(&var_14_1 + 4) = 0;
                            }

                            if (esi_8 <= 0 && (esi_8 < 0 || edi_11 <= 0xffffffff))
                            {
                                while (true)
                                {
                                    var_20_2 = var_28_1;
                                    int32_t eax_29;
                                    int32_t edx_16;
                                    eax_29 = __allmul(var_8_1, 0, ebx_12, eax_26);

                                    if (edx_16 < edi_11 || (edx_16 <= edi_11 && eax_29 <= var_20_2))
                                    {
                                        eax_26 = var_18_1;
                                        break;
                                    }

                                    uint32_t temp14_1 = ebx_12;
                                    ebx_12 -= 1;
                                    var_14_1 = ebx_12;
                                    eax_26 = var_18_1 - 1;
                                    uint32_t temp15_1 = edi_11;
                                    edi_11 += var_3c;
                                    var_18_1 = eax_26;
                                    int32_t temp17_1 = var_1c_2 + 0;
                                    var_1c_2 = temp17_1;
                                    *(&var_14_1 + 4) = eax_26;

                                    if (temp17_1)
                                        break;

                                    if (edi_11 > 0xffffffff)
                                        break;

                                    continue;
                                }

                                var_40_1 = ebx_12;
                            }

                            void* edx_20;

                            if (eax_26 || ebx_12)
                            {
                                void* i_8 = i_10;
                                int32_t* eax_31 = arg2;
                                int64_t var_24_1 = 0;
                                uint32_t esi_10 = var_20_2;
                                int32_t edi_12 = 0;

                                if (i_8)
                                {
                                    int32_t* ebx_14 = var_48_1;
                                    int32_t* eax_32 = &eax_31[1];
                                    int32_t* var_c_3 = eax_32;
                                    void* i_4 = i_8;
                                    void* i_1;

                                    do
                                    {
                                        int32_t eax_33 = *eax_32;
                                        int32_t eax_37;
                                        int32_t edx_17;
                                        edx_17 = HIGHD(var_14_1 * eax_33);
                                        eax_37 = LOWD(var_14_1 * eax_33);
                                        int32_t edi_13 = edi_12 + eax_37;
                                        int32_t eax_38 = *ebx_14;
                                        edi_12 = esi_10 + edx_17 + *(&var_14_1 + 4) * eax_33;
                                        esi_10 = 0;

                                        if (eax_38 < edi_13)
                                        {
                                            int32_t temp19_1 = edi_12;
                                            edi_12 += 1;
                                            esi_10 = 0 + 0;
                                        }

                                        *ebx_14 = eax_38 - edi_13;
                                        ebx_14 = &ebx_14[1];
                                        eax_32 = &var_c_3[1];
                                        i_1 = i_4;
                                        i_4 -= 1;
                                        var_c_3 = eax_32;
                                    } while (i_1 != 1);
                                    eax_31 = arg2;
                                    ebx_12 = var_40_1;
                                    i_8 = i_10;
                                }

                                if (0 <= esi_10 && (0 < esi_10 || var_4c_1 < edi_12))
                                {
                                    if (i_8)
                                    {
                                        int32_t* edx_19 = var_48_1;
                                        void* esi_12 = &eax_31[1];
                                        void* i_7 = i_8;
                                        int64_t var_50_1 = 0;
                                        uint32_t ebx_15 = var_4c_1;
                                        int32_t var_4c_2 = 0;
                                        void* i_2;

                                        do
                                        {
                                            int32_t ecx_29 = *edx_19;
                                            esi_12 += 4;
                                            edx_19 = &edx_19[1];
                                            int32_t ecx_30 = ecx_29 + *(esi_12 - 4);
                                            int32_t eax_42 = 0 + 0;
                                            edx_19[-1] = ecx_30 + var_4c_2;
                                            int32_t eax_43 = eax_42 + ebx_15;
                                            ebx_15 = 0;
                                            var_4c_2 = eax_43;
                                            i_2 = i_7;
                                            i_7 -= 1;
                                        } while (i_2 != 1);
                                        ebx_12 = var_40_1;
                                    }

                                    ebx_12 -= 1;
                                }

                                edx_20 = var_44_1;
                                var_c_1 = edx_20 - 1;
                            }
                            else
                                edx_20 = var_44_1;

                            edi_14 = ebx_12;
                            var_5c_1 = edi_14;
                            var_48_1 -= 4;
                            int32_t ebx_17 = *(&var_58 + 4) - 1;
                            edx_11 = edx_20 - 1;
                            *(&var_58 + 4) = ebx_17;
                            ecx_21 = var_30_2 - 4;
                            var_44_1 = edx_11;
                            var_30_2 = ecx_21;

                            if (ebx_17 < 0)
                                break;
                        }
                    }

                    void* i_5 = var_c_1 + 1;
                    void* i_3 = i_5;

                    if (i_3 < *arg1)
                    {
                        int32_t* edx_22 = &arg1[1 + i_3];

                        do
                        {
                            *edx_22 = 0;
                            edx_22 = &edx_22[1];
                            i_3 += 1;
                        } while (i_3 < *arg1);
                    }

                    *arg1 = i_5;

                    if (i_5)
                    {
                        while (!arg1[i_5])
                        {
                            void* i_9 = i_5;
                            i_5 -= 1;
                            *arg1 = i_5;

                            if (i_9 == 1)
                                break;
                        }
                    }

                    return edi_14;
                }
            }
        }
    }

    return 0;
}

int32_t sub_4108a7(int32_t arg1 @ 0x8, void* arg2, int32_t arg3, int32_t* arg4, char* arg5, int32_t arg6)
{
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    int32_t var_7a4;
    _fegetenv(&var_7a4);
    int32_t result = 1;
    char var_79c;

    if ((var_7a4 & 0x1f) != 0x1f)
    {
        sub_413770(&var_7a4);
        var_79c = 1;
    }
    else
        var_79c = 0;

    int32_t edi;
    int32_t var_b54 = edi;
    int32_t arg_4;
    int32_t eax_6;

    eax_6 = arg1 > 0 || (arg1 >= 0 && arg_4 >= 0) ? 0x20 : 0x2d;

    *arg4 = eax_6;
    arg4[2] = arg5;
    int32_t var_7a8;
    sub_409550(&var_7a8, 0, 0);
    char const* const var_b58;

    if (arg1 & 0x7ff00000 || (arg_4 | (arg1 & 0xfffff) && !(var_7a8 & 0x1000000)))
    {
        int32_t eax_12 = __acrt_fp_classify(&arg_4);

        if (!eax_12)
        {
        label_410a0d:
            arg_4 = arg_4;
            arg1 &= 0x7fffffff;
            int32_t var_794_1 = 0x8001f;
            int32_t var_798;
            sub_409550(&var_798, 0, 0);
            double var_774;
            int32_t mxcsr_1;
            int16_t x87control_1;
            mxcsr_1 = sub_409550((&var_774 + 4), 0x8001f, var_794_1);
            int64_t xmm1_1 = arg_4;
            int64_t var_77c_1 = xmm1_1;
            int32_t edi_3 = *(&var_77c_1 + 4);
            uint32_t ecx_10 = edi_3 >> 0x14;
            int32_t var_770_1 = 0;
            int32_t var_758_1;
            int32_t eax_25;
            int32_t edx_1;

            if (ecx_10 & 0x7ff)
            {
                var_758_1 = 0;
                eax_25 = 0;
                edx_1 = 0x100000;
            }
            else
            {
                eax_25 = 1;
                var_774 = 0.0;
                edx_1 = var_770_1;
                var_758_1 = var_774;
            }

            int32_t esi_3 = var_77c_1;
            int32_t edi_5 = (edi_3 & 0xfffff) + edx_1;
            int32_t eax_26 = eax_25 + (ecx_10 & 0x7ff);
            int32_t ecx_12;
            int16_t x87control_2;
            double xmm0_2;
            ecx_12 = __libm_sse2_log10_precise(mxcsr_1, x87control_1, xmm1_1);
            int32_t var_b58_2 = ecx_12;
            var_774 = xmm0_2;
            int32_t var_b5c_2 = ecx_12;
            var_b5c_2 = var_774;
            var_774 = sub_413ac0(mxcsr_1, x87control_2, var_b5c_2);
            int32_t ecx_13 = var_774;
            int32_t var_764_1 = ecx_13;

            if (ecx_13 == 0x7fffffff || ecx_13 == 0x80000000)
                var_764_1 = 0;

            void* edx_2 = nullptr;
            int32_t var_1d4 = esi_3 + var_758_1;
            int32_t eax_28 = eax_26;
            edx_2 = edi_5;
            int32_t var_1d0_1 = edi_5;
            char* i_17 = nullptr;
            char* i_32 = edx_2 + 1;
            char* i_18 = i_32;
            int32_t var_574;
            uint32_t var_3a4[0x4];

            if (eax_28 < 0x433)
            {
                if (eax_28 != 0x35)
                {
                    var_574 = 0;
                    int32_t var_570_3 = 0x100000;
                    int32_t var_578_5 = 2;
                }

                uint32_t edi_14;

                if (eax_28 == 0x35 || !edi_5)
                {
                label_41103e:
                    int32_t eax_76 = 8;

                    if (!edi_5)
                        eax_76 = 4;

                    int32_t var_770_5 = 0;
                    int32_t eflags_4;
                    int32_t eax_78;
                    eax_78 = _bit_scan_reverse(*(&i_18 + eax_76));
                    int32_t eax_79 = 0;
                    char* i_38 = &i_32[-((0x20 - eax_79 - (0x20 - eax_79)))];

                    if (i_38 <= 0x73)
                    {
                        void* ecx_37 = &i_38[0xffffffff];

                        if (ecx_37 != 0xffffffff)
                        {
                            void* ebx_3 = ecx_37 - 1;

                            while (true)
                            {
                                void* edi_15 = ecx_37;
                                int32_t eax_80;

                                if (ecx_37 >= i_32)
                                    eax_80 = 0;
                                else
                                    eax_80 = (&var_1d4)[edi_15];

                                int32_t edx_12;

                                if (ebx_3 >= i_32)
                                    edx_12 = 0;
                                else
                                    edx_12 = (&i_18)[edi_15];

                                ecx_37 -= 1;
                                ebx_3 -= 1;
                                (&var_1d4)[edi_15] = edx_12 >> 0x1f | (eax_80 * 2);

                                if (ecx_37 == 0xffffffff)
                                    break;

                                i_32 = i_18;
                            }
                        }

                        i_18 = i_38;
                    }
                    else
                    {
                        int32_t var_578_7 = 0;
                        i_18 = nullptr;
                        _memcpy_s(&var_1d4, 0x1cc, &var_574, nullptr);
                    }

                    edi_14 = (0x434 - eax_26) >> 5;
                    _memset(&var_574, 0, edi_14 << 2);
                    (&var_574)[edi_14] = 1 << ((0x434 - eax_26) & 0x1f);
                }
                else
                {
                    int32_t ecx_34 = 0;

                    while (true)
                    {
                        if (*(&var_574 + ecx_34) != *(&var_1d4 + ecx_34))
                            goto label_41103e;

                        ecx_34 += 4;

                        if (ecx_34 == 8)
                        {
                            int32_t eflags_3;
                            int32_t eax_71;
                            eax_71 = _bit_scan_reverse(edi_5);
                            int32_t var_770_4 = 0;
                            int32_t eax_72 = 0;
                            char* i_37 = &i_32[-((0x20 - eax_72 - (0x20 - eax_72)))];

                            if (i_37 <= 0x73)
                            {
                                void* ecx_35 = &i_37[0xffffffff];

                                if (ecx_35 != 0xffffffff)
                                {
                                    void* ebx = ecx_35 - 1;

                                    while (true)
                                    {
                                        void* edi_12 = ecx_35;
                                        int32_t eax_73;

                                        if (ecx_35 >= i_32)
                                            eax_73 = 0;
                                        else
                                            eax_73 = (&var_1d4)[edi_12];

                                        int32_t edx_9;

                                        if (ebx >= i_32)
                                            edx_9 = 0;
                                        else
                                            edx_9 = (&i_18)[edi_12];

                                        ecx_35 -= 1;
                                        ebx -= 1;
                                        (&var_1d4)[edi_12] = edx_9 >> 0x1e | eax_73 << 2;

                                        if (ecx_35 == 0xffffffff)
                                            break;

                                        i_32 = i_18;
                                    }
                                }

                                i_18 = i_37;
                            }
                            else
                            {
                                int32_t var_578_6 = 0;
                                i_18 = nullptr;
                                _memcpy_s(&var_1d4, 0x1cc, &var_574, nullptr);
                            }

                            edi_14 = (0x435 - eax_26) >> 5;
                            _memset(&var_574, 0, edi_14 << 2);
                            (&var_574)[edi_14] = 1 << ((0x435 - eax_26) & 0x1f);
                            break;
                        }
                    }
                }

                char* var_578_8 = edi_14 + 1;
                i_17 = edi_14 + 1;
                _memcpy_s(&var_3a4, 0x1cc, &var_574, (edi_14 + 1) << 2);
                result = 1;
            }
            else
            {
                var_574 = 0;
                int32_t var_570_1 = 0x100000;
                int32_t var_578_1 = 2;

                if (!edi_5)
                {
                label_410d7b:
                    int32_t ecx_26 = (eax_28 - 0x432) & 0x1f;
                    uint32_t eax_51 = (eax_28 - 0x432) >> 5;
                    char var_788_2 = (0x20 - ecx_26);
                    int32_t eax_53 = 0;
                    int32_t edi_9 = 1 << ((0x20 - ecx_26) % 0x20);

                    if (0x20 - ecx_26 >= 0x20)
                        eax_53 = edi_9;

                    int32_t var_770_3 = 0;
                    int32_t edi_10 = edi_9 ^ eax_53;
                    *(&var_77c_1 + 4) = ~(edi_10 - 1);
                    int32_t eflags_2;
                    int32_t eax_57;
                    eax_57 = _bit_scan_reverse((&i_18)[i_32]);
                    int32_t var_75c_2;

                    var_75c_2 = edi_10 == 1 ? 0 : eax_57 + 1;

                    uint32_t ecx_28 = eax_51;
                    char* i_36;

                    if (&i_32[ecx_28] <= 0x73)
                        i_36 = -((0x20 - var_75c_2 - (0x20 - var_75c_2))) + ecx_28 + i_32;

                    if (&i_32[ecx_28] > 0x73 || i_36 > 0x73)
                    {
                        int32_t var_578_4 = 0;
                        i_18 = nullptr;
                        _memcpy_s(&var_1d4, 0x1cc, &var_574, nullptr);
                    }
                    else
                    {
                        void* var_750_2 = &i_36[0xffffffff];

                        if (&i_36[0xffffffff] != ecx_28 - 1)
                        {
                            void* esi_16 = &i_36[0xffffffff] - ecx_28;
                            int32_t* ecx_29 = &(&i_18)[esi_16];
                            int32_t* var_758_4 = ecx_29;

                            while (true)
                            {
                                int32_t eax_62;

                                if (esi_16 >= i_32)
                                    eax_62 = 0;
                                else
                                    eax_62 = ecx_29[1];

                                int32_t eax_64;

                                if (esi_16 - 1 >= i_32)
                                    eax_64 = 0;
                                else
                                    eax_64 = *ecx_29;

                                (&var_1d4)[var_750_2] =
                                    (eax_64 & *(&var_77c_1 + 4)) >> (var_788_2 & 0x1f)
                                    | (eax_62 & (edi_10 - 1)) << (ecx_26 & 0x1f);
                                void* eax_69 = var_750_2 - 1;
                                ecx_29 = var_758_4 - 4;
                                var_750_2 = eax_69;
                                esi_16 -= 1;
                                var_758_4 = ecx_29;

                                if (eax_69 == ecx_28 - 1)
                                    break;

                                i_32 = i_18;
                            }

                            ecx_28 = eax_51;
                        }

                        if (ecx_28)
                            __builtin_memset(&var_1d4, 0, ecx_28 << 2);

                        i_18 = i_36;
                    }

                    var_574 = 2;
                    int32_t var_b58_4 = 4;
                }
                else
                {
                    int32_t ecx_14 = 0;

                    while (true)
                    {
                        if (*(&var_574 + ecx_14) != *(&var_1d4 + ecx_14))
                        {
                            eax_28 = eax_26;
                            goto label_410d7b;
                        }

                        ecx_14 += 4;

                        if (ecx_14 == 8)
                        {
                            int32_t ecx_17 = (eax_26 - 0x431) & 0x1f;
                            uint32_t eax_31 = (eax_26 - 0x431) >> 5;
                            char var_784_1 = (0x20 - ecx_17);
                            int32_t eax_33 = 0;
                            int32_t edi_6 = 1 << ((0x20 - ecx_17) % 0x20);

                            if (0x20 - ecx_17 >= 0x20)
                                eax_33 = edi_6;

                            int32_t var_770_2 = 0;
                            int32_t edi_7 = edi_6 ^ eax_33;
                            int32_t eflags_1;
                            int32_t eax_37;
                            eax_37 = _bit_scan_reverse((&i_18)[i_32]);
                            int32_t var_758_2;

                            var_758_2 = edi_7 == 1 ? 0 : eax_37 + 1;

                            uint32_t ecx_19 = eax_31;
                            char* i_35;

                            if (&i_32[ecx_19] <= 0x73)
                            {
                                i_35 = &i_32[-((0x20 - var_758_2 - (0x20 - var_758_2))) + ecx_19];
                                *(&var_77c_1 + 4) = i_35;
                            }

                            if (&i_32[ecx_19] > 0x73 || i_35 > 0x73)
                            {
                                int32_t var_578_2 = 0;
                                i_18 = nullptr;
                                _memcpy_s(&var_1d4, 0x1cc, &var_574, nullptr);
                            }
                            else
                            {
                                void* var_750_1 = &i_35[0xffffffff];

                                if (&i_35[0xffffffff] != ecx_19 - 1)
                                {
                                    void* esi_10 = &i_35[0xffffffff] - ecx_19;
                                    int32_t* ecx_20 = &(&i_18)[esi_10];
                                    int32_t* var_74c_2 = ecx_20;

                                    while (true)
                                    {
                                        int32_t eax_42;

                                        if (esi_10 >= i_32)
                                            eax_42 = 0;
                                        else
                                            eax_42 = ecx_20[1];

                                        int32_t eax_44;

                                        if (esi_10 - 1 >= i_32)
                                            eax_44 = 0;
                                        else
                                            eax_44 = *ecx_20;

                                        (&var_1d4)[var_750_1] =
                                            (eax_44 & ~(edi_7 - 1)) >> (var_784_1 & 0x1f)
                                            | (eax_42 & (edi_7 - 1)) << (ecx_17 & 0x1f);
                                        void* eax_49 = var_750_1 - 1;
                                        ecx_20 = var_74c_2 - 4;
                                        var_750_1 = eax_49;
                                        esi_10 -= 1;
                                        var_74c_2 = ecx_20;

                                        if (eax_49 == ecx_19 - 1)
                                            break;

                                        i_32 = i_18;
                                    }

                                    i_35 = *(&var_77c_1 + 4);
                                    ecx_19 = eax_31;
                                }

                                if (ecx_19)
                                    __builtin_memset(&var_1d4, 0, ecx_19 << 2);

                                i_18 = i_35;
                            }

                            var_574 = 4;
                            int32_t var_b58_3 = 4;
                            break;
                        }
                    }
                }

                int32_t var_570_2 = 0;
                i_17 = 1;
                int32_t var_578_3 = 1;
                _memcpy_s(&var_3a4, 0x1cc, &var_574, 4);
            }

            int32_t edx_15 = 0;
            int32_t var_780_4 = 0xa;
            void var_974;
            void var_b44;
            int32_t var_744[0x73];

            if (var_764_1 < 0)
            {
                int32_t eax_121 = -(var_764_1);
                uint32_t eax_122 = COMBINE(edx_15, eax_121) / 0xa;
                uint32_t var_76c_4 = eax_122;

                if (eax_122)
                {
                    while (true)
                    {
                        uint32_t ecx_50 = eax_122;

                        if (eax_122 > 0x26)
                            ecx_50 = 0x26;

                        uint32_t esi_33 = *((ecx_50 << 2) + &data_4197a7);
                        uint32_t ecx_51 = *((ecx_50 << 2) + &data_4197a6);
                        _memset(&var_574, 0, ecx_51 << 2);
                        sub_4035c0(&(&var_574)[ecx_51],
                            (*((ecx_50 << 2) + &data_4197a4) << 2) + &data_418ea0, esi_33 << 2);
                        uint32_t i_34 = ecx_51 + esi_33;
                        char eax_135;
                        int32_t ecx_52;

                        if (i_34 <= 1)
                        {
                            int32_t esi_34 = var_574;

                            if (!esi_34)
                            {
                            label_41168f:
                                int32_t var_978_2 = 0;
                                i_18 = nullptr;
                                _memcpy_s(&var_1d4, 0x1cc, &var_974, nullptr);
                                eax_135 = 1;
                            }
                            else if (esi_34 == 1 || !i_18)
                                eax_135 = 1;
                            else
                            {
                                ecx_52 = 0;
                                *(&var_77c_1 + 4) = i_18;
                                int32_t i = 0;

                                do
                                {
                                    void* eax_133;
                                    int32_t edx_31;
                                    edx_31 = HIGHD(esi_34 * (&var_1d4)[i]);
                                    eax_133 = LOWD(esi_34 * (&var_1d4)[i]);
                                    (&var_1d4)[i] = eax_133 + ecx_52;
                                    i += 1;
                                    ecx_52 = edx_31 + 0;
                                } while (i != *(&var_77c_1 + 4));

                            label_4116ec:

                                if (!ecx_52)
                                    eax_135 = 1;
                                else
                                {
                                    char* i_21 = i_18;

                                    if (i_21 >= 0x73)
                                    {
                                        int32_t var_978_3 = 0;
                                        i_18 = nullptr;
                                        _memcpy_s(&var_1d4, 0x1cc, &var_974, nullptr);
                                        eax_135 = 0;
                                    }
                                    else
                                    {
                                        (&var_1d4)[i_21] = ecx_52;
                                        i_18 = &i_18[1];
                                        eax_135 = 1;
                                    }
                                }
                            }
                        }
                        else if (i_18 > 1)
                        {
                            uint32_t i_29 = i_18;
                            bool c_15 = i_34 < i_29;
                            int32_t* esi_35 = &var_574;

                            if (!c_15)
                                esi_35 = &var_1d4;

                            int32_t* esi_36 = &var_1d4;

                            if (!c_15)
                                esi_36 = &var_574;

                            *(&var_77c_1 + 4) = esi_36;
                            uint32_t i_43 = i_29;

                            if (c_15)
                                i_43 = i_34;

                            uint32_t i_45 = i_43;

                            if (c_15)
                                i_34 = i_29;

                            char* i_16 = nullptr;
                            char* i_12 = nullptr;
                            uint32_t i_40 = i_34;
                            char* i_14 = nullptr;

                            if (i_43)
                            {
                                int32_t* ecx_53 = esi_35;

                                while (true)
                                {
                                    if (ecx_53[i_12])
                                    {
                                        int32_t i_8 = 0;
                                        char* i_1 = i_12;
                                        void* var_750_5 = nullptr;

                                        if (i_34)
                                        {
                                            while (i_1 != 0x73)
                                            {
                                                if (i_1 == i_16)
                                                {
                                                    var_744[i_1] = 0;
                                                    i_14 = var_750_5 + 1 + i_12;
                                                }

                                                int32_t eax_146;
                                                int32_t edx_37;
                                                edx_37 = HIGHD(
                                                    *(*(&var_77c_1 + 4) + (var_750_5 << 2))
                                                    * esi_35[i_12]);
                                                eax_146 = LOWD(
                                                    *(*(&var_77c_1 + 4) + (var_750_5 << 2))
                                                    * esi_35[i_12]);
                                                int32_t eax_147 = eax_146 + var_744[i_1];
                                                int32_t edx_38 = edx_37 + 0;
                                                var_744[i_1] = eax_147 + i_8;
                                                i_16 = i_14;
                                                void* ecx_57 = var_750_5 + 1;
                                                i_8 = edx_38 + 0;
                                                i_1 = &i_1[1];
                                                i_34 = i_40;
                                                var_750_5 = ecx_57;

                                                if (ecx_57 == i_34)
                                                    break;
                                            }

                                            if (i_8)
                                            {
                                                int32_t* var_760_4 = &var_744[i_1];
                                                int32_t i_2;

                                                do
                                                {
                                                    if (i_1 == 0x73)
                                                        goto label_411a27;

                                                    char* i_10 = &i_1[1];
                                                    bool cond:16_1 = i_1 != i_16;
                                                    i_1 = i_10;

                                                    if (!cond:16_1)
                                                    {
                                                        *var_760_4 = 0;
                                                        i_14 = i_10;
                                                    }

                                                    int32_t* ecx_59 = var_760_4;
                                                    var_760_4 = &var_760_4[1];
                                                    int32_t var_74c_5 = 0;
                                                    int32_t temp34_1 = *ecx_59;
                                                    *ecx_59 += i_8;
                                                    i_16 = i_14;
                                                    i_2 = var_74c_5 + 0;
                                                    i_8 = i_2;
                                                } while (i_2);
                                            }
                                        }

                                        if (i_1 == 0x73)
                                        {
                                        label_411a27:
                                            int32_t var_b48_2 = 0;
                                            i_18 = nullptr;
                                            _memcpy_s(&var_1d4, 0x1cc, &var_b44, nullptr);
                                            break;
                                        }

                                        i_43 = i_45;
                                        ecx_53 = esi_35;
                                    }
                                    else if (i_12 == i_16)
                                    {
                                        var_744[i_12] = 0;
                                        i_16 = &i_12[1];
                                        i_14 = i_16;
                                    }

                                    i_12 = &i_12[1];

                                    if (i_12 == i_43)
                                        goto label_41195b;
                                }

                                break;
                            }

                        label_41195b:
                            i_18 = i_16;
                            _memcpy_s(&var_1d4, 0x1cc, &var_744, i_16 << 2);
                            eax_135 = 1;
                        }
                        else
                        {
                            int32_t edi_24 = var_1d4;
                            i_18 = i_34;
                            _memcpy_s(&var_1d4, 0x1cc, &var_574, i_34 << 2);

                            if (!edi_24)
                                goto label_41168f;

                            if (edi_24 != 1 && i_18)
                            {
                                ecx_52 = 0;
                                *(&var_77c_1 + 4) = i_18;
                                int32_t i_3 = 0;

                                do
                                {
                                    void* eax_140;
                                    int32_t edx_33;
                                    edx_33 = HIGHD(edi_24 * (&var_1d4)[i_3]);
                                    eax_140 = LOWD(edi_24 * (&var_1d4)[i_3]);
                                    (&var_1d4)[i_3] = eax_140 + ecx_52;
                                    i_3 += 1;
                                    ecx_52 = edx_33 + 0;
                                } while (i_3 != *(&var_77c_1 + 4));

                                goto label_4116ec;
                            }

                            eax_135 = 1;
                        }

                        if (!eax_135)
                            break;

                        eax_122 = var_76c_4 - ecx_50;
                        bool cond:13_1 = var_76c_4 != ecx_50;
                        var_76c_4 = eax_122;

                        if (!cond:13_1)
                            goto label_4119ad;
                    }

                    goto label_411a50;
                }

            label_4119ad:
                uint32_t temp1_4 = COMBINE(0, eax_121) % 0xa;

                if (temp1_4)
                {
                    int32_t eax_156 = *((temp1_4 << 2) + &data_41983c);
                    int32_t var_770_7 = eax_156;

                    if (!eax_156)
                    {
                    label_411a50:
                        int32_t var_b58_14 = 0;
                        int32_t var_978_4 = 0;
                        i_18 = nullptr;
                        _memcpy_s(&var_1d4, 0x1cc, &var_974, nullptr);
                    }
                    else if (eax_156 != 1)
                    {
                        char* i_30 = i_18;

                        if (i_30)
                        {
                            int32_t esi_37 = 0;
                            int32_t edi_25 = 0;

                            do
                            {
                                int32_t eax_157;
                                int32_t edx_42;
                                edx_42 = HIGHD(eax_156 * (&var_1d4)[edi_25]);
                                eax_157 = LOWD(eax_156 * (&var_1d4)[edi_25]);
                                (&var_1d4)[edi_25] = eax_157 + esi_37;
                                eax_156 = var_770_7;
                                edi_25 += 1;
                                esi_37 = edx_42 + 0;
                            } while (edi_25 != i_30);

                            if (esi_37)
                            {
                                char* i_22 = i_18;

                                if (i_22 >= 0x73)
                                    goto label_411a50;

                                (&var_1d4)[i_22] = esi_37;
                                i_18 = &i_18[1];
                            }
                        }
                    }
                }
            }
            else
            {
                uint32_t eax_86 = COMBINE(edx_15, var_764_1) / 0xa;
                char* i_28 = i_17;
                uint32_t var_76c_3 = eax_86;

                if (eax_86)
                {
                    char* i_41 = i_28;

                    while (true)
                    {
                        uint32_t ecx_39 = eax_86;

                        if (eax_86 > 0x26)
                            ecx_39 = 0x26;

                        uint32_t esi_27 = *((ecx_39 << 2) + &data_4197a7);
                        uint32_t ecx_40 = *((ecx_39 << 2) + &data_4197a6);
                        _memset(&var_574, 0, ecx_40 << 2);
                        sub_4035c0(&(&var_574)[ecx_40],
                            (*((ecx_39 << 2) + &data_4197a4) << 2) + &data_418ea0, esi_27 << 2);
                        char* i_33 = ecx_40 + esi_27;
                        char eax_98;
                        void* var_b58_8;
                        int32_t* eax_94;
                        int32_t esi_28;

                        if (i_33 > 1)
                        {
                            if (i_41 > 1)
                            {
                                bool c_8 = i_33 < i_41;
                                int32_t* esi_30 = &var_574;

                                if (!c_8)
                                    esi_30 = &var_3a4;

                                uint32_t (* esi_31)[0x4] = &var_3a4;

                                if (!c_8)
                                    esi_31 = &var_574;

                                *(&var_77c_1 + 4) = esi_31;
                                char* i_42 = i_41;

                                if (c_8)
                                    i_42 = i_33;

                                char* i_44 = i_42;

                                if (c_8)
                                    i_33 = i_41;

                                char* i_15 = nullptr;
                                char* i_11 = nullptr;
                                char* i_39 = i_33;
                                char* i_13 = nullptr;

                                if (!i_42)
                                {
                                label_4114d2:
                                    i_17 = i_15;
                                    var_b58_8 = i_15 << 2;
                                    eax_94 = &var_744;
                                    goto label_4114ef;
                                }

                                int32_t* ecx_43 = esi_30;

                                while (true)
                                {
                                    if (ecx_43[i_11])
                                    {
                                        int32_t i_7 = 0;
                                        char* i_4 = i_11;
                                        void* var_750_3 = nullptr;

                                        if (i_33)
                                        {
                                            while (i_4 != 0x73)
                                            {
                                                if (i_4 == i_15)
                                                {
                                                    var_744[i_4] = 0;
                                                    i_13 = var_750_3 + 1 + i_11;
                                                }

                                                int32_t eax_108;
                                                int32_t edx_23;
                                                edx_23 = HIGHD(
                                                    *(*(&var_77c_1 + 4) + (var_750_3 << 2))
                                                    * esi_30[i_11]);
                                                eax_108 = LOWD(
                                                    *(*(&var_77c_1 + 4) + (var_750_3 << 2))
                                                    * esi_30[i_11]);
                                                int32_t eax_109 = eax_108 + i_7;
                                                int32_t temp33_1 = var_744[i_4];
                                                var_744[i_4] += eax_109;
                                                i_15 = i_13;
                                                void* ecx_47 = var_750_3 + 1;
                                                i_7 = edx_23 + 0 + 0;
                                                i_33 = i_39;
                                                i_4 = &i_4[1];
                                                var_750_3 = ecx_47;

                                                if (ecx_47 == i_33)
                                                    break;
                                            }

                                            if (i_7)
                                            {
                                                int32_t* var_750_4 = &var_744[i_4];
                                                int32_t i_5;

                                                do
                                                {
                                                    if (i_4 == 0x73)
                                                        goto label_4115ab;

                                                    char* i_9 = &i_4[1];
                                                    bool cond:17_1 = i_4 != i_15;
                                                    i_4 = i_9;

                                                    if (!cond:17_1)
                                                    {
                                                        *var_750_4 = 0;
                                                        i_13 = i_9;
                                                    }

                                                    int32_t* ecx_49 = var_750_4;
                                                    var_750_4 = &var_750_4[1];
                                                    int32_t var_74c_4 = 0;
                                                    int32_t temp36_1 = *ecx_49;
                                                    *ecx_49 += i_7;
                                                    i_15 = i_13;
                                                    i_5 = var_74c_4 + 0;
                                                    i_7 = i_5;
                                                } while (i_5);
                                            }
                                        }

                                        if (i_4 == 0x73)
                                        {
                                        label_4115ab:
                                            int32_t var_b48_1 = 0;
                                            i_17 = nullptr;
                                            _memcpy_s(&var_3a4, 0x1cc, &var_b44, nullptr);
                                            break;
                                        }

                                        i_42 = i_44;
                                        ecx_43 = esi_30;
                                    }
                                    else if (i_11 == i_15)
                                    {
                                        var_744[i_11] = 0;
                                        i_15 = &i_11[1];
                                        i_13 = i_15;
                                    }

                                    i_11 = &i_11[1];

                                    if (i_11 == i_42)
                                        goto label_4114d2;
                                }

                                break;
                            }

                            uint32_t esi_29 = var_3a4[0];
                            *(&var_77c_1 + 4) = esi_29;
                            i_17 = i_33;
                            _memcpy_s(&var_3a4, 0x1cc, &var_574, i_33 << 2);

                            if (!esi_29)
                                goto label_411200;

                            i_28 = i_17;
                            i_41 = i_28;

                            if (esi_29 == 1 || !i_28)
                                eax_98 = 1;
                            else
                            {
                                esi_28 = 0;
                                int32_t edi_20 = 0;

                                do
                                {
                                    void* eax_102;
                                    int32_t edx_19;
                                    edx_19 = HIGHD(*(&var_77c_1 + 4) * var_3a4[edi_20]);
                                    eax_102 = LOWD(*(&var_77c_1 + 4) * var_3a4[edi_20]);
                                    var_3a4[edi_20] = eax_102 + esi_28;
                                    edi_20 += 1;
                                    esi_28 = edx_19 + 0;
                                } while (edi_20 != i_28);

                            label_411256:

                                if (!esi_28)
                                    goto label_4114f7;

                                char* i_19 = i_17;

                                if (i_19 >= 0x73)
                                {
                                    int32_t var_578_11 = 0;
                                    i_17 = nullptr;
                                    _memcpy_s(&var_3a4, 0x1cc, &var_574, nullptr);
                                    i_28 = i_17;
                                    eax_98 = 0;
                                    i_41 = i_28;
                                }
                                else
                                {
                                    var_3a4[i_19] = esi_28;
                                    i_28 = &i_17[1];
                                    i_17 = i_28;
                                    i_41 = i_28;
                                    eax_98 = 1;
                                }
                            }
                        }
                        else if (var_574)
                        {
                            i_28 = i_41;

                            if (var_574 != 1 && i_28)
                            {
                                esi_28 = 0;
                                int32_t edi_19 = 0;

                                do
                                {
                                    void* eax_96;
                                    int32_t edx_17;
                                    edx_17 = HIGHD(var_574 * var_3a4[edi_19]);
                                    eax_96 = LOWD(var_574 * var_3a4[edi_19]);
                                    var_3a4[edi_19] = eax_96 + esi_28;
                                    edi_19 += 1;
                                    esi_28 = edx_17 + 0;
                                } while (edi_19 != i_28);

                                goto label_411256;
                            }

                            eax_98 = 1;
                        }
                        else
                        {
                        label_411200:
                            int32_t var_578_10 = 0;
                            i_17 = nullptr;
                            var_b58_8 = nullptr;
                            eax_94 = &var_574;
                        label_4114ef:
                            _memcpy_s(&var_3a4, 0x1cc, eax_94, var_b58_8);
                        label_4114f7:
                            i_28 = i_17;
                            i_41 = i_28;
                            eax_98 = 1;
                        }

                        if (!eax_98)
                            break;

                        eax_86 = var_76c_3 - ecx_39;
                        bool cond:14_1 = var_76c_3 != ecx_39;
                        var_76c_3 = eax_86;

                        if (!cond:14_1)
                            goto label_411530;
                    }

                    goto label_4115d4;
                }

            label_411530:
                uint32_t temp1_2 = COMBINE(0, var_764_1) % 0xa;

                if (temp1_2)
                {
                    int32_t eax_117 = *((temp1_2 << 2) + &data_41983c);
                    *(&var_77c_1 + 4) = eax_117;

                    if (!eax_117)
                    {
                    label_4115d4:
                        int32_t var_b58_10 = 0;
                        int32_t var_978_1 = 0;
                        i_17 = nullptr;
                        _memcpy_s(&var_3a4, 0x1cc, &var_974, nullptr);
                    }
                    else if (eax_117 != 1 && i_28)
                    {
                        int32_t esi_32 = 0;
                        int32_t edi_21 = 0;

                        do
                        {
                            int32_t eax_118;
                            int32_t edx_28;
                            edx_28 = HIGHD(eax_117 * var_3a4[edi_21]);
                            eax_118 = LOWD(eax_117 * var_3a4[edi_21]);
                            var_3a4[edi_21] = eax_118 + esi_32;
                            eax_117 = *(&var_77c_1 + 4);
                            edi_21 += 1;
                            esi_32 = edx_28 + 0;
                        } while (edi_21 != i_28);

                        if (esi_32)
                        {
                            char* i_20 = i_17;

                            if (i_20 >= 0x73)
                                goto label_4115d4;

                            var_3a4[i_20] = esi_32;
                            i_17 = &i_17[1];
                        }
                    }
                }
            }
            char* edi_27 = arg5;
            char* esi_38 = edi_27;
            char* i_31 = i_18;
            char* var_74c_6 = esi_38;

            if (i_31)
            {
                int32_t edi_26 = 0;
                int32_t esi_39 = 0;

                do
                {
                    int32_t eax_160;
                    int32_t edx_44;
                    edx_44 = HIGHD((&var_1d4)[esi_39] * 0xa);
                    eax_160 = LOWD((&var_1d4)[esi_39] * 0xa);
                    (&var_1d4)[esi_39] = eax_160 + edi_26;
                    esi_39 += 1;
                    edi_26 = edx_44 + 0;
                } while (esi_39 != i_31);

                esi_38 = var_74c_6;

                if (edi_26)
                {
                    char* i_23 = i_18;

                    if (i_23 >= 0x73)
                    {
                        int32_t var_978_5 = 0;
                        i_18 = nullptr;
                        _memcpy_s(&var_1d4, 0x1cc, &var_974, nullptr);
                    }
                    else
                    {
                        (&var_1d4)[i_23] = edi_26;
                        i_18 = &i_18[1];
                    }
                }

                edi_27 = esi_38;
            }

            uint32_t eax_162 = sub_4103d0(&i_18, &i_17);
            int32_t eax_167;

            if (eax_162 == 0xa)
            {
                var_764_1 += 1;
                esi_38 = &edi_27[1];
                char* i_24 = i_17;
                *edi_27 = 0x31;
                var_74c_6 = esi_38;

                if (i_24)
                {
                    int32_t ecx_61 = 0;
                    int32_t edi_28 = 0;

                    do
                    {
                        int32_t eax_164;
                        int32_t edx_47;
                        edx_47 = HIGHD(var_3a4[edi_28] * 0xa);
                        eax_164 = LOWD(var_3a4[edi_28] * 0xa);
                        var_3a4[edi_28] = eax_164 + ecx_61;
                        edi_28 += 1;
                        ecx_61 = edx_47 + 0;
                    } while (edi_28 != i_24);

                    esi_38 = var_74c_6;

                    if (ecx_61)
                    {
                        char* i_25 = i_17;

                        if (i_25 >= 0x73)
                        {
                            int32_t var_978_6 = 0;
                            i_17 = nullptr;
                            _memcpy_s(&var_3a4, 0x1cc, &var_974, nullptr);
                        }
                        else
                        {
                            var_3a4[i_25] = ecx_61;
                            i_17 = &i_17[1];
                        }
                    }
                }

                eax_167 = var_764_1;
            }
            else if (eax_162)
            {
                esi_38 = &edi_27[1];
                *edi_27 = eax_162 + 0x30;
                var_74c_6 = esi_38;
                eax_167 = var_764_1;
            }
            else
                eax_167 = var_764_1 - 1;

            arg4[1] = eax_167;
            void* ecx_63 = arg2 + 1;

            if (eax_167 >= 0 && ecx_63 <= 0x7fffffff && !arg3)
                ecx_63 += eax_167;

            if (arg6 - 1 < ecx_63)
                ecx_63 = arg6 - 1;

            uint8_t edx_49 = 0;
            void* ecx_64 = ecx_63 + arg5;
            uint8_t var_751_1 = 0;

            while (esi_38 != ecx_64)
            {
                char* i_26 = i_18;

                if (!i_26)
                    break;

                int32_t ecx_65 = 0;
                int32_t edi_29 = 0;

                do
                {
                    int32_t eax_172;
                    int32_t edx_50;
                    edx_50 = HIGHD((&var_1d4)[edi_29] * 0x3b9aca00);
                    eax_172 = LOWD((&var_1d4)[edi_29] * 0x3b9aca00);
                    (&var_1d4)[edi_29] = eax_172 + ecx_65;
                    edi_29 += 1;
                    ecx_65 = edx_50 + 0;
                } while (edi_29 != i_26);

                if (ecx_65)
                {
                    char* i_27 = i_18;

                    if (i_27 >= 0x73)
                    {
                        int32_t var_978_7 = 0;
                        i_18 = nullptr;
                        _memcpy_s(&var_1d4, 0x1cc, &var_974, nullptr);
                    }
                    else
                    {
                        (&var_1d4)[i_27] = ecx_65;
                        i_18 = &i_18[1];
                    }
                }

                uint32_t eax_174 = sub_4103d0(&i_18, &i_17);

                for (char* i_6 = 8; i_6 != 0xffffffff; i_6 -= 1)
                {
                    int32_t edx_52 = 0;
                    uint8_t temp1_5 = COMBINE(edx_52, eax_174) % var_780_4;
                    eax_174 = COMBINE(edx_52, eax_174) / var_780_4;

                    if (ecx_64 - var_74c_6 > i_6)
                    {
                        *(i_6 + var_74c_6) = temp1_5 + 0x30;
                        edx_49 = var_751_1;
                    }
                    else if (!temp1_5)
                        edx_49 = var_751_1;
                    else
                    {
                        edx_49 = 1;
                        var_751_1 = 1;
                    }
                }

                void* eax_176 = ecx_64 - var_74c_6;

                if (eax_176 > 9)
                    eax_176 = 9;

                esi_38 = var_74c_6 + eax_176;
                var_74c_6 = esi_38;
            }

            *esi_38 = 0;

            if (i_18 || edx_49)
                result = 0;

            sub_409550((&var_774 + 4), var_798, var_794_1);
        }
        else
        {
            arg4[1] = 1;

            if (eax_12 != 1)
            {
                if (eax_12 == 2)
                {
                    var_b58 = "1#QNAN";
                    goto label_4109c8;
                }

                if (eax_12 == 3)
                {
                    var_b58 = "1#SNAN";
                    goto label_4109c8;
                }

                if (eax_12 != 4)
                    goto label_410a0d;

                var_b58 = "1#IND";
                goto label_4109c8;
            }

            if (sub_409620(arg5, arg6, "1#INF"))
            {
            label_411d6e:
                int32_t var_b68_4;
                __builtin_memset(&var_b68_4, 0, 0x14);
                sub_40a6d6();
                /* no return */
            }

            result = 0;
        }
    }
    else
    {
        var_b58 = &data_419864;
        arg4[1] = 0;
    label_4109c8:

        if (sub_409620(arg5, arg6, var_b58))
            goto label_411d6e;
    }

    if (var_79c)
        sub_413710(&var_7a4);

    sub_402910(eax_1 ^ &__saved_ebp);
    return result;
}

int32_t sub_411d75(char* arg1, uint32_t arg2, int32_t* arg3, int32_t* arg4)
{
    uint32_t ecx;

    if (arg1)
    {
        ecx = arg2;

        if (ecx)
        {
            if (ecx & 0xffffff80)
            {
                char ebx_1;
                char* i_2;

                if (ecx & 0xfffff800)
                {
                    char* i_3;

                    if (ecx & 0xffff0000)
                    {
                        if (ecx & 0xffe00000 || ecx > 0x10ffff)
                            return __crt_mbstring::return_illegal_sequence(arg3, arg4);

                        i_3 = 3;
                        ebx_1 = 0xf0;
                    }
                    else
                    {
                        if (ecx >= 0xd800 && ecx <= 0xdfff)
                            return __crt_mbstring::return_illegal_sequence(arg3, arg4);

                        i_3 = 2;
                        ebx_1 = 0xe0;
                    }

                    i_2 = i_3;
                }
                else
                {
                    ebx_1 = 0xc0;
                    i_2 = 1;
                }

                int32_t edi;
                int32_t var_10_1 = edi;
                char* i_1 = i_2;
                char* i;

                do
                {
                    char eax_3 = ecx;
                    ecx u>>= 6;
                    *(i_1 + arg1) = (eax_3 & 0x3f) | 0x80;
                    i = i_1;
                    i_1 -= 1;
                } while (i != 1);
                *arg1 = ebx_1 | ecx;
                return sub_411e23(&i_2[1], arg3);
            }

            *arg1 = ecx;
        }
        else
        {
            *arg1 = ecx;
            *arg3 = ecx;
            arg3[1] = ecx;
        }
    }
    else
    {
        ecx = 0;
        *arg3 = ecx;
        arg3[1] = ecx;
    }
    return 1;
}

int32_t sub_411e23(int32_t arg1, int32_t* arg2)
{
    *arg2 = 0;
    arg2[1] = 0;
    return arg1;
}

int32_t __crt_mbstring::return_illegal_sequence(int32_t* arg1, void* arg2)
{
    *arg1 = 0;
    arg1[1] = 0;
    *(arg2 + 0x1c) = 1;
    *(arg2 + 0x18) = 0x2a;
    return 0xffffffff;
}

int32_t __fcloseall()
{
    int32_t __saved_ebp_1 = 0x10;
    int32_t var_8 = 0x41cea0;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41cea0 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_34 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_34;
    void* const var_38_4 = &data_411e65;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t result = 0;
    ___acrt_lock(8);
    int32_t var_8_1 = 0;
    int32_t var_38 = 3;
    int32_t esi = 3;

    while (true)
    {
        int32_t var_24_1 = esi;

        if (esi == data_41ecec)
            break;

        void* eax_1 = *(data_41ecf0 + (esi << 2));

        if (eax_1)
        {
            if (*(eax_1 + 0xc) >> 0xd & 1 && _fclose(*(data_41ecf0 + (esi << 2))) != 0xffffffff)
                result += 1;

            DeleteCriticalSection(*(data_41ecf0 + (esi << 2)) + 0x20);
            __free_base(*(data_41ecf0 + (esi << 2)));
            *(data_41ecf0 + (esi << 2)) = 0;
        }

        esi += 1;
    }

    int32_t var_8_2 = 0xfffffffe;
    $LN10();
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t $LN10()
{
    return ___acrt_unlock(8);
}

uint8_t ___acrt_stdio_free_buffer_nolock(int32_t* arg1)
{
    int32_t edi;
    int32_t var_c = edi;
    uint8_t result = arg1[3] >> 0xd;

    if (result & 1)
    {
        result = arg1[3] >> 6;

        if (result & 1)
        {
            __free_base(arg1[1]);
            arg1[3] &= 0xfffffebf;
            result = 0;
            arg1[1] = 0;
            *arg1 = 0;
            arg1[2] = 0;
        }
    }

    return result;
}

int32_t __isatty(int32_t arg1)
{
    if (arg1 != 0xfffffffe)
    {
        if (arg1 >= 0 && arg1 < data_41ef08)
            return *((&data_41ed08)[arg1 >> 6] + (arg1 & 0x3f) * 0x38 + 0x28) & 0x40;

        *sub_40a844() = 9;
        __invalid_parameter_noinfo();
    }
    else
        *sub_40a844() = 9;

    return 0;
}

int32_t sub_411f9a(void* arg1)
{
    int32_t edi;
    int32_t var_10 = edi;
    int32_t edi_1 = 0;
    int32_t ebx = 0xe3;

    do
    {
        int32_t eax_2;
        int32_t edx_1;
        edx_1 = HIGHD(ebx + edi_1);
        eax_2 = LOWD(ebx + edi_1);
        int32_t esi_2 = (eax_2 - edx_1) >> 1;
        uint32_t eax_4 = sub_412890(arg1, (&data_41a9a8)[esi_2 * 2], 0x55);

        if (!eax_4)
            return *((esi_2 << 3) + &data_41a9ac);

        int32_t ecx_1 = esi_2 - 1;

        if (eax_4 >= 0)
            ecx_1 = ebx;

        ebx = ecx_1;

        if (eax_4 >= 0)
            edi_1 = esi_2 + 1;
    } while (edi_1 <= ebx);

    return 0xffffffff;
}

int32_t ___acrt_DownlevelLocaleNameToLCID(void* arg1)
{
    if (arg1)
    {
        int32_t eax_1 = sub_411f9a(arg1);

        if (eax_1 >= 0 && eax_1 < 0xe4)
            return *((eax_1 << 3) + &data_419888);
    }

    return 0;
}

char* sub_412020(char* arg1, int32_t arg2, void* arg3, int32_t arg4)
{
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    char* result = arg1;
    char* result_2 = result;
    int32_t ebx = arg4;
    int32_t var_100 = ebx;
    void* i_12 = arg3;
    void* i_15 = i_12;
    int32_t edi;
    int32_t var_128 = edi;

    if (result)
    {
        if (i_12 && ebx)
            goto label_412089;

        *sub_40a844() = 0x16;
        result = __invalid_parameter_noinfo();
    }
    else if (!arg2 && i_12 && ebx)
    {
    label_412089:
        sub_409788();
        char* result_1 = nullptr;

        if (arg2 >= 2)
        {
            char* result_5 = result_2;
            char* i_5 = (arg2 - 1) * i_12 + result_5;

            while (true)
            {
            label_4120ab:
                char* i_7 = i_5;
                int32_t var_f8[0x1e];
                int32_t var_80[0x1e];

                while (true)
                {
                    if (COMBINE(0, i_5 - result_5) / i_12 + 1 > 8)
                    {
                        int32_t eax_10 = ((COMBINE(0, i_5 - result_5) / i_12 + 1) >> 1) * i_12;
                        char* result_10 = &result_5[eax_10];
                        char* result_3 = result_2;

                        if (ebx(result_2, result_10) > 0)
                        {
                            char* result_12 = result_10;

                            if (result_3 != result_10)
                            {
                                void* i_14 = i_12;
                                void* i;

                                do
                                {
                                    char* edx_4 = result_12 - eax_10;
                                    char ecx_7 = *edx_4;
                                    *edx_4 = *result_12;
                                    *result_12 = ecx_7;
                                    result_12 = &result_12[1];
                                    i = i_14;
                                    i_14 -= 1;
                                } while (i != 1);
                                i_12 = i_15;
                                result_3 = result_2;
                            }
                        }

                        char* i_19 = i_7;

                        if (var_100(result_3, i_19) > 0)
                        {
                            char* i_22 = i_19;

                            if (result_2 != i_19)
                            {
                                void* eax_15 = result_2 - i_19;
                                void* var_114_2 = eax_15;
                                void* i_1;

                                do
                                {
                                    char eax_16 = *i_22;
                                    i_22 = &i_22[1];
                                    char ecx_8 = *(eax_15 + i_22 - 1);
                                    *(eax_15 + i_22 - 1) = eax_16;
                                    i_22[0xffffffff] = ecx_8;
                                    i_1 = i_12;
                                    i_12 -= 1;
                                } while (i_1 != 1);
                                i_19 = i_7;
                            }
                        }

                        void* i_18 = i_15;

                        if (var_100(result_10, i_19) > 0)
                        {
                            void* i_13 = i_18;
                            char* i_23 = i_19;

                            if (result_10 != i_19)
                            {
                                int32_t eax_19 = result_10 - i_19;
                                int32_t var_114_3 = eax_19;
                                void* i_2;

                                do
                                {
                                    char eax_20 = *i_23;
                                    i_23 = &i_23[1];
                                    char ecx_9 = i_23[eax_19 - 1];
                                    i_23[eax_19 - 1] = eax_20;
                                    i_23[0xffffffff] = ecx_9;
                                    i_2 = i_13;
                                    i_13 -= 1;
                                } while (i_2 != 1);
                                i_18 = i_15;
                                i_19 = i_7;
                            }
                        }

                        char* result_4 = result_2;
                        char* i_21 = i_19;
                        char* result_6;
                        char* i_16;

                        while (true)
                        {
                            if (result_10 > result_4)
                            {
                                while (true)
                                {
                                    result_4 += i_18;
                                    result_6 = result_4;

                                    if (result_4 >= result_10)
                                        break;

                                    i_18 = i_15;

                                    if (var_100(result_4, result_10) > 0)
                                        goto label_4122d0;
                                }
                            }

                            int32_t i_3;

                            do
                            {
                                result_4 += i_18;

                                if (result_4 > i_7)
                                    break;

                                i_3 = var_100(result_4, result_10);
                                i_18 = i_15;
                            } while (i_3 <= 0);
                            i_19 = i_21;
                            result_6 = result_4;
                        label_4122d0:

                            while (true)
                            {
                                i_18 = i_15;
                                i_16 = i_19;
                                i_19 -= i_18;

                                if (i_19 <= result_10)
                                    break;

                                if (var_100(i_19, result_10) <= 0)
                                {
                                    i_18 = i_15;
                                    break;
                                }
                            }

                            result_4 = result_6;
                            i_21 = i_19;

                            if (i_19 < result_4)
                                break;

                            void* i_20 = i_18;
                            char* i_24 = i_19;

                            if (i_19 != result_4)
                            {
                                void* esi_2 = result_4 - i_19;
                                void* i_11 = i_18;
                                void* i_4;

                                do
                                {
                                    char eax_23 = *i_24;
                                    i_24 = &i_24[1];
                                    char ecx_10 = *(esi_2 + i_24 - 1);
                                    *(esi_2 + i_24 - 1) = eax_23;
                                    i_24[0xffffffff] = ecx_10;
                                    i_4 = i_11;
                                    i_11 -= 1;
                                } while (i_4 != 1);
                                result_4 = result_6;
                                i_19 = i_21;
                                i_18 = i_15;
                            }

                            char* result_7 = result_4;

                            if (result_10 != i_19)
                                result_7 = result_10;

                            result_10 = result_7;
                        }

                        char* i_8;

                        if (result_10 < i_16)
                        {
                            while (true)
                            {
                                i_16 -= i_18;
                                i_8 = i_16;

                                if (i_16 <= result_10)
                                    break;

                                i_18 = i_15;
                                bool cond:5_1 = !var_100(i_16, result_10);
                                i_16 = i_8;

                                if (!cond:5_1)
                                    goto label_4123cd;
                            }
                        }

                        bool cond:4_1;

                        do
                        {
                            char* i_17 = i_16 - i_18;
                            i_8 = i_17;

                            if (i_17 <= result_2)
                                break;

                            i_18 = i_15;
                            cond:4_1 = !var_100(i_17, result_10);
                            i_16 = i_8;
                        } while (cond:4_1);
                        result_4 = result_6;
                    label_4123cd:
                        result_5 = result_2;

                        if (i_8 - result_5 < i_7 - result_4)
                        {
                            if (result_4 < i_7)
                            {
                                var_80[result_1] = result_4;
                                var_f8[result_1] = i_7;
                                result_1 = &result_1[1];
                            }

                            i_12 = i_15;

                            if (result_5 < i_8)
                            {
                                ebx = var_100;
                                i_5 = i_8;
                                goto label_4120ab;
                            }
                        }
                        else
                        {
                            if (result_5 < i_8)
                            {
                                var_80[result_1] = result_5;
                                var_f8[result_1] = i_8;
                                result_1 = &result_1[1];
                            }

                            i_5 = i_7;
                            ebx = var_100;

                            if (result_4 >= i_5)
                            {
                                i_12 = i_15;
                                break;
                            }

                            result_5 = result_4;
                            i_12 = i_15;
                            result_2 = result_5;
                            continue;
                        }
                    }
                    else
                    {
                        if (i_5 <= result_5)
                            break;

                        char* result_11 = i_12 + result_5;
                        char* result_13 = result_11;

                        do
                        {
                            for (char* result_9 = result_11; result_9 <= i_5; i_5 = i_7)
                            {
                                char* result_8 = result_9;

                                if (var_100(result_9, result_5) <= 0)
                                    result_8 = result_5;

                                result_9 += i_12;
                                result_5 = result_8;
                            }

                            void* i_10 = i_12;
                            char* i_9 = i_5;

                            if (result_5 != i_5)
                            {
                                void* edi_3 = result_5 - i_5;
                                void* i_6;

                                do
                                {
                                    char eax_7 = *i_9;
                                    i_9 = &i_9[1];
                                    char ecx_6 = *(edi_3 + i_9 - 1);
                                    *(edi_3 + i_9 - 1) = eax_7;
                                    i_9[0xffffffff] = ecx_6;
                                    i_6 = i_10;
                                    i_10 -= 1;
                                } while (i_6 != 1);
                                i_5 = i_7;
                            }

                            result_5 = result_2;
                            i_5 -= i_12;
                            result_11 = result_13;
                            i_7 = i_5;
                        } while (i_5 > result_5);
                    }

                    ebx = var_100;
                    break;
                }

                result = result_1 - 1;
                bool cond:1_1 = result_1 - 1 < 0;
                result_1 = result;

                if (cond:1_1)
                    break;

                result_5 = var_80[result];
                i_5 = var_f8[result];
                result_2 = result_5;
            }
        }
    }
    else
    {
        *sub_40a844() = 0x16;
        result = __invalid_parameter_noinfo();
    }

    sub_402910(eax_1 ^ &__saved_ebp);
    return result;
}

int32_t sub_412460(char* arg1, int32_t arg2, int32_t arg3, int32_t arg4)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    int32_t edi;
    int32_t var_10 = edi;

    if (!arg4)
    {
        if (arg1)
            goto label_412488;

        if (arg2 == arg4)
            return arg4;
    }
    else if (arg1)
    {
    label_412488:
        int32_t i_2 = arg2;

        if (i_2)
        {
            if (!arg4)
            {
                *arg1 = arg4;
                return arg4;
            }

            if (arg3)
            {
                char* edi_5 = arg3 - arg1;
                char* ecx_1 = arg1;
                int32_t i_3 = arg4;

                if (arg4 != 0xffffffff)
                {
                    int32_t i_4;
                    int32_t i;

                    do
                    {
                        char eax_4 = *(edi_5 + ecx_1);
                        ecx_1 = &ecx_1[1];
                        ecx_1[0xffffffff] = eax_4;
                        i_4 = i_3;

                        if (!eax_4)
                            return 0;

                        int32_t i_5 = i_2;
                        i_2 -= 1;

                        if (i_5 == 1)
                            break;

                        i = i_3;
                        i_3 -= 1;
                    } while (i != 1);
                    int32_t i_6 = i_4 - 1;

                    if (!i_2)
                        i_6 = i_4;

                    if (!i_6)
                        *ecx_1 = i_6;
                }
                else
                {
                    int32_t i_1;

                    do
                    {
                        char eax_3 = *(edi_5 + ecx_1);
                        ecx_1 = &ecx_1[1];
                        ecx_1[0xffffffff] = eax_3;

                        if (!eax_3)
                            return 0;

                        i_1 = i_2;
                        i_2 -= 1;
                    } while (i_1 != 1);
                }

                if (i_2)
                    return 0;

                if (arg4 == 0xffffffff)
                {
                    arg1[arg2 - 1] = i_2;
                    return i_2 + 0x50;
                }

                *arg1 = 0;
                *sub_40a844() = 0x22;
                __invalid_parameter_noinfo();
                return 0x22;
            }

            *arg1 = 0;
        }
    }

    *sub_40a844() = 0x16;
    __invalid_parameter_noinfo();
    return 0x16;
}

void* _strpbrk(char* arg1, char* arg2)
{
    void* result = nullptr;
    int32_t var_28_1;
    __builtin_memset(&var_28_1, 0, 0x20);
    char* edx = arg2;

    while (true)
    {
        result = *edx;
        result = result;

        if (!result)
            break;

        edx = &edx[1];
        var_28_1 |= 1 << (result % 0x20);
    }

    char* esi = arg1;

    do
    {
        result = *esi;
        result = result;

        if (!result)
            return result;

        esi = &esi[1];
    } while (!TEST_BITD(var_28_1, result));

    return &esi[0xffffffff];
}

char* __mbsdec(int32_t arg1, void* arg2)
{
    return __mbsdec_l(arg1, arg2, nullptr);
}

char* __mbsdec_l(int32_t arg1, void* arg2, int32_t* arg3)
{
    if (!arg1)
    {
        *sub_40a844() = 0x16;
        __invalid_parameter_noinfo();
        return 0;
    }

    if (!arg2)
    {
        *sub_40a844() = 0x16;
        __invalid_parameter_noinfo();
    }
    else if (arg1 < arg2)
    {
        void* var_14;
        _LocaleUpdate::_LocaleUpdate(&var_14, arg3);
        char* result = arg2 - 1;
        void* var_c;

        if (*(var_c + 8))
        {
            do
            {
                result -= 1;

                if (arg1 > result)
                    break;
            } while (*(*result + var_c + 0x19) & 4);

            result = arg2 - ((arg2 - result) & 1) - 1;
        }

        char var_8;

        if (var_8)
        {
            void* ecx_3 = var_14;
            *(ecx_3 + 0x350) &= 0xfffffffd;
        }

        return result;
    }

    return nullptr;
}

int32_t sub_412644(int32_t* arg1, void* arg2, uint32_t arg3, uint8_t* arg4, char* arg5, PWSTR arg6, int32_t arg7, uint32_t arg8, int32_t arg9)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    int32_t var_c = ecx;
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    int32_t edi;
    int32_t var_18 = edi;
    char* edi_1 = arg5;

    if (edi_1 > 0)
    {
        char* eax_2 = sub_413dc0(arg4, edi_1);
        bool cond:0_1 = eax_2 < edi_1;
        edi_1 = &eax_2[1];

        if (!cond:0_1)
            edi_1 = eax_2;
    }

    uint32_t ebx = arg8;

    if (!ebx)
    {
        ebx = *(*arg1 + 8);
        arg8 = ebx;
    }

    int32_t eax_5 = 1;

    if (arg9)
        eax_5 = 9;

    int32_t result = ___acrt_MultiByteToWideChar(ebx, eax_5, arg4, edi_1, nullptr, 0);

    if (result)
    {
        int32_t eax_6 = result * 2;
        uint32_t eax_8 = (eax_6 - eax_6) & (eax_6 + 8);
        int32_t result_1;
        int32_t* esi_1;

        if (!eax_8)
        {
            esi_1 = nullptr;
            result_1 = 0;
        }
        else if (eax_8 > 0x400)
        {
            esi_1 = sub_40a8b0(eax_8);

            if (!esi_1)
                result_1 = 0;
            else
            {
                *esi_1 = 0xdddd;
            label_4126f5:
                esi_1 = &esi_1[2];

                if (!esi_1)
                    result_1 = 0;
                else if (!___acrt_MultiByteToWideChar(ebx, 1, arg4, edi_1, esi_1, result))
                    result_1 = 0;
                else
                {
                    result_1 =
                        ___acrt_LCMapStringEx@36(arg2, arg3, esi_1, result, nullptr, 0, 0, 0, 0);

                    if (!result_1)
                        result_1 = 0;
                    else if (!(arg3 & 0x400))
                    {
                        int32_t eax_14 = result_1 * 2;
                        uint32_t eax_16 = (eax_14 - eax_14) & (eax_14 + 8);

                        if (!eax_16)
                        {
                            __freea_crt(nullptr);
                            result_1 = 0;
                        }
                        else
                        {
                            int32_t* edi_3;

                            if (eax_16 > 0x400)
                            {
                                edi_3 = sub_40a8b0(eax_16);

                                if (!edi_3)
                                {
                                    __freea_crt(edi_3);
                                    result_1 = 0;
                                }
                                else
                                {
                                    *edi_3 = 0xdddd;
                                label_4127b6:
                                    edi_3 = &edi_3[2];

                                    if (!edi_3)
                                    {
                                        __freea_crt(edi_3);
                                        result_1 = 0;
                                    }
                                    else if (!___acrt_LCMapStringEx@36(arg2, arg3, esi_1, result,
                                        edi_3, result_1, 0, 0, 0))
                                    {
                                        __freea_crt(edi_3);
                                        result_1 = 0;
                                    }
                                    else
                                    {
                                        PSTR var_28_4;
                                        int32_t var_24_2;

                                        if (arg7)
                                        {
                                            var_24_2 = arg7;
                                            var_28_4 = arg6;
                                        }
                                        else
                                        {
                                            var_24_2 = 0;
                                            var_28_4 = nullptr;
                                        }

                                        result_1 = sub_40e427(arg8, 0, edi_3, result_1, var_28_4,
                                            var_24_2, nullptr, nullptr);

                                        if (!result_1)
                                        {
                                            __freea_crt(edi_3);
                                            result_1 = 0;
                                        }
                                        else
                                            __freea_crt(edi_3);
                                    }
                                }
                            }
                            else
                            {
                                __alloca_probe_16(eax_16);
                                edi_3 = &var_18;

                                if (&var_18)
                                {
                                    var_18 = 0xcccc;
                                    goto label_4127b6;
                                }

                                __freea_crt(edi_3);
                                result_1 = 0;
                            }
                        }
                    }
                    else if (arg7)
                    {
                        if (result_1 > arg7)
                            result_1 = 0;
                        else
                        {
                            result_1 = ___acrt_LCMapStringEx@36(arg2, arg3, esi_1, result, arg6,
                                arg7, 0, 0, 0);

                            if (!result_1)
                                result_1 = 0;
                        }
                    }
                }
            }
        }
        else
        {
            __alloca_probe_16(eax_8);
            esi_1 = &var_18;

            if (&var_18)
            {
                var_18 = 0xcccc;
                goto label_4126f5;
            }

            result_1 = 0;
        }

        __freea_crt(esi_1);
        result = result_1;
    }

    sub_402910(eax_1 ^ &__saved_ebp);
    return result;
}

int32_t ___acrt_LCMapStringA(int32_t* arg1, void* arg2, uint32_t arg3, uint8_t* arg4, char* arg5, PWSTR arg6, int32_t arg7, uint32_t arg8, int32_t arg9)
{
    void* var_14;
    _LocaleUpdate::_LocaleUpdate(&var_14, arg1);
    void var_10;
    int32_t result = sub_412644(&var_10, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    char var_8;

    if (var_8)
    {
        void* ecx_1 = var_14;
        *(ecx_1 + 0x350) &= 0xfffffffd;
    }

    return result;
}

int32_t sub_41287a()
{
    return ___acrt_initialize_multibyte() ^ 1;
}

uint32_t sub_412890(void* arg1, int16_t* arg2, int32_t arg3)
{
    int32_t edi;
    int32_t var_8 = edi;
    int32_t i_1 = arg3;

    if (!i_1)
        return 0;

    void* ebx = arg1;
    uint32_t ecx_1;
    uint32_t esi_1;
    int32_t i;

    do
    {
        ebx += 2;
        ecx_1 = *(ebx - 2);
        esi_1 = *arg2;
        arg2 = &arg2[1];

        if (ecx_1 != esi_1)
        {
            uint32_t edx_1 = ecx_1 + 0x20;

            if (ecx_1 - 0x41 > 0x19)
                edx_1 = ecx_1;

            ecx_1 = edx_1;
            uint32_t edx_2 = esi_1 + 0x20;

            if (esi_1 - 0x41 > 0x19)
                edx_2 = esi_1;

            esi_1 = edx_2;
        }

        if (ecx_1 != esi_1)
            break;

        if (!ecx_1)
            break;

        i = i_1;
        i_1 -= 1;
    } while (i != 1);
    return ecx_1 - esi_1;
}

uint32_t sub_412900(int32_t arg1)
{
    if (arg1)
        return HeapSize(data_41f110, HEAP_NONE, arg1);

    *sub_40a844() = 0x16;
    __invalid_parameter_noinfo();
    return 0xffffffff;
}

int32_t sub_412940()
{
    /* tailcall */
    return sub_412900();
}

int32_t __realloc_base(int32_t arg1, uint32_t arg2)
{
    int32_t edi;
    int32_t var_8 = edi;

    if (!arg1)
        return sub_40a8b0(arg2);

    if (arg2)
    {
        if (arg2 <= 0xffffffe0)
        {
            int32_t i;

            do
            {
                int32_t result = HeapReAlloc(data_41f110, HEAP_NONE, arg1, arg2);

                if (result)
                    return result;

                if (!sub_409070())
                    break;

                i = __callnewh(arg2);
            } while (i);
        }

        *sub_40a844() = 0xc;
    }
    else
        __free_base(arg1);

    return 0;
}

int32_t __stdcall __crt_seh_guarded_call<int32_t>::operator()<class <lambda_9e9de3de5fa147e2223d7db92bc10aa6>,class <lambda_38ce7e780aa69e748d6df282ebc68efe>&,class <lambda_8ca6da459f0f6780f1cff60fdc3d00e5> >(int32_t* arg1, int32_t* arg2)
{
    int32_t __saved_ebp_1 = 0xc;
    int32_t var_8 = 0x41cec0;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41cec0 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_3 = &data_4129c5;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t result = 0;
    int32_t var_20 = 0;
    ___acrt_lowio_lock_fh(*arg1);
    int32_t var_8_1 = 0;
    int32_t edi = **arg2;

    if (!(*((&data_41ed08)[edi >> 6] + (edi & 0x3f) * 0x38 + 0x28) & 1))
    {
        *sub_40a844() = 9;
        result = 0xffffffff;
    }
    else if (!FlushFileBuffers(__get_osfhandle(edi)))
    {
        *sub_40a82f() = GetLastError();
        *sub_40a844() = 9;
        result = 0xffffffff;
    }

    int32_t result_1 = result;
    int32_t var_8_2 = 0xfffffffe;
    $LN7(&__saved_ebp);
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t $LN7(void* arg1 @ ebp)
{
    return ___acrt_lowio_unlock_fh(**(arg1 + 0x10));
}

int32_t __commit(int32_t arg1)
{
    int32_t esi = arg1;

    if (esi != 0xfffffffe)
    {
        if (esi >= 0 && esi < data_41ef08
            && *((&data_41ed08)[esi >> 6] + (esi & 0x3f) * 0x38 + 0x28) & 1)
        {
            int32_t var_c = esi;
            int32_t* var_10 = &arg1;
            int32_t var_14 = esi;
            int32_t* var_1c_1 = &var_c;
            return __crt_seh_guarded_call<int32_t>::operator()<class <lambda_9e9de3de5fa147e2223d7db92bc10aa6>,class <lambda_38ce7e780aa69e748d6df282ebc68efe>&,class <lambda_8ca6da459f0f6780f1cff60fdc3d00e5> >(
                &var_14, &var_10);
        }

        *sub_40a844() = 9;
        __invalid_parameter_noinfo();
    }
    else
        *sub_40a844() = 9;

    return 0xffffffff;
}

int32_t* sub_412ad8(int32_t* arg1, int32_t arg2, char* arg3, void* arg4, enum WIN32_ERROR arg5)
{
    int32_t var_8 = 0xffffffff;
    int32_t (* var_c)(void* arg1 @ 0x8) = sub_415725;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t __saved_ebp;
    int32_t eax_2 = __security_cookie ^ &__saved_ebp;
    int32_t edi;
    int32_t var_8c = edi;
    int32_t var_90 = eax_2;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t ecx = (arg2 & 0x3f) * 0x38;
    int32_t edx_1 = arg2 >> 6;
    HANDLE hFile = *(ecx + (&data_41ed08)[edx_1] + 0x18);
    void* eax_7 = arg4 + arg3;
    uint32_t eax_8 = GetConsoleOutputCP();

    if (!*(arg5 + 0x14))
        __crt_cached_ptd_host::update_locale_slow(arg5);

    int32_t* result = arg1;
    int32_t ecx_2 = *(*(arg5 + 0xc) + 8);
    *result = 0;
    int32_t* edi_2 = &result[1];
    int32_t var_78 = ecx_2;
    *edi_2 = 0;
    edi_2[1] = 0;
    char* nNumberOfBytesToWrite_4 = arg3;
    char* nNumberOfBytesToWrite_6 = nNumberOfBytesToWrite_4;

    if (arg3 < eax_7)
    {
        int32_t edi_5 = ecx;
        char* ebx_1 = nullptr;
        char* var_58_1 = nullptr;

        while (true)
        {
            char eax_11 = *nNumberOfBytesToWrite_4;
            int32_t eax_12 = edx_1;
            int32_t var_44 = 0;
            int32_t var_38_1 = 1;
            char* nNumberOfBytesToWrite_1;
            char* nNumberOfBytesToWrite_3;

            if (ecx_2 != 0xfde9)
            {
                int32_t ecx_7 = (&data_41ed08)[eax_12];
                *(&eax_12 + 1) = *(ecx_7 + edi_5 + 0x2d);
                char* nNumberOfBytesToWrite_5;
                void* var_98_4;
                enum WIN32_ERROR var_94_4;

                if (!(*(&eax_12 + 1) & 4))
                {
                    if (*(**(arg5 + 0xc) + (*nNumberOfBytesToWrite_4 << 1)) >= 0)
                    {
                        var_94_4 = arg5;
                        var_98_4 = 1;
                        nNumberOfBytesToWrite_5 = nNumberOfBytesToWrite_4;
                        goto label_412d46;
                    }

                    nNumberOfBytesToWrite_1 = &nNumberOfBytesToWrite_4[1];

                    if (&nNumberOfBytesToWrite_4[1] >= eax_7)
                    {
                        *(ecx_7 + edi_5 + 0x2e) = *nNumberOfBytesToWrite_4;
                        int32_t eax_52 = (&data_41ed08)[edx_1];
                        *(eax_52 + edi_5 + 0x2d) |= 4;
                        result[1] = &var_58_1[1];
                        break;
                    }

                    if (sub_40b994(&var_44, nNumberOfBytesToWrite_4, 2, arg5) == 0xffffffff)
                        break;

                    nNumberOfBytesToWrite_3 = nNumberOfBytesToWrite_1;
                }
                else
                {
                    eax_12 = *(ecx_7 + edi_5 + 0x2e);
                    *(&eax_12 + 1) &= 0xfb;
                    var_94_4 = arg5;
                    char var_24 = eax_12;
                    eax_12 = *nNumberOfBytesToWrite_4;
                    char var_23_1 = eax_12;
                    *(ecx_7 + edi_5 + 0x2d) = *(&eax_12 + 1);
                    var_98_4 = 2;
                    nNumberOfBytesToWrite_5 = &var_24;
                label_412d46:

                    if (sub_40b994(&var_44, nNumberOfBytesToWrite_5, var_98_4, var_94_4)
                            == 0xffffffff)
                        break;

                    nNumberOfBytesToWrite_3 = nNumberOfBytesToWrite_6;
                }
            }
            else
            {
                int32_t ecx_3 = 0;
                char* eax_15 = (&data_41ed08)[eax_12] + 0x2e + edi_5;
                char* var_58_2 = eax_15;

                while (*eax_15)
                {
                    ecx_3 += 1;
                    eax_15 = &eax_15[1];

                    if (ecx_3 >= 5)
                        break;
                }

                void* edi_7 = eax_7 - nNumberOfBytesToWrite_4;
                void* var_4c_1;

                if (ecx_3 <= 0)
                {
                    void* eax_30 = *(*nNumberOfBytesToWrite_4 + 0x41e8e0) + 1;
                    var_4c_1 = eax_30;

                    if (eax_30 > edi_7)
                    {
                        if (edi_7 <= 0)
                        {
                            result[1] += edi_7;
                            break;
                        }

                        do
                        {
                            ebx_1[(&data_41ed08)[edx_1] + ecx + 0x2e] =
                                *(ebx_1 + nNumberOfBytesToWrite_4);
                            ebx_1 = &ebx_1[1];
                        } while (ebx_1 < edi_7);

                    label_412e30:
                        result = arg1;
                        result[1] += edi_7;
                        break;
                    }

                    int32_t ecx_5 = 0;
                    nNumberOfBytesToWrite_1 = nNumberOfBytesToWrite_4;
                    int64_t var_5c = 0;
                    ecx_5 = eax_30 == 4;
                    var_38_1 = ecx_5 + 1;

                    if (sub_40bdd8(&var_44, nNumberOfBytesToWrite_4, ecx_5 + 1, &var_44,
                            &nNumberOfBytesToWrite_1, ecx_5 + 1, &var_5c, arg5) == 0xffffffff)
                        break;

                    edi_5 = ecx;
                }
                else
                {
                    char* nNumberOfBytesToWrite_2 = *(*var_58_2 + 0x41e8e0) + 1;
                    nNumberOfBytesToWrite_1 = nNumberOfBytesToWrite_2;
                    void* eax_19 = nNumberOfBytesToWrite_2 - ecx_3;
                    var_4c_1 = eax_19;

                    if (eax_19 > edi_7)
                    {
                        if (edi_7 <= 0)
                        {
                            result[1] += edi_7;
                            break;
                        }

                        do
                        {
                            char ecx_10 = *(ebx_1 + nNumberOfBytesToWrite_6);
                            void* edx_5 = (&data_41ed08)[edx_1] + ecx + ebx_1;
                            ebx_1 = &ebx_1[1];
                            *(edx_5 + ecx_3 + 0x2e) = ecx_10;
                        } while (ebx_1 < edi_7);

                        goto label_412e30;
                    }

                    int32_t edi_8 = 0;
                    char* ebx_2 = var_58_2;
                    char var_1c[0x8];

                    do
                    {
                        var_1c[edi_8] = *ebx_2;
                        edi_8 += 1;
                        ebx_2 = &ebx_2[1];
                    } while (edi_8 < ecx_3);

                    ebx_1 = nullptr;

                    if (var_4c_1 > 0)
                        sub_4035c0(&var_1c[ecx_3], nNumberOfBytesToWrite_4, var_4c_1);

                    edi_5 = ecx;
                    int32_t edx_2 = 0;

                    do
                    {
                        *((&data_41ed08)[edx_1] + edi_5 + edx_2 + 0x2e) = 0;
                        edx_2 += 1;
                    } while (edx_2 < ecx_3);

                    result = arg1;
                    char (* var_70)[0x8] = &var_1c;
                    int32_t eax_24 = 0;
                    eax_24 = nNumberOfBytesToWrite_1 == 4;
                    int64_t var_80 = 0;
                    var_38_1 = eax_24 + 1;

                    if (sub_40bdd8(&var_44, edx_2, &var_80, &var_44, &var_70, eax_24 + 1, &var_80,
                            arg5) == 0xffffffff)
                        break;
                }

                nNumberOfBytesToWrite_3 = nNumberOfBytesToWrite_6 + var_4c_1 - 1;
            }

            nNumberOfBytesToWrite_6 = &nNumberOfBytesToWrite_3[1];
            void buffer_1;
            int32_t nNumberOfBytesToWrite =
                sub_40e427(eax_8, 0, &var_44, var_38_1, &buffer_1, 5, nullptr, nullptr);
            nNumberOfBytesToWrite_1 = nNumberOfBytesToWrite;

            if (!nNumberOfBytesToWrite)
                break;

            uint32_t numberOfBytesWritten;

            if (WriteFile(hFile, &buffer_1, nNumberOfBytesToWrite, &numberOfBytesWritten, nullptr))
            {
                nNumberOfBytesToWrite_4 = nNumberOfBytesToWrite_6;
                char* eax_45 = result[2] - arg3 + nNumberOfBytesToWrite_4;
                var_58_1 = eax_45;
                result[1] = eax_45;

                if (numberOfBytesWritten < nNumberOfBytesToWrite_1)
                    break;

                if (eax_11 != 0xa)
                {
                label_412dfe:

                    if (nNumberOfBytesToWrite_4 >= eax_7)
                        break;

                    ecx_2 = var_78;
                    continue;
                }
                else
                {
                    int16_t buffer = 0xd;

                    if (WriteFile(hFile, &buffer, 1, &numberOfBytesWritten, nullptr))
                    {
                        if (numberOfBytesWritten < 1)
                            break;

                        result[2] += 1;
                        result[1] += 1;
                        nNumberOfBytesToWrite_4 = nNumberOfBytesToWrite_6;
                        var_58_1 = result[1];
                        goto label_412dfe;
                    }
                }
            }

            *result = GetLastError();
            break;
        }
    }

    fsbase->NtTib.ExceptionList = ExceptionList;
    sub_402910(eax_2 ^ &__saved_ebp);
    return result;
}

int32_t* write_double_translated_unicode_nolock(int32_t* arg1, int16_t* arg2, void* arg3)
{
    uint32_t ecx;
    uint32_t var_8 = ecx;
    int32_t edi;
    int32_t var_14 = edi;
    *arg1 = 0;
    int32_t* edi_2 = &arg1[1];
    *edi_2 = 0;
    edi_2[1] = 0;
    int16_t* edi_5 = arg2;
    void* eax_1 = arg3 + edi_5;

    if (edi_5 < eax_1)
    {
        while (true)
        {
            uint32_t ebx_1 = *edi_5;
            int16_t eax_2 = __putwch_nolock(ecx);
            ecx = ebx_1;

            if (eax_2 == ebx_1)
            {
                arg1[1] += 2;

                if (ebx_1 != 0xa)
                    goto label_412ef2;

                int16_t eax_3 = __putwch_nolock(ecx);
                ecx = 0xd;

                if (eax_3 == 0xd)
                {
                    arg1[1] += 1;
                    arg1[2] += 1;
                label_412ef2:
                    edi_5 = &edi_5[1];

                    if (edi_5 >= eax_1)
                        break;

                    continue;
                }
            }

            *arg1 = GetLastError();
            break;
        }
    }

    return arg1;
}

BOOL __convention("regparm") write_requires_double_translation_nolock(int32_t arg1, int32_t arg2, enum CONSOLE_MODE arg3, int32_t arg4, enum WIN32_ERROR arg5)
{
    enum CONSOLE_MODE mode = arg3;
    int32_t edi;
    int32_t var_14 = edi;
    BOOL result = __isatty(arg4);

    if (!result)
        result = 0;
    else
    {
        int32_t edi_2 = arg4 >> 6;
        int32_t ebx_1 = (arg4 & 0x3f) * 0x38;
        result = (&data_41ed08)[edi_2];

        if (*(result + ebx_1 + 0x28) >= 0)
            result = 0;
        else
        {
            if (!*(arg5 + 0x14))
                __crt_cached_ptd_host::update_locale_slow(arg5);

            if (!*(*(arg5 + 0xc) + 0xa8))
                result = (&data_41ed08)[edi_2];

            if (!*(*(arg5 + 0xc) + 0xa8) && !*(result + ebx_1 + 0x29))
                result = 0;
            else
            {
                result = GetConsoleMode(*((&data_41ed08)[edi_2] + ebx_1 + 0x18), &mode);
                result = result;
            }
        }
    }

    return result;
}

int32_t* write_text_ansi_nolock(int32_t* arg1, int32_t arg2, char* arg3, void* arg4)
{
    sub_415440(0x140c);
    int32_t __saved_ebp;
    int32_t var_8 = __security_cookie ^ &__saved_ebp;
    int32_t edi;
    int32_t var_10 = edi;
    char* ecx_3 = arg3;
    void* edx_1 = arg4 + ecx_3;
    uint32_t numberOfBytesWritten = *((&data_41ed08)[arg2 >> 6] + (arg2 & 0x3f) * 0x38 + 0x18);
    *arg1 = 0;
    int32_t* edi_2 = &arg1[1];
    void* var_1410 = edx_1;
    *edi_2 = 0;
    edi_2[1] = 0;

    if (ecx_3 < edx_1)
    {
        uint32_t hFile = numberOfBytesWritten;

        do
        {
            uint8_t buffer[0x13e4];
            uint8_t (* esi_1)[0x13e4] = &buffer;

            while (ecx_3 < edx_1)
            {
                char eax_6 = *ecx_3;
                ecx_3 = &ecx_3[1];

                if (eax_6 == 0xa)
                {
                    arg1[2] += 1;
                    *esi_1 = 0xd;
                    esi_1 = &(*esi_1)[1];
                }

                *esi_1 = eax_6;
                esi_1 = &(*esi_1)[1];
                int32_t __saved_esi;

                if (esi_1 >= (&__saved_esi + 3))
                    break;
            }

            uint32_t nNumberOfBytesToWrite = esi_1 - &buffer;

            if (!WriteFile(hFile, &buffer, nNumberOfBytesToWrite, &numberOfBytesWritten, nullptr))
            {
                *arg1 = GetLastError();
                break;
            }

            void* numberOfBytesWritten_1 = numberOfBytesWritten;
            arg1[1] += numberOfBytesWritten_1;

            if (numberOfBytesWritten_1 < nNumberOfBytesToWrite)
                break;

            edx_1 = var_1410;
        } while (ecx_3 < edx_1);
    }

    int32_t entry_ebx;
    sub_402910(entry_ebx ^ &__saved_ebp);
    return arg1;
}

int32_t* write_text_utf16le_nolock(int32_t* arg1, int32_t arg2, int16_t* arg3, void* arg4)
{
    sub_415440(0x1410);
    int32_t __saved_ebp;
    int32_t var_8 = __security_cookie ^ &__saved_ebp;
    int32_t edi;
    int32_t var_10 = edi;
    HANDLE hFile = *((&data_41ed08)[arg2 >> 6] + (arg2 & 0x3f) * 0x38 + 0x18);
    int16_t* ecx_3 = arg3;
    void* i = arg4 + ecx_3;
    *arg1 = 0;
    int32_t* edi_2 = &arg1[1];
    void* i_1 = i;
    *edi_2 = 0;
    edi_2[1] = 0;

    for (; ecx_3 < i; i = i_1)
    {
        uint8_t buffer[0x13e4];
        uint8_t (* esi_1)[0x13e4] = &buffer;

        while (ecx_3 < i)
        {
            uint32_t eax_5 = *ecx_3;
            ecx_3 = &ecx_3[1];

            if (eax_5 == 0xa)
            {
                arg1[2] += 2;
                *esi_1 = 0xd;
                esi_1 = &(*esi_1)[2];
            }

            *esi_1 = eax_5;
            esi_1 = &(*esi_1)[2];
            int32_t __saved_esi;

            if (esi_1 >= (&__saved_esi + 2))
                break;
        }

        uint32_t nNumberOfBytesToWrite = (esi_1 - &buffer) & 0xfffffffe;
        uint32_t numberOfBytesWritten;

        if (!WriteFile(hFile, &buffer, nNumberOfBytesToWrite, &numberOfBytesWritten, nullptr))
        {
            *arg1 = GetLastError();
            break;
        }

        uint32_t numberOfBytesWritten_1 = numberOfBytesWritten;
        arg1[1] += numberOfBytesWritten_1;

        if (numberOfBytesWritten_1 < nNumberOfBytesToWrite)
            break;
    }

    int32_t entry_ebx;
    sub_402910(entry_ebx ^ &__saved_ebp);
    return arg1;
}

int32_t* write_text_utf8_nolock(int32_t* arg1, int32_t arg2, int16_t* arg3, void* arg4)
{
    sub_415440(0x1418);
    int32_t __saved_ebp;
    int32_t var_8 = __security_cookie ^ &__saved_ebp;
    int32_t* result = arg1;
    int32_t edi;
    int32_t var_10 = edi;
    HANDLE hFile = *((&data_41ed08)[arg2 >> 6] + (arg2 & 0x3f) * 0x38 + 0x18);
    void* ecx_4 = arg4 + arg3;
    *result = 0;
    int32_t* edi_2 = &result[1];
    *edi_2 = 0;
    edi_2[1] = 0;
    int16_t* edi_5 = arg3;

    if (arg3 < ecx_4)
    {
        do
        {
            wchar16 var_6b4[0x342];
            wchar16 (* eax_5)[0x342] = &var_6b4;

            while (edi_5 < ecx_4)
            {
                uint32_t ecx_5 = *edi_5;
                edi_5 = &edi_5[1];

                if (ecx_5 == 0xa)
                {
                    *eax_5 = 0xd;
                    eax_5 = &(*eax_5)[1];
                }

                *eax_5 = ecx_5;
                eax_5 = &(*eax_5)[1];
                int32_t __saved_esi;

                if (eax_5 >= &__saved_esi)
                    break;
            }

            CHAR var_140c[0xd58];
            int32_t eax_8 = sub_40e427(0xfde9, 0, &var_6b4, (eax_5 - &var_6b4) >> 1, &var_140c,
                0xd55, nullptr, nullptr);
            result = arg1;
            int32_t var_141c_1 = eax_8;

            if (!eax_8)
            {
            label_41326b:
                *result = GetLastError();
                break;
            }

            int32_t ebx = 0;

            if (eax_8)
            {
                do
                {
                    uint32_t numberOfBytesWritten;

                    if (!WriteFile(hFile, &var_140c[ebx], eax_8 - ebx, &numberOfBytesWritten,
                            nullptr))
                        goto label_41326b;

                    ebx += numberOfBytesWritten;
                    eax_8 = var_141c_1;
                } while (ebx < eax_8);
            }

            result[1] = edi_5 - arg3;
        } while (edi_5 < ecx_4);
    }

    int32_t entry_ebx;
    sub_402910(entry_ebx ^ &__saved_ebp);
    return result;
}

int32_t __write_internal(enum CONSOLE_MODE arg1, int16_t* arg2, uint32_t arg3, int32_t* arg4)
{
    int32_t __saved_ebp_1 = 0x14;
    int32_t var_8 = 0x41cee0;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41cee0 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_38 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_38;
    void* const var_3c_3 = &data_41328a;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t result;

    if (arg1 != ~ENABLE_PROCESSED_INPUT)
    {
        int32_t eax_1;

        if (arg1 < 0 || arg1 >= data_41ef08)
            eax_1 = 0;
        else
            eax_1 = 1;

        int32_t ecx_2;
        int32_t edx_1;

        if (eax_1)
        {
            ecx_2 = arg1 >> 6;
            edx_1 = (arg1 & 0x3f) * 0x38;
        }

        if (!eax_1 || !(*((&data_41ed08)[ecx_2] + edx_1 + 0x28) & 1))
        {
            arg4[9] = 1;
            arg4[8] = 0;
            arg4[7] = 1;
            arg4[6] = 9;
            __invalid_parameter_internal(0, 0, 0, 0, 0, arg4);
            result = 0xffffffff;
        }
        else
        {
            ___acrt_lowio_lock_fh(arg1);
            int32_t result_1 = 0xffffffff;
            int32_t var_20_1 = 0xffffffff;
            int32_t var_8_1 = 0;

            if (*(edx_1 + (&data_41ed08)[ecx_2] + 0x28) & 1)
            {
                result_1 = __write_nolock(arg1, arg2, arg3, arg4);
                int32_t result_2 = result_1;
            }
            else
            {
                arg4[7] = 1;
                arg4[6] = 9;
                arg4[9] = 1;
                arg4[8] = 0;
            }

            int32_t var_8_2 = 0xfffffffe;
            $LN13(arg1);
            result = result_1;
        }
    }
    else
    {
        arg4[9] = 1;
        arg4[8] = 0;
        arg4[7] = 1;
        arg4[6] = 9;
        result = 0xffffffff;
    }

    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t $LN13(int32_t arg1 @ edi)
{
    return ___acrt_lowio_unlock_fh(arg1);
}

int32_t __write_nolock(enum CONSOLE_MODE arg1, int16_t* arg2, uint32_t arg3, int32_t* arg4)
{
    enum CONSOLE_MODE ecx = arg1;
    enum CONSOLE_MODE var_14 = ecx;
    int32_t edi;
    int32_t var_40 = edi;

    if (arg3)
    {
        char eax_4;
        int32_t esi_2;
        int32_t edi_1;

        if (arg2)
        {
            esi_2 = ecx >> 6;
            edi_1 = (ecx & 0x3f) * 0x38;
            eax_4 = *(edi_1 + (&data_41ed08)[esi_2] + 0x29);
        }

        if (!arg2 || ((eax_4 == 2 || eax_4 == 1) && !(~arg3 & 1)))
        {
            arg4[9] = 1;
            arg4[8] = 0;
            arg4[7] = 1;
            arg4[6] = 0x16;
            __invalid_parameter_internal(0, 0, 0, 0, 0, arg4);
            return 0xffffffff;
        }

        int32_t edx_1 = esi_2;
        int32_t eax_7 = (&data_41ed08)[edx_1];

        if (*(edi_1 + eax_7 + 0x28) & 0x20)
        {
            eax_7 = __lseeki64_nolock_internal(ecx, 0, 0, FILE_END, arg4);
            ecx = var_14;
        }

        int32_t edi_2 = 0;
        int32_t var_28_1 = 0;
        int32_t ecx_2;
        int32_t edx_2;
        enum WIN32_ERROR var_34;
        int32_t* eax_13;
        int32_t* esi_3;

        if (!write_requires_double_translation_nolock(eax_7, edx_1, ecx, ecx, arg4))
        {
            edx_2 = esi_2;
            ecx_2 = edi_1;
            int32_t eax_14 = (&data_41ed08)[edx_2];

            if (*(eax_14 + ecx_2 + 0x28) >= 0)
            {
                HANDLE hFile = *(eax_14 + ecx_2 + 0x18);
                var_34 = NO_ERROR;
                uint32_t numberOfBytesWritten;
                uint32_t* edi_3 = &numberOfBytesWritten;
                *edi_3 = 0;
                edi_3[1] = 0;

                if (!WriteFile(hFile, arg2, arg3, &numberOfBytesWritten, nullptr))
                    var_34 = GetLastError();

                esi_3 = &var_34;
                goto label_41352d;
            }

            int32_t eax_15 = eax_4;

            if (!eax_15)
            {
                eax_13 = write_text_ansi_nolock(&var_34, var_14, arg2, arg3);
                goto label_413474;
            }

            if (eax_15 == 1)
            {
                eax_13 = write_text_utf8_nolock(&var_34, var_14, arg2, arg3);
                goto label_413474;
            }

            if (eax_15 == 2)
            {
                eax_13 = write_text_utf16le_nolock(&var_34, var_14, arg2, arg3);
                goto label_413474;
            }
        }
        else
        {
            int32_t eax_9 = eax_4;

            if (!eax_9)
            {
                eax_13 = sub_412ad8(&var_34, var_14, arg2, arg3, arg4);
            label_413474:
                esi_3 = eax_13;
            label_41352d:
                int32_t var_28_2 = *esi_3;
                int32_t var_24;
                int32_t* edi_6 = &var_24;
                int32_t* esi_4 = &esi_3[1];
                *edi_6 = *esi_4;
                edi_6[1] = esi_4[1];
                int32_t eax_21 = var_24;
                int32_t var_20;

                if (eax_21)
                    return eax_21 - var_20;
                edi_2 = var_28_2;
                edx_2 = esi_2;
                ecx_2 = edi_1;
            }
            else
            {
                if (eax_9 == 1 || eax_9 == 2)
                {
                    eax_13 = write_double_translated_unicode_nolock(&var_34, arg2, arg3);
                    goto label_413474;
                }

                edx_2 = esi_2;
                ecx_2 = edi_1;
            }
        }

        if (edi_2)
        {
            if (edi_2 != 5)
                ___acrt_errno_map_os_error_ptd(edi_2, arg4);
            else
            {
                arg4[7] = 1;
                arg4[6] = 9;
                arg4[9] = 1;
                arg4[8] = 5;
            }

            return 0xffffffff;
        }

        if (!(*((&data_41ed08)[edx_2] + ecx_2 + 0x28) & 0x40) || *arg2 != 0x1a)
        {
            arg4[7] = 1;
            arg4[6] = 0x1c;
            arg4[9] = 1;
            arg4[8] = 0;
            return 0xffffffff;
        }
    }

    return 0;
}

int32_t* sub_4135b0(int32_t arg1, int32_t* arg2, int16_t* arg3)
{
    void* const __return_addr_1 = __return_addr;
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    int32_t edi;
    int32_t var_a0 = edi;
    uint32_t ecx = *arg3;
    uint32_t var_94 = ecx;
    int32_t edi_1;

    switch (*arg2 - 1)
    {
        case 0:
        case 4:
        {
            edi_1 = 8;
        label_413623:

            if (!sub_407c50(edi_1, &arg2[6], ecx))
            {
                int32_t var_50;

                if (arg1 == 0x10 || arg1 == 0x16 || arg1 == 0x1d)
                {
                    int64_t var_60_1 = *(arg2 + 0x10);
                    int32_t var_50_2 = (var_50 & 0xffffffe3) | 3;
                }
                else
                    int32_t var_50_1 = var_50 & 0xfffffffe;
                void var_90;
                sub_407f80(&var_90, &var_94, edi_1, arg1, &arg2[2], &arg2[6]);
                /* no return */
            }
            break;
        }
        case 1:
        {
            edi_1 = 4;
            goto label_413623;
        }
        case 2:
        {
            edi_1 = 0x11;
            goto label_413623;
        }
        case 3:
        {
            edi_1 = 0x12;
            goto label_413623;
        }
        case 7:
        {
            edi_1 = 0x10;
            goto label_413623;
        }
    }

    int16_t x87control;
    sub_40c870(x87control, var_94, 0xffff);
    int32_t* result;

    if (*arg2 == 8)
        result = __set_errno_from_matherr(*arg2);
    else if (!___acrt_has_user_matherr())
        result = __set_errno_from_matherr(*arg2);
    else
    {
        result = sub_4085b0(arg2);

        if (!result)
            result = __set_errno_from_matherr(*arg2);
    }

    sub_402910(eax_1 ^ &__saved_ebp);
    return result;
}

int32_t _fegetenv(int32_t* arg1)
{
    int32_t mxcsr;
    *arg1 = sub_40c950(mxcsr);
    arg1[1] = sub_40cb30(mxcsr);
    return 0;
}

int32_t sub_413710(int32_t* arg1)
{
    int32_t mxcsr;
    sub_40ce30(sub_40cbe0(mxcsr, *arg1), arg1[1]);
    int64_t var_c = 0;
    _fegetenv(&var_c);

    if (*arg1 != var_c)
        return 1;

    int32_t result = 0;
    result = arg1[1] != *(&var_c + 4);
    return result;
}

int32_t sub_413770(int32_t* arg1)
{
    int32_t var_c = 0;
    int32_t var_8 = 0;
    _fegetenv(&var_c);
    int32_t edx_1 = var_c;
    *arg1 = edx_1;
    arg1[1] = var_8;
    var_c = edx_1 | 0x1f;
    int32_t eax_2;
    int32_t mxcsr_1;
    eax_2 = sub_413710(&var_c);

    if (eax_2)
        return 1;

    sub_40f9b0(mxcsr_1);
    return 0;
}

void* __libm_sse2_log10_precise(int32_t arg1 @ mxcsr, int16_t arg2 @ x87control, int64_t arg3 @ xmm0)
{
    double var_8;

    if ((arg1 & 0x7f80) == 0x1f80)
    {
        int16_t x87status_1;
        int16_t temp0_1;
        temp0_1 = __fnstcw_memmem16(arg2);
        var_8 = temp0_1;

        if ((var_8 & 0x7f) == 0x7f)
        {
            var_8 = arg3;
            int32_t edx = 0;
            void* eax_4;
            uint32_t ecx_1;
            double xmm0_4[0x2];
            double xmm0_5[0x2];
            double xmm6_4[0x2];
            int64_t xmm7_1;

            while (true)
            {
                double xmm0[0x2] = _mm_unpacklo_pd(arg3, arg3);
                ecx_1 = _mm_extract_epi16(_mm_srli_epi64(arg3, 0x34), 0);
                uint64_t xmm1_1[0x2] = data_41b900;
                double xmm2_1[0x2] = data_41b910;
                double xmm4_1[0x2] = data_41b920;
                uint64_t xmm6_1[0x2] = data_41b930;
                uint64_t xmm0_2[0x2] = _mm_or_pd(_mm_and_pd(xmm0, xmm1_1), *data_41b970);
                eax_4 = _mm_extract_epi16(_mm_add_pd(xmm4_1, xmm0_2), 0) & 0x7f0;
                double xmm4_3[0x2] = *(eax_4 + 0x41be70);
                xmm7_1 = *(eax_4 + 0x41ba60);
                uint64_t xmm6_2[0x2] = _mm_and_pd(xmm6_1, xmm0_2);
                double xmm0_3[0x2] = _mm_sub_pd(xmm0_2, xmm6_2);
                xmm6_4 = _mm_sub_pd(_mm_mul_pd(xmm6_2, xmm4_3), xmm2_1);
                xmm0_4 = _mm_mul_pd(xmm0_3, xmm4_3);
                xmm0_5 = _mm_add_pd(xmm0_4, xmm6_4);

                if ((ecx_1 & 0xfff) - 1 <= 0x7fd)
                    break;

                double xmm0_11 = var_8;
                double xmm1_10[0x2] = _mm_cmpeq_sd(_mm_xor_pd(xmm1_1, xmm1_1), xmm0_11, 0);
                int64_t var_10;

                if (_mm_extract_epi16(xmm1_10, 0) > 0)
                {
                    var_10 = -0x10000000000000;
                    return sub_413e10(&var_8, &var_8, &var_10, 8);
                }

                if (ecx_1 & 0xfff)
                {
                    uint32_t edx_2;

                    if ((ecx_1 & 0xfff) - 1 > 0x7fe)
                    {
                        int32_t eax_10;

                        if ((ecx_1 & 0x7ff) >= 0x7ff)
                        {
                            uint64_t xmm2_9[0x2] = var_8;
                            eax_10 = xmm2_9 | (_mm_srli_epi64(xmm2_9, 0x20) & 0xfffff);
                        }

                        if ((ecx_1 & 0x7ff) < 0x7ff || !eax_10)
                        {
                            double xmm1_11 = _mm_xor_pd(xmm1_10, xmm1_10);
                            xmm1_10 = xmm1_11 / xmm1_11;
                            edx_2 = 9;
                        }
                        else
                            edx_2 = 0x3e9;
                    }
                    else
                    {
                        xmm1_10 = data_41b900;
                        uint64_t xmm2_6[0x2] = *data_41b970;
                        uint32_t eax_7 = _mm_extract_epi16(
                            _mm_cmpeq_sd(xmm2_6, _mm_or_pd(_mm_and_pd(var_8, xmm1_10), xmm2_6), 0),
                            0);

                        if (eax_7)
                            return eax_7;

                        edx_2 = 0x3e9;
                    }

                    var_10 = xmm1_10;
                    return sub_413e10(&var_8, &var_8, &var_10, edx_2);
                }

                arg3 = xmm0_11 * 4503599627370496.0;
                edx = 0xffffffcc;
            }

            int32_t ecx_5 = (ecx_1 & 0xfff) - 0x3ff + edx;
            double xmm6_5[0x2] = ecx_5;
            double xmm6_6[0x2] = _mm_unpacklo_pd(xmm6_5, xmm6_5);
            void* eax_5 = eax_4 + (ecx_5 << 0xa);
            void* const edx_1 = nullptr;

            if (!eax_5)
                edx_1 = 0x10;

            double xmm2_2[0x2] = data_41b9d0;
            double xmm1_3[0x2] = _mm_mul_pd(data_41b9c0, xmm0_5);
            double xmm3_3 = _mm_mul_pd(xmm0_5, xmm0_5);
            double xmm1_4[0x2] = _mm_add_pd(xmm1_3, xmm2_2);
            double xmm2_3[0x2] = data_41b9e0;
            double xmm6_7[0x2] = _mm_mul_pd(xmm6_6, data_41b940);
            uint64_t xmm4_5[0x2] = _mm_and_pd(xmm0_4, *(edx_1 + 0x41b950));
            double xmm7_4[0x2] = _mm_add_pd(_mm_add_pd(xmm7_1 + xmm6_4, xmm6_7), xmm4_5);
            double xmm1_6[0x2] = _mm_add_pd(_mm_mul_pd(xmm1_4, xmm0_5), xmm2_3);
            double xmm2_5[0x2] = _mm_mul_pd(data_41b9f0, xmm0_5);
            _mm_unpackhi_pd(xmm7_4, xmm7_4);
            double xmm1_7[0x2] = _mm_mul_pd(xmm1_6, xmm3_3 * xmm3_3 * xmm0_5);
            _mm_add_pd(xmm1_7, xmm2_5);
            _mm_unpackhi_pd(xmm1_7, xmm1_7);
            return eax_5;
        }
    }

    var_8 = arg3;
    int32_t eax_11;
    long double st0;
    st0 = sub_4140ff();
    var_8 = st0;
    return eax_11;
}

long double sub_413ac0(int32_t arg1 @ mxcsr, int16_t arg2 @ x87control, int64_t arg3)
{
    if (data_41eae8 >= 2)
    {
        int64_t xmm0 = arg3;
        arg3 = _mm_round_sd(xmm0, xmm0, 0xa);
        return arg3;
    }

    if (data_41f148)
    {
        int32_t eax_10 = arg1 & 0x7f80;
        bool cond:0_1 = eax_10 != 0x1f80;
        int16_t var_8;

        if (eax_10 == 0x1f80)
        {
            int16_t x87status_1;
            int16_t temp0_1;
            temp0_1 = __fnstcw_memmem16(arg2);
            var_8 = temp0_1;
            cond:0_1 = (var_8 & 0x7f) != 0x7f;
        }

        if (!cond:0_1)
        {
            uint128_t xmm0_2 = arg3;
            int32_t xmm2[0x4] = data_41ba10;
            int64_t xmm7 = xmm0_2;
            uint64_t xmm0_3[0x2] = _mm_srli_epi64(xmm0_2, 0x34);
            int32_t eax_1 = xmm0_3;
            int32_t xmm2_1[0x4] = _mm_sub_epi32(xmm2, __andpd_xmmxuq_memxuq(xmm0_3, data_41ba30));
            int32_t xmm1_1[0x4] = _mm_srl_epi64(xmm0_2, xmm2_1);

            if (!(eax_1 & 0x800))
            {
                uint128_t xmm0_5 = arg3;
                double xmm1_3[0x2] = _mm_sll_epi64(xmm1_1, xmm2_1);

                if (eax_1 < 0x3ff)
                {
                    arg3 = __andpd_xmmxuq_memxuq(__cmppd_xmmpd_mempd_immb(xmm0_5, data_41ba20, 6),
                        data_41ba00);
                    return arg3;
                }

                if (eax_1 <= 0x432)
                {
                    arg3 = xmm1_3
                        + __andpd_xmmxuq_memxuq(_mm_cmpeq_pd(xmm0_5, xmm1_3, 6), data_41ba00);
                    return arg3;
                }
            }
            else
            {
                if (eax_1 < 0xbff)
                    return -0.0;

                int64_t xmm1_2 = _mm_sll_epi64(xmm1_1, xmm2_1);

                if (eax_1 <= 0xc32)
                {
                    arg3 = xmm1_2;
                    return arg3;
                }
            }

            if (!FCMP_O(xmm7, xmm7))
            {
                int32_t __saved_ebp_1 = 0x3ec;
                var_8 = &arg3;
                int64_t var_c;
                var_c = &arg3;
                int64_t var_14;
                *(&var_14 + 4) = &arg3;
                sub_413e10();
            }

            return arg3;
        }
    }

    int32_t __saved_ebp_4;
    int32_t __saved_ebp_2 = __saved_ebp_4;
    int32_t __saved_ebx_1;
    int32_t __saved_ebx = __saved_ebx_1;
    int32_t var_1c = 0xffff;
    int32_t var_20 = 0x1b3f;
    int32_t eax_2;
    int16_t x87control;
    eax_2 = sub_40c870(arg2);
    int32_t eax_4 = *(&arg3 + 4) & 0x7ff00000;
    var_20 = arg3;

    if (eax_4 == 0x7ff00000)
    {
        int32_t eax_5 = sub_40c6f0();

        if (eax_5 != 1 && eax_5 != 2 && eax_5 != 3)
        {
            int64_t xmm1_5 = arg3;
            double var_24_1 = xmm1_5 + 1.0;
            int64_t var_2c = xmm1_5;
            int32_t var_30 = 0xc;
            int32_t var_34 = 8;
            return sub_407b10(8, 0xc, eax_2);
        }

        int32_t var_1c_2 = 0xffff;
        int32_t var_20_1 = eax_2;
        sub_40c870(x87control);
        return arg3;
    }

    long double st0_1 = __frnd();
    int64_t xmm0_11 = arg3;
    double var_c_1 = st0_1;
    var_c_1 - xmm0_11;
    *(&eax_4 + 1) = (var_c_1 == xmm0_11 ? 1 : 0) << 6 | (FCMP_UO(var_c_1, xmm0_11) ? 1 : 0) << 2
        | (var_c_1 < xmm0_11 ? 1 : 0);

    if (__builtin_popcount(*(&eax_4 + 1) & 0x44) & 1 || eax_2 & 0x20)
    {
        int32_t var_1c_4 = 0xffff;
        int32_t var_20_2 = eax_2;
        sub_40c870(x87control);
        return st0_1;
    }

    double var_24_2 = var_c_1;
    int64_t var_2c_1 = xmm0_11;
    int32_t var_30_1 = 0xc;
    int32_t var_34_1 = 0x10;
    return sub_407b10(0x10, 0xc, eax_2);
}

int32_t _fclose_internal(int32_t* arg1, int32_t* arg2)
{
    int32_t __saved_ebp_1 = 0x10;
    int32_t var_8 = 0x41cf00;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41cf00 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_34 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_34;
    void* const var_38_3 = &data_413bc9;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t* var_24 = arg1;
    int32_t result;

    if (!arg1)
    {
        arg2[7] = 1;
        arg2[6] = 0x16;
        __invalid_parameter_internal(0, 0, 0, 0, 0, arg2);
        result = 0xffffffff;
    }
    else if (!(arg1[3] >> 0xc & 1))
    {
        int32_t var_20_1 = 0;
        __lock_file(arg1);
        int32_t var_8_1 = 0;
        int32_t result_1 = _fclose_nolock_internal(arg1, arg2);
        int32_t result_2 = result_1;
        int32_t var_8_2 = 0xfffffffe;
        $LN9(arg1);
        result = result_1;
    }
    else
    {
        __acrt_stdio_free_stream(arg1);
        result = 0xffffffff;
    }

    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t sub_413c46(void* arg1 @ ebp)
{
    *(arg1 - 0x1c);
    /* tailcall */
    return $LN9(*(arg1 - 0x20));
}

int32_t $LN9(void* arg1 @ esi)
{
    return __unlock_file(arg1);
}

int32_t _fclose_nolock_internal(int32_t* arg1, int32_t* arg2)
{
    if (!arg1)
    {
        arg2[7] = 1;
        arg2[6] = 0x16;
        __invalid_parameter_internal(0, 0, 0, 0, 0, arg2);
        return 0xffffffff;
    }

    int32_t edi;
    int32_t var_c_1 = edi;
    int32_t result = 0xffffffff;

    if (arg1[3] >> 0xd & 1)
    {
        result = ___acrt_stdio_flush_nolock(arg1, arg2);
        ___acrt_stdio_free_buffer_nolock(arg1);

        if (__close_internal(__fileno(arg1), arg2) < 0)
            result = 0xffffffff;
        else if (arg1[7])
        {
            __free_base(arg1[7]);
            arg1[7] = 0;
        }
    }

    __acrt_stdio_free_stream(arg1);
    return result;
}

int32_t _fclose(int32_t* arg1)
{
    void var_2c;
    __crt_cached_ptd_host::__crt_cached_ptd_host(&var_2c, nullptr);
    int32_t result = _fclose_internal(arg1, &var_2c);
    __crt_cached_ptd_host::~__crt_cached_ptd_host(&var_2c);
    return result;
}

int32_t __convention("regparm") common_lseek_nolock<int64_t>(int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4, int32_t arg5, int32_t arg6, enum SET_FILE_POINTER_MOVE_METHOD arg7, void* arg8)
{
    int32_t newFilePointer = arg3;
    int32_t edi;
    int32_t var_14 = edi;
    HANDLE hFile = __get_osfhandle(arg4);
    int32_t result;

    if (hFile != 0xffffffff)
    {
        int32_t var_20_1 = arg6;

        if (!SetFilePointerEx(hFile, arg5, &newFilePointer, arg7))
        {
            ___acrt_errno_map_os_error_ptd(GetLastError(), arg8);
            result = 0xffffffff;
        }
        else if ((newFilePointer & arg3) == 0xffffffff)
            result = 0xffffffff;
        else
        {
            result = newFilePointer;
            int32_t esi_2 = (arg4 & 0x3f) * 0x38;
            int32_t ecx_4 = (&data_41ed08)[arg4 >> 6];
            *(ecx_4 + esi_2 + 0x28) &= 0xfd;
        }
    }
    else
    {
        *(arg8 + 0x1c) = 1;
        *(arg8 + 0x18) = 9;
        result = 0xffffffff;
    }

    return result;
}

int32_t __lseeki64_nolock_internal(int32_t arg1, int32_t arg2, int32_t arg3, enum SET_FILE_POINTER_MOVE_METHOD arg4, void* arg5)
{
    int32_t eax;
    int32_t ecx;
    int32_t edx;
    return common_lseek_nolock<int64_t>(eax, edx, ecx, arg1, arg2, arg3, arg4, arg5);
}

char* sub_413dc0(char* arg1, int32_t arg2)
{
    char* result = nullptr;

    if (*arg1)
    {
        while (result != arg2)
        {
            result = &result[1];

            if (!*(result + arg1))
                break;
        }
    }

    return result;
}

BOOL __fastcall __putwch_nolock(uint32_t arg1)
{
    uint32_t var_8 = arg1;

    if (___dcrt_lowio_ensure_console_output_initialized())
    {
        int16_t arg_4;
        BOOL result = sub_414586(&arg_4, 1, &var_8);

        if (result)
        {
            result = arg_4;
            return result;
        }
    }

    return 0xffff;
}

uint32_t sub_413e10(int64_t* arg1, int64_t* arg2, int64_t* arg3, uint32_t arg4)
{
    int32_t edi;
    int32_t var_28 = edi;
    int32_t (* edi_1)(int32_t arg1);

    if (!data_41f12c)
        edi_1 = sub_4085b0;
    else
        edi_1 = DecodePointer(data_41f144);

    uint32_t eax_2 = arg4;

    if (eax_2 <= 0x3e8)
    {
        if (eax_2 == 0x3e8)
        {
            *arg3 = *arg1;
            return arg3;
        }

        eax_2 -= 2;

        if (eax_2 <= 0x3b)
        {
            eax_2 = lookup_table_414068[eax_2];
            int32_t var_24;
            int64_t var_c_1;
            int32_t* eax_8;

            switch (eax_2)
            {
                case 0:
                {
                    var_24 = 2;
                    void* const var_20 = &data_416ef8;
                label_413f3f:
                    int64_t var_1c_1 = *arg1;
                    int64_t var_14_1 = *arg2;
                    var_c_1 = *arg3;
                    eax_8 = edi_1(&var_24);

                    if (eax_8)
                    {
                        *arg3 = var_c_1;
                        return eax_8;
                    }

                    int32_t* eax_9 = sub_40a844();
                    *eax_9 = 0x22;
                    *arg3 = var_c_1;
                    return eax_9;
                    break;
                }
                case 1:
                {
                    void* const var_20_1 = &data_416ef8;
                label_413fb8:
                    var_24 = 1;
                    int64_t var_1c_2 = *arg1;
                    int64_t var_14_2 = *arg2;
                    var_c_1 = *arg3;
                    eax_8 = edi_1(&var_24);

                    if (!eax_8)
                    {
                        eax_8 = sub_40a844();
                        *eax_8 = 0x21;
                    }

                    *arg3 = var_c_1;
                    return eax_8;
                    break;
                }
                case 2:
                {
                    var_24 = 2;
                    char const* const var_20_2 = "log10";
                    goto label_413f3f;
                }
                case 3:
                {
                    char const* const var_20_3 = "log10";
                    goto label_413fb8;
                }
                case 4:
                {
                    var_24 = 3;
                    void* const var_20_4 = &data_416ef0;
                    goto label_413f3f;
                }
                case 5:
                {
                    void* const var_20_5 = &data_416ef0;
                label_413ee9:
                    var_24 = 4;
                    int64_t var_1c = *arg1;
                    int64_t var_14 = *arg2;
                    int64_t xmm0_4 = *arg3;
                    int32_t eax_5 = edi_1(&var_24);
                    *arg3 = xmm0_4;
                    return eax_5;
                    break;
                }
                case 6:
                {
                    var_24 = 3;
                label_413f33:
                    void* const var_20_7 = &data_416ef4;
                    goto label_413f3f;
                }
                case 7:
                {
                    void* const var_20_6 = &data_416ef4;
                    goto label_413ee9;
                }
                case 8:
                {
                    eax_2 = arg3;
                    *eax_2 = 0x3ff0000000000000;
                    break;
                }
                case 9:
                {
                    var_24 = 2;
                    goto label_413f33;
                }
                case 0xa:
                {
                    void* const var_20_8 = &data_416ef4;
                    goto label_413fb8;
                }
                case 0xb:
                {
                    char const* const var_20_11 = "sqrt";
                    goto label_413fb8;
                }
                case 0xc:
                {
                    char const* const var_20_10 = "acos";
                    goto label_413fb8;
                }
                case 0xd:
                {
                    char const* const var_20_9 = "asin";
                    goto label_413fb8;
                }
            }
        }
    }
    else if (eax_2 == 0x3e9)
    {
        *arg3 = *arg1;
        return arg3;
    }

    return eax_2;
}

int32_t sub_4140b0(int32_t arg1 @ mxcsr, int16_t arg2 @ x87control, long double arg3 @ st0) __location("st0")
{
    int32_t var_4;

    if (data_41f148)
    {
        var_4 = arg1;
        int32_t eax_2 = var_4 & 0x7f80;
        bool cond:0_1 = eax_2 != 0x1f80;

        if (eax_2 == 0x1f80)
        {
            int16_t x87status_1;
            int16_t temp0_1;
            temp0_1 = __fnstcw_memmem16(arg2);
            int48_t var_c;
            *(&var_c + 4) = temp0_1;
            cond:0_1 = (*(&var_c + 4) & 0x7f) != 0x7f;
        }

        if (!cond:0_1)
            /* tailcall */
            return sub_4145e0(arg3);
    }

    return sub_414108(__checkTOS_withFB(arg3, var_4), arg2, arg3);
}

int32_t sub_4140ff() __location("st0")
{
    void arg_4;
    int32_t eax;
    int32_t ecx;
    long double st0;
    st0 = __fload_withFB(ecx, &arg_4);
    int16_t x87control;
    /* tailcall */
    return sub_414108(eax, x87control, st0);
}

void __convention("regparm") sub_414108(int32_t arg1, int16_t arg2 @ x87control, long double arg3 @ st0, int32_t arg4 @ 0x4, int32_t arg5 @ 0x8)
{
    int32_t edx;
    int32_t var_4 = edx;
    int16_t x87status;
    int16_t temp0;
    temp0 = __fnstcw_memmem16(arg2);
    var_4 = temp0;
    bool z;
    int32_t eax_1;

    if (z)
    {
        if (!(arg1 & 0xfffff) && !arg4)
        {
            if (!(arg1 & 0x80000000))
                goto label_414135;

        label_414172:
            arg3 = data_418660;
            eax_1 = 1;
            goto label_4141a1;
        }

        long double st0_1;
        st0_1 = __convertTOStoQNaN(arg1, arg3);
        arg3 = st0_1;
    label_4141a1:

        if (!data_41f128)
        {
            __startOneArgErrorHandling(eax_1, 0x1b, arg3, arg4, arg5);
            return;
        }
    }
    else
    {
        int16_t x87control;
        int16_t x87status_1;

        if (var_4 != 0x27f)
            x87control = __fldcw_memmem16(0x27f);

        if (!(arg5 & 0x7ff00000))
        {
            if (!(arg5 & 0xfffff) && !arg4)
            {
                arg3 = data_41c39a;
                eax_1 = 2;
                goto label_4141a1;
            }

            if (arg5 & 0x80000000)
                goto label_414172;

            goto label_414133;
        }

        if (arg5 & 0x80000000)
            goto label_414172;

    label_414133:
        long double st1_1;
        bool c1;
        st1_1 = __fyl2x(arg3, 0.30102999560767785 + 5.6303348065105986e-11);
        arg3 = st1_1;
    label_414135:

        if (!data_41f128)
        {
            int16_t eax_2 = var_4;

            if (eax_2 != 0x27f)
            {
                bool c0;
                bool c2;
                bool c3;

                if (eax_2 & 0x20 && ((c0 ? 1 : 0) << 8 | (c1 ? 1 : 0) << 9 | (c2 ? 1 : 0) << 0xa
                    | (c3 ? 1 : 0) << 0xe) & 0x20)
                {
                    __startOneArgErrorHandling(8, 0x1b, arg3, arg4, arg5);
                    return;
                }

                int16_t x87control_2;
                int16_t x87status_3;
                x87control_2 = __fldcw_memmem16(var_4);
            }

            return;
        }
    }
    int16_t x87control_1;
    int16_t x87status_2;

    if (var_4 != 0x27f)
        x87control_1 = __fldcw_memmem16(var_4);
}

int32_t __stdcall __crt_seh_guarded_call<int32_t>::operator()<class <lambda_d422a76eb4c3bf3ad751449ab71a6ea4>,class <lambda_c9ba49e555ba839a7b07aa3fbecb7617>&,class <lambda_9476263c8ee91a25d21c55370bdb50de> >(int32_t* arg1, int32_t* arg2)
{
    int32_t __saved_ebp_1 = 0xc;
    int32_t var_8 = 0x41cf20;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x41cf20 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_2 = &data_4142bf;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t var_20 = 0;
    ___acrt_lowio_lock_fh(*arg1);
    int32_t var_8_1 = 0;
    int32_t edi = **arg2;
    void* esi = arg2[1];
    int32_t result;

    if (!(*((&data_41ed08)[edi >> 6] + (edi & 0x3f) * 0x38 + 0x28) & 1))
    {
        *(esi + 0x1c) = 1;
        *(esi + 0x18) = 9;
        result = 0xffffffff;
    }
    else
        result = __close_nolock_internal(edi, esi);

    int32_t result_1 = result;
    int32_t var_8_2 = 0xfffffffe;
    $LN7(&__saved_ebp);
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t sub_414335(void* arg1 @ ebp)
{
    *(arg1 - 0x1c);
    /* tailcall */
    return $LN7(arg1);
}

int32_t $LN7(void* arg1 @ ebp)
{
    return ___acrt_lowio_unlock_fh(**(arg1 + 0x10));
}

int32_t __close_internal(int32_t arg1, int32_t* arg2)
{
    int32_t esi = arg1;

    if (esi != 0xfffffffe)
    {
        if (esi >= 0 && esi < data_41ef08
            && *((&data_41ed08)[esi >> 6] + (esi & 0x3f) * 0x38 + 0x28) & 1)
        {
            int32_t var_c = esi;
            int32_t* var_18 = &arg1;
            int32_t* var_14_1 = arg2;
            int32_t* var_20_1 = &var_c;
            int32_t var_10 = esi;
            return __crt_seh_guarded_call<int32_t>::operator()<class <lambda_d422a76eb4c3bf3ad751449ab71a6ea4>,class <lambda_c9ba49e555ba839a7b07aa3fbecb7617>&,class <lambda_9476263c8ee91a25d21c55370bdb50de> >(
                &var_10, &var_18);
        }

        arg2[9] = 1;
        arg2[8] = 0;
        arg2[7] = 1;
        arg2[6] = 9;
        __invalid_parameter_internal(0, 0, 0, 0, 0, arg2);
    }
    else
    {
        arg2[8] = 0;
        arg2[9] = 1;
        arg2[7] = 1;
        arg2[6] = 9;
    }

    return 0xffffffff;
}

int32_t __close_nolock_internal(int32_t arg1, void* arg2)
{
    int32_t edi;
    int32_t var_c = edi;
    enum WIN32_ERROR esi_2;

    if (__get_osfhandle(arg1) != 0xffffffff)
    {
        void* eax_1 = data_41ed08;

        if ((arg1 != 1 || !(*(eax_1 + 0x98) & 1)) && (arg1 != 2 || !(*(eax_1 + 0x60) & 1)))
        {
        label_41443d:

            if (CloseHandle(__get_osfhandle(arg1)))
                esi_2 = NO_ERROR;
            else
                esi_2 = GetLastError();
        }
        else
        {
            int32_t eax_2 = __get_osfhandle(2);

            if (__get_osfhandle(1) != eax_2)
                goto label_41443d;

            esi_2 = NO_ERROR;
        }
    }
    else
        esi_2 = NO_ERROR;

    __free_osfhnd(arg1);
    *((&data_41ed08)[arg1 >> 6] + (arg1 & 0x3f) * 0x38 + 0x28) = 0;

    if (!esi_2)
        return 0;

    ___acrt_errno_map_os_error_ptd(esi_2, arg2);
    return 0xffffffff;
}

int32_t* __acrt_stdio_free_stream(int32_t* arg1)
{
    *arg1 = 0;
    arg1[1] = 0;
    arg1[2] = 0;
    arg1[4] = 0xffffffff;
    arg1[5] = 0;
    arg1[6] = 0;
    arg1[7] = 0;
    arg1[3];
    arg1[3] = 0;
    return &arg1[3];
}

int32_t ___ascii_strnicmp(char* arg1, char* arg2, int32_t arg3)
{
    int32_t result = arg3;

    if (result)
    {
        char* esi_1 = arg1;
        char* edi_1 = arg2;
        int32_t result_1 = result;

        while (true)
        {
            int16_t eax;
            *(&eax + 1) = *esi_1;
            *(&eax + 1) = *(&eax + 1);
            bool cond:1_1 = !*(&eax + 1);
            eax = *edi_1;
            bool cond:0_1;

            if (cond:1_1)
            {
            label_41451b:
                result = 0;
                cond:0_1 = *(&eax + 1) < eax;

                if (*(&eax + 1) == eax)
                    break;
            }
            else
            {
                eax = eax;

                if (!eax)
                    goto label_41451b;

                esi_1 = &esi_1[1];
                edi_1 = &edi_1[1];

                if (*(&eax + 1) >= 0x41 && *(&eax + 1) <= 0x5a)
                    *(&eax + 1) += 0x20;

                if (eax >= 0x41 && eax <= 0x5a)
                    eax += 0x20;

                cond:0_1 = *(&eax + 1) < eax;

                if (*(&eax + 1) == eax)
                {
                    int32_t result_2 = result_1;
                    result_1 -= 1;

                    if (result_2 != 1)
                        continue;

                    goto label_41451b;
                }
            }

            result = 0xffffffff;

            if (!cond:0_1)
                return 1;

            break;
        }
    }

    return result;
}

HANDLE sub_414531()
{
    HANDLE result = CreateFileW(u"CONOUT$", 0x40000000, FILE_SHARE_READ | FILE_SHARE_WRITE,
        nullptr, OPEN_EXISTING, SECURITY_ANONYMOUS, nullptr);
    data_41e9e0 = result;
    return result;
}

int32_t ___dcrt_lowio_ensure_console_output_initialized()
{
    int32_t ecx = data_41e9e0;

    if (ecx == 0xfffffffe)
    {
        sub_414531();
        ecx = data_41e9e0;
    }

    int32_t result = 0;
    result = ecx != 0xffffffff;
    return result;
}

BOOL sub_41456f()
{
    BOOL hObject = data_41e9e0;

    if (hObject != 0xffffffff && hObject != 0xfffffffe)
        return CloseHandle(hObject);

    return hObject;
}

BOOL sub_414586(void* arg1, uint32_t arg2, uint32_t* arg3)
{
    BOOL lpReserved = WriteConsoleW(data_41e9e0, arg1, arg2, arg3, nullptr);

    if (!lpReserved && GetLastError() == ERROR_INVALID_HANDLE)
    {
        sub_41456f();
        sub_414531();
        return WriteConsoleW(data_41e9e0, arg1, arg2, arg3, lpReserved);
    }

    return lpReserved;
}

int32_t sub_4145e0(long double arg1 @ st0) __location("st0")
{
    double var_10 = arg1;
    return start(var_10, var_10);
}

int32_t sub_4145f8(double arg1)
{
    /* tailcall */
    return start(arg1, arg1);
}

long double start(double arg1[0x2] @ xmm0, double arg2)
{
    int32_t edx = 0;
    double var_c;
    void* eax_2;
    uint32_t ecx_1;
    double xmm0_4[0x2];
    double xmm0_5[0x2];
    double xmm6_4[0x2];
    int64_t xmm7_1;

    while (true)
    {
        double xmm0[0x2] = _mm_unpacklo_pd(arg1, arg1);
        ecx_1 = _mm_extract_epi16(_mm_srli_epi64(arg1, 0x34), 0);
        double xmm2_1[0x2] = data_41c2a0;
        double xmm4_1[0x2] = data_41c2b0;
        uint64_t xmm6_1[0x2] = data_41c2c0;
        uint64_t xmm0_2[0x2] = _mm_or_pd(_mm_and_pd(xmm0, data_41c290), *data_41c300);
        eax_2 = _mm_extract_epi16(_mm_add_pd(xmm4_1, xmm0_2), 0) & 0x7f0;
        double xmm4_3[0x2] = *(eax_2 + 0x41be70);
        xmm7_1 = *(eax_2 + 0x41ba60);
        uint64_t xmm6_2[0x2] = _mm_and_pd(xmm6_1, xmm0_2);
        double xmm0_3[0x2] = _mm_sub_pd(xmm0_2, xmm6_2);
        xmm6_4 = _mm_sub_pd(_mm_mul_pd(xmm6_2, xmm4_3), xmm2_1);
        xmm0_4 = _mm_mul_pd(xmm0_3, xmm4_3);
        xmm0_5 = _mm_add_pd(xmm0_4, xmm6_4);

        if ((ecx_1 & 0xfff) - 1 <= 0x7fd)
            break;

        double xmm0_11 = arg2;
        double xmm1_10[0x2] = _mm_cmpeq_sd(data_41c310, xmm0_11, 0);
        uint32_t edx_2;

        if (_mm_extract_epi16(xmm1_10, 0) > 0)
        {
            xmm1_10 = -0x10000000000000;
            edx_2 = 8;
        label_41480d:
            var_c = xmm1_10;
            sub_413e10(&arg2, &arg2, &var_c, edx_2);
            return var_c;
        }

        if (ecx_1 & 0xfff)
        {
            if ((ecx_1 & 0xfff) - 1 > 0x7fe)
            {
                int32_t eax_7;

                if ((ecx_1 & 0x7ff) >= 0x7ff)
                {
                    uint64_t xmm2_9[0x2] = arg2;
                    eax_7 = xmm2_9 | (_mm_srli_epi64(xmm2_9, 0x20) & 0xfffff);
                }

                if ((ecx_1 & 0x7ff) < 0x7ff || !eax_7)
                {
                    double xmm1_11 = _mm_xor_pd(xmm1_10, xmm1_10);
                    xmm1_10 = xmm1_11 / xmm1_11;
                    edx_2 = 9;
                }
                else
                    edx_2 = 0x3e9;
            }
            else
            {
                xmm1_10 = data_41c290;
                uint64_t xmm2_6[0x2] = *data_41c300;

                if (_mm_extract_epi16(
                        _mm_cmpeq_sd(xmm2_6, _mm_or_pd(_mm_and_pd(arg2, xmm1_10), xmm2_6), 0), 0))
                    return inf.0;

                edx_2 = 0x3e9;
            }

            goto label_41480d;
        }

        arg1 = xmm0_11 * 4503599627370496.0;
        edx = 0xffffffcc;
    }

    int32_t ecx_5 = (ecx_1 & 0xfff) - 0x3ff + edx;
    double xmm6_5[0x2] = ecx_5;
    double xmm6_6[0x2] = _mm_unpacklo_pd(xmm6_5, xmm6_5);
    void* const edx_1 = nullptr;

    if (!(eax_2 + (ecx_5 << 0xa)))
        edx_1 = 0x10;

    double xmm2_2[0x2] = data_41c360;
    double xmm1_3[0x2] = _mm_mul_pd(data_41c350, xmm0_5);
    double xmm3_3 = _mm_mul_pd(xmm0_5, xmm0_5);
    double xmm1_4[0x2] = _mm_add_pd(xmm1_3, xmm2_2);
    double xmm2_3[0x2] = data_41c370;
    double xmm6_7[0x2] = _mm_mul_pd(xmm6_6, data_41c2d0);
    uint64_t xmm4_5[0x2] = _mm_and_pd(xmm0_4, *(edx_1 + 0x41c2e0));
    double xmm7_4[0x2] = _mm_add_pd(_mm_add_pd(xmm7_1 + xmm6_4, xmm6_7), xmm4_5);
    double xmm1_6[0x2] = _mm_add_pd(_mm_mul_pd(xmm1_4, xmm0_5), xmm2_3);
    double xmm2_5[0x2] = _mm_mul_pd(data_41c380, xmm0_5);
    double xmm6_9 = _mm_unpackhi_pd(xmm7_4, xmm7_4);
    double xmm1_7[0x2] = _mm_mul_pd(xmm1_6, xmm3_3 * xmm3_3 * xmm0_5);
    double xmm1_8 = _mm_add_pd(xmm1_7, xmm2_5);
    var_c = _mm_unpackhi_pd(xmm1_7, xmm1_7) + xmm1_8 + xmm6_9 + xmm7_4;
    return var_c;
}

int32_t __fastcall sub_41486b(int16_t arg1, void* arg2 @ ebp, long double arg3 @ st0, long double arg4 @ st1)
{
    *(arg2 - 0x90) = 0xfe;
    *(&arg1 + 1) = *(&arg1 + 1);
    long double x87_r0;
    long double x87_r1;

    if (*(&arg1 + 1))
    {
        int32_t eax_2 = _isintTOS(arg3);

        if (!eax_2)
            /* tailcall */
            return sub_410180();

        *(&arg1 + 1) = 0;

        if (eax_2 != 2)
            *(&arg1 + 1) = 0xff;

        x87_r1 = arg3;
        x87_r0 = fabsl(arg4);
    }
    else
    {
        x87_r0 = arg4;
        x87_r1 = arg3;
    }

    long double st1;
    bool c1;
    st1 = __fyl2x(x87_r0, x87_r1);
    long double x87_r2;
    long double x87_r3;
    /* tailcall */
    return sub_41489d(arg2, x87_r2, x87_r3);
}

int32_t sub_414890(void* arg1 @ ebp, long double arg2 @ st0) __location("st0")
{
    *(arg1 - 0x90) = 0xfe;
    int32_t ecx;
    *(&ecx + 1) = 0;
    long double x87_r1;
    long double x87_r2;
    /* tailcall */
    return sub_41489d(arg1, x87_r1, x87_r2);
}

int32_t sub_41489d(void* arg1 @ ebp, long double arg2 @ st1, long double arg3 @ st2) __location("st0")
{
    int16_t ecx;
    int16_t ecx_1;
    char edx;
    long double x87_r0;
    ecx_1 = sub_4149cd(ecx, arg1, x87_r0);
    long double x87_r1 = arg2 + 1;

    if (*(arg1 - 0x9f) & 1)
    {
        long double x87_r0_2 = 1;
        x87_r1 = x87_r0_2 / x87_r0_2;
    }

    if (!(edx & 0x40))
    {
        long double st0_1;
        bool c1_1;
        st0_1 = __fscale(x87_r1, arg3);
        x87_r1 = st0_1;
    }

    *(&ecx_1 + 1) = *(&ecx_1 + 1);

    if (*(&ecx_1 + 1))
        x87_r1 = -(x87_r1);

    /* tailcall */
    return sub_410084(x87_r1);
}

long double j_sub_4100bd()
{
    /* tailcall */
    return sub_4100bd();
}

int32_t sub_4148e7(void* arg1 @ ebp) __location("st0")
{
    int80_t result = data_41c390;
    *(arg1 - 0x90) = 2;
    return result;
}

int32_t sub_414913(void* arg1 @ ebp) __location("st0")
{
    *(arg1 - 0x90) = 2;
    return data_41c39a;
}

int32_t __fastcall sub_414923(char arg1)
{
    void* ebp;

    if (arg1)
        /* tailcall */
        return sub_410182(arg1, ebp);
}

int80_t sub_414928() __location("st0")
{
    /* tailcall */
    return sub_41492e();
}

int80_t sub_41492c() __location("st0")
{
    /* tailcall */
    return sub_41492e();
}

long double j_sub_4100bd()
{
    /* tailcall */
    return sub_4100bd();
}

long double __fastcall sub_41493c(int16_t arg1, void* arg2 @ ebp)
{
    long double x87_r0;
    int32_t eax = _isintTOS(x87_r0);
    arg1 = arg1;
    long double result;

    if (arg1)
    {
        *(arg2 - 0x90) = 2;
        result = data_41c390;

        if (eax == 1)
        {
            *(&arg1 + 1) = *(&arg1 + 1);

            if (*(&arg1 + 1))
                return -(result);
        }
    }
    else
    {
        result = 0;

        if (eax == 1)
        {
            *(&arg1 + 1) = *(&arg1 + 1);

            if (*(&arg1 + 1))
                return -(result);
        }
    }

    return result;
}

int32_t sub_414978()
{
    char ecx;
    void* ebp;
    /* tailcall */
    return sub_410182(ecx, ebp);
}

int32_t sub_4149ae(void* arg1 @ ebp) __location("st0")
{
    int80_t result = data_41c390;
    *(arg1 - 0x90) = 3;
    return result;
}

int32_t __fastcall sub_4149c0(char arg1) __location("st0")
{
    if (arg1)
        /* tailcall */
        return sub_4100aa();

    return data_41c390;
}

void __fastcall sub_4149cd(int16_t arg1, void* arg2 @ ebp, long double arg3 @ st0)
{
    long double x87_r7 = fabsl(arg3);
    long double x87_r6 = data_41c3ae;
    x87_r6 - x87_r7;
    *(arg2 - 0xa0) = (x87_r6 < x87_r7 ? 1 : 0) << 8 | (FCMP_UO(x87_r6, x87_r7) ? 1 : 0) << 0xa
        | (x87_r6 == x87_r7 ? 1 : 0) << 0xe;

    if (*(arg2 - 0x9f) & 0x41)
    {
        long double temp1 = 0;
        arg3 - temp1;
        *(arg2 - 0xa0) = (arg3 < temp1 ? 1 : 0) << 8 | (FCMP_UO(arg3, temp1) ? 1 : 0) << 0xa
            | (arg3 == temp1 ? 1 : 0) << 0xe;

        if (*(arg2 - 0x9f) & 1)
        {
            *(arg2 - 0x90) = 4;
            /* tailcall */
            return sub_4100aa();
        }

        data_41c390;
        *(&arg1 + 1) = *(&arg1 + 1);
        return;
    }

    long double x87_r7_2 = roundl(arg3);
    long double temp2 = 0;
    x87_r7_2 - temp2;
    *(arg2 - 0xa0) = (x87_r7_2 < temp2 ? 1 : 0) << 8 | (FCMP_UO(x87_r7_2, temp2) ? 1 : 0) << 0xa
        | (x87_r7_2 == temp2 ? 1 : 0) << 0xe | 0x3800;
    int32_t edx;
    edx = *(arg2 - 0x9f);
    long double x87_r7_4 = arg3 - x87_r7_2;
    long double temp3 = 0;
    x87_r7_4 - temp3;
    *(arg2 - 0xa0) = (x87_r7_4 < temp3 ? 1 : 0) << 8 | (FCMP_UO(x87_r7_4, temp3) ? 1 : 0) << 0xa
        | (x87_r7_4 == temp3 ? 1 : 0) << 0xe | 0x3800;
    long double st0;
    bool c1;
    st0 = __f2xm1(fabsl(x87_r7_4));
}

int32_t _isintTOS(long double arg1 @ st0) __pure
{
    long double x87_r7 = roundl(arg1);
    x87_r7 - arg1;

    if (!TEST_BITB(
            *(&((x87_r7 < arg1 ? 1 : 0) << 8 | (FCMP_UO(x87_r7, arg1) ? 1 : 0) << 0xa
                | (x87_r7 == arg1 ? 1 : 0) << 0xe) + 1),
            6))
        return 0;

    long double x87_r7_2 = arg1 * 0.5;
    long double x87_r6_2 = roundl(x87_r7_2);
    x87_r6_2 - x87_r7_2;

    if (TEST_BITB(
            *(&((x87_r6_2 < x87_r7_2 ? 1 : 0) << 8 | (FCMP_UO(x87_r6_2, x87_r7_2) ? 1 : 0) << 0xa
                | (x87_r6_2 == x87_r7_2 ? 1 : 0) << 0xe) + 1),
            6))
        return 2;

    return 1;
}

long double sub_414a44(int16_t arg1 @ x87control, int16_t arg2 @ x87status, int16_t arg3 @ x87tag, long double arg4 @ st0, long double arg5 @ st1)
{
    int16_t x87control;
    int16_t x87status;
    int16_t x87tag;
    uint864_t temp0;
    temp0 = __fnsave_memmem108(arg1, arg3, arg2);
    double var_78;
    sub_414aa0(arg5, arg4, &var_78);
    __frstor_memmem108(temp0);
    return var_78;
}

long double __frnd(double arg1) __pure
{
    return roundl(arg1);
}

int32_t sub_414aa0(int64_t arg1, int32_t arg2, int32_t arg3, int64_t* arg4)
{
    double xmm0_1 = __andps_xmmxud_memxud(arg1, data_416ce0);
    double xmm1_1;

    if (!arg2)
    {
        if (arg3 == 0x7ff00000)
        {
            xmm1_1 = 1.0;

            if (!(xmm0_1 <= xmm1_1))
            {
                *arg4 = 0x7ff0000000000000;
                return 0;
            }

            if (!(xmm1_1 <= xmm0_1))
            {
                *arg4 = {0};
                return 0;
            }

            *arg4 = xmm1_1;
            return 0;
        }

        if (!arg2 && arg3 == 0xfff00000)
        {
            xmm1_1 = 1.0;

            if (!(xmm0_1 <= xmm1_1))
            {
                *arg4 = {0};
                return 0;
            }

            if (!(xmm1_1 <= xmm0_1))
            {
                *arg4 = 0x7ff0000000000000;
                return 0;
            }

            *arg4 = xmm1_1;
            return 0;
        }
    }

    int32_t ecx_1 = arg1;
    int32_t eax_8 = *(&arg1 + 4);

    if (ecx_1)
        return 0;

    if (eax_8 == 0x7ff00000)
    {
        double xmm1_2 = arg2;

        if (xmm1_2 > 0)
        {
            *arg4 = 0x7ff0000000000000;
            return 0;
        }

        if (!(0.0 > xmm1_2))
        {
            *arg4 = 0x3ff0000000000000;
            return 0;
        }

        *arg4 = {0};
        return 0;
    }

    if (ecx_1 || eax_8 != 0xfff00000)
        return 0;

    int16_t eax_11 = sub_414ca0(arg2);
    int32_t eax_12;

    if (eax_11 & 0x90)
        eax_12 = 0;
    else
    {
        double xmm1_3 = arg2;
        double var_c_1 = __frnd(arg2);
        var_c_1 - xmm1_3;
        *(&eax_11 + 1) = (var_c_1 == xmm1_3 ? 1 : 0) << 6 | (FCMP_UO(var_c_1, xmm1_3) ? 1 : 0) << 2
            | (var_c_1 < xmm1_3 ? 1 : 0);

        if (!(__builtin_popcount(*(&eax_11 + 1) & 0x44) & 1))
            eax_12 = 0;
        else
        {
            double xmm0_10 = xmm1_3 * 0.5;
            double var_c_2 = __frnd(xmm0_10);
            var_c_2 - xmm0_10;
            *(&eax_11 + 1) = (var_c_2 == xmm0_10 ? 1 : 0) << 6
                | (FCMP_UO(var_c_2, xmm0_10) ? 1 : 0) << 2 | (var_c_2 < xmm0_10 ? 1 : 0);

            eax_12 = !(__builtin_popcount(*(&eax_11 + 1) & 0x44) & 1) ? 1 : 2;
        }
    }

    int64_t xmm0_12 = arg2;
    xmm1_1 = {0};
    int64_t xmm0_4;

    if (xmm0_12 <= 0)
    {
        if (!(0 <= xmm0_12))
        {
            if (eax_12 == 1)
                xmm1_1 = -0.0;

            *arg4 = xmm1_1;
            return 0;
        }

        xmm0_4 = 0x3ff0000000000000;
    }
    else
    {
        xmm0_4 = 0x7ff0000000000000;

        if (eax_12 == 1)
        {
            *arg4 = xmm0_4 ^ data_416fc0;
            return 0;
        }
    }

    *arg4 = xmm0_4;
    return 0;
}

int32_t sub_414ca0(double arg1, int32_t arg2 @ 0x8)
{
    int32_t eax_1 = arg2 & 0x7ff00000;

    if (eax_1 == 0x7ff00000)
    {
        int32_t eax_2 = sub_40c6f0(arg1);

        if (eax_2 == 1)
            return 0x200;

        if (eax_2 == 2)
            return 4;

        if (eax_2 == 3)
            return 2;

        return 1;
    }

    int32_t ecx_1 = *(&arg2 + 2) & 0x8000;

    if (!eax_1)
    {
        eax_1 = arg1 | (arg2 & 0xfffff);

        if (eax_1)
        {
            if (ecx_1)
                return 0x10;

            return 0x80;
        }
    }

    arg1 - 0.0;
    *(&eax_1 + 1) =
        (arg1 == 0.0 ? 1 : 0) << 6 | (FCMP_UO(arg1, 0.0) ? 1 : 0) << 2 | (arg1 < 0.0 ? 1 : 0);

    if (!(__builtin_popcount(*(&eax_1 + 1) & 0x44) & 1))
    {
        if (ecx_1)
            return 8;

        return 0x100;
    }

    if (ecx_1)
        return 0x20;

    return 0x40;
}

void* __FindPESection(void* arg1, int32_t arg2)
{
    int32_t edx = 0;
    void* ecx_1 = *(arg1 + 0x3c) + arg1;
    uint32_t ebx = *(ecx_1 + 6);
    void* result = *(ecx_1 + 0x14) + 0x18 + ecx_1;

    if (ebx)
    {
        do
        {
            int32_t esi_1 = *(result + 0xc);

            if (arg2 >= esi_1 && arg2 < *(result + 8) + esi_1)
                return result;

            edx += 1;
            result += 0x28;
        } while (edx < ebx);
    }

    return nullptr;
}

int32_t __IsNonwritableInCurrentImage(int32_t arg1)
{
    int32_t var_8 = 0xfffffffe;
    int32_t var_c = 0x41cf40;
    int32_t (* var_10)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_c_1 = var_c ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_2c = __security_cookie_1 ^ &__saved_ebp;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t* var_1c = &var_2c;
    int32_t var_8_1 = 0;

    if (__ValidateImageBase(&__dos_header))
    {
        void* eax_5 = __FindPESection(&__dos_header, arg1 - &__dos_header);

        if (eax_5)
        {
            int32_t result = ~(*(eax_5 + 0x24) >> 0x1f) & 1;
            int32_t var_8_2 = 0xfffffffe;
            fsbase->NtTib.ExceptionList = ExceptionList;
            return result;
        }
    }

    int32_t var_8_3 = 0xfffffffe;
    fsbase->NtTib.ExceptionList = ExceptionList;
    return 0;
}

int32_t sub_414e49(void* arg1 @ ebp)
{
    int32_t result = 0;
    result = ***(arg1 - 0x14) == 0xc0000005;
    return result;
}

int32_t __ValidateImageBase(int16_t* arg1)
{
    if (*arg1 == 0x5a4d)
    {
        int32_t* ecx_2 = *(arg1 + 0x3c) + arg1;

        if (*ecx_2 == 0x4550)
        {
            int32_t result = 0;
            result = ecx_2[6] == 0x10b;
            return result;
        }
    }

    return 0;
}

struct type_info::VTable** __thiscall sub_414ec0(struct type_info::VTable** arg1, char arg2)
{
    *arg1 = &type_info::`vftable';

    if (arg2 & 1)
    {
        int32_t var_c_1 = 0xc;
        sub_414ef0(arg1);
    }

    return arg1;
}

int32_t sub_414ef0(int32_t arg1)
{
    return j_j___free_base(arg1);
}

void __SEH_prolog4(int32_t arg1 @ esi, int32_t arg2 @ edi, void* arg3)
{
    int32_t (* var_4)(int32_t* arg1, void* arg2, void* arg3) = sub_403ce0;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t arg_8;
    int32_t eax = arg_8;
    int32_t ebp;
    arg_8 = ebp;
    void* esp = &ExceptionList - eax;
    int32_t entry_ebx;
    *(esp - 4) = entry_ebx;
    *(esp - 8) = arg1;
    *(esp - 0xc) = arg2;
    uint32_t __security_cookie_1 = __security_cookie;
    *(esp - 0x10) = __security_cookie_1 ^ &arg_8;
    void* var_10 = esp - 0x10;
    *(esp - 0x14) = __return_addr;
    void* __return_addr_1 = arg3 ^ __security_cookie_1;
    arg3 = 0xfffffffe;
    __return_addr = __return_addr_1;
    fsbase->NtTib.ExceptionList = &ExceptionList;
}

uint32_t __stdcall __aulldvrm(int32_t arg1, uint32_t arg2, int32_t arg3, uint32_t arg4) __pure
{
    uint32_t result;

    if (arg4)
    {
        uint32_t i = arg4;
        int32_t ebx_1 = arg3;
        uint32_t edx_4 = arg2;
        int32_t eax_10 = arg1;

        do
        {
            ebx_1 = RRCD(ebx_1, 1, i & 1);
            uint32_t temp4_1 = edx_4;
            edx_4 u>>= 1;
            eax_10 = RRCD(eax_10, 1, temp4_1 & 1);
            i u>>= 1;
        } while (i);

        uint32_t result_1 = COMBINE(edx_4, eax_10) / ebx_1;
        result = result_1;
        int32_t eax_12 = result_1 * arg4;
        int32_t eax_9;
        int32_t edx_5;
        edx_5 = HIGHD(arg3 * result);
        eax_9 = LOWD(arg3 * result);
        int32_t edx_3 = edx_5 + eax_12;

        if (edx_5 + eax_12 < edx_5 || edx_3 > arg2)
            result -= 1;
        else if (edx_3 >= arg2 && eax_9 > arg1)
            result -= 1;
    }
    else
        result = COMBINE(COMBINE(0, arg2) % arg3, arg1) / arg3;

    return result;
}

uint32_t __stdcall __alldiv(int32_t arg1, uint32_t arg2, int32_t arg3, uint32_t arg4) __pure
{
    int32_t edi = 0;

    if (arg2 < 0)
    {
        edi = 1;
        arg2 = -(arg2) - 0;
        arg1 = -(arg1);
    }

    uint32_t i_1 = arg4;

    if (i_1 < 0)
    {
        edi += 1;
        i_1 = -(i_1) - 0;
        arg4 = i_1;
        arg3 = -(arg3);
    }

    uint32_t result;

    if (i_1)
    {
        uint32_t i = i_1;
        int32_t ecx_1 = arg3;
        uint32_t edx_8 = arg2;
        int32_t eax_10 = arg1;

        do
        {
            ecx_1 = RRCD(ecx_1, 1, i & 1);
            uint32_t temp6_1 = edx_8;
            edx_8 u>>= 1;
            eax_10 = RRCD(eax_10, 1, temp6_1 & 1);
            i u>>= 1;
        } while (i);

        uint32_t result_2 = COMBINE(edx_8, eax_10) / ecx_1;
        uint32_t result_1 = result_2;
        int32_t eax_12 = result_2 * arg4;
        int32_t eax_14;
        int32_t edx_9;
        edx_9 = HIGHD(arg3 * result_1);
        eax_14 = LOWD(arg3 * result_1);
        int32_t edx_10 = edx_9 + eax_12;

        if (edx_9 + eax_12 < edx_9 || edx_10 > arg2)
            result_1 -= 1;
        else if (edx_10 >= arg2 && eax_14 > arg1)
            result_1 -= 1;

        result = result_1;
    }
    else
        result = COMBINE(COMBINE(0, arg2) % arg3, arg1) / arg3;

    if (edi == 1)
        result = -(result);

    return result;
}

uint32_t __stdcall __alldvrm(int32_t arg1, uint32_t arg2, int32_t arg3, uint32_t arg4) __pure
{
    int32_t edi = 0;

    if (arg2 < 0)
    {
        edi = 1;
        arg2 = -(arg2) - 0;
        arg1 = -(arg1);
    }

    uint32_t i_1 = arg4;

    if (i_1 < 0)
    {
        edi += 1;
        i_1 = -(i_1) - 0;
        arg4 = i_1;
        arg3 = -(arg3);
    }

    uint32_t result_1;

    if (i_1)
    {
        uint32_t i = i_1;
        int32_t ecx_2 = arg3;
        uint32_t edx_9 = arg2;
        int32_t eax_15 = arg1;

        do
        {
            ecx_2 = RRCD(ecx_2, 1, i & 1);
            uint32_t temp6_1 = edx_9;
            edx_9 u>>= 1;
            eax_15 = RRCD(eax_15, 1, temp6_1 & 1);
            i u>>= 1;
        } while (i);

        uint32_t result_2 = COMBINE(edx_9, eax_15) / ecx_2;
        result_1 = result_2;
        int32_t eax_17 = result_2 * arg4;
        int32_t eax_14;
        int32_t edx_10;
        edx_10 = HIGHD(arg3 * result_1);
        eax_14 = LOWD(arg3 * result_1);
        int32_t edx_8 = edx_10 + eax_17;

        if (edx_10 + eax_17 < edx_10 || edx_8 > arg2)
            result_1 -= 1;
        else if (edx_8 >= arg2 && eax_14 > arg1)
            result_1 -= 1;
    }
    else
        result_1 = COMBINE(COMBINE(0, arg2) % arg3, arg1) / arg3;

    uint32_t result = result_1;

    if (edi == 1)
        result = -(result);

    return result;
}

int32_t sub_415180(int32_t* arg1 @ ebp, int32_t arg2 @ 0x8, int32_t arg3, int32_t arg4)
{
    TEB* fsbase;
    fsbase->NtTib.ExceptionList = arg1[-3];
    *arg1;
    *arg1 = __return_addr;
}

void __EH_prolog3(int32_t arg1 @ esi, int32_t arg2 @ edi)
{
    int32_t eax;
    int32_t var_4 = eax;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t arg_4;
    void* esp = &ExceptionList - arg_4;
    int32_t entry_ebx;
    *(esp - 4) = entry_ebx;
    *(esp - 8) = arg1;
    *(esp - 0xc) = arg2;
    int32_t ebp;
    arg_4 = ebp;
    *(esp - 0x10) = __security_cookie ^ &arg_4;
    *(esp - 0x14) = __return_addr;
    __return_addr = 0xffffffff;
    fsbase->NtTib.ExceptionList = &ExceptionList;
}

int32_t __stdcall __allmul(int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4) __pure
{
    if (!(arg4 | arg2))
        return arg1 * arg3;

    int32_t result;
    int32_t edx;
    edx = HIGHD(arg1 * arg3);
    result = LOWD(arg1 * arg3);
    return result;
}

uint32_t __stdcall __aulldiv(int32_t arg1, uint32_t arg2, int32_t arg3, uint32_t arg4) __pure
{
    if (!arg4)
        return COMBINE(COMBINE(0, arg2) % arg3, arg1) / arg3;

    uint32_t i = arg4;
    int32_t ebx_1 = arg3;
    uint32_t edx_3 = arg2;
    int32_t eax_6 = arg1;

    do
    {
        ebx_1 = RRCD(ebx_1, 1, i & 1);
        uint32_t temp4_1 = edx_3;
        edx_3 u>>= 1;
        eax_6 = RRCD(eax_6, 1, temp4_1 & 1);
        i u>>= 1;
    } while (i);

    uint32_t result = COMBINE(edx_3, eax_6) / ebx_1;
    int32_t eax_8 = result * arg4;
    int32_t eax_10;
    int32_t edx_4;
    edx_4 = HIGHD(arg3 * result);
    eax_10 = LOWD(arg3 * result);
    int32_t edx_5 = edx_4 + eax_8;

    if (edx_4 + eax_8 >= edx_4 && edx_5 <= arg2 && (edx_5 < arg2 || eax_10 <= arg1))
        return result;

    return result - 1;
}

uint32_t __stdcall __allrem(int32_t arg1, uint32_t arg2, int32_t arg3, uint32_t arg4) __pure
{
    int32_t edi = 0;

    if (arg2 < 0)
    {
        edi = 1;
        arg2 = -(arg2) - 0;
        arg1 = -(arg1);
    }

    uint32_t i_1 = arg4;

    if (i_1 < 0)
    {
        i_1 = -(i_1) - 0;
        arg4 = i_1;
        arg3 = -(arg3);
    }

    uint32_t result;

    if (i_1)
    {
        uint32_t i = i_1;
        int32_t ecx_1 = arg3;
        uint32_t edx_9 = arg2;
        int32_t eax_9 = arg1;

        do
        {
            ecx_1 = RRCD(ecx_1, 1, i & 1);
            uint32_t temp7_1 = edx_9;
            edx_9 u>>= 1;
            eax_9 = RRCD(eax_9, 1, temp7_1 & 1);
            i u>>= 1;
        } while (i);

        uint32_t temp0_3 = COMBINE(edx_9, eax_9) / ecx_1;
        int32_t eax_11 = temp0_3 * arg4;
        int32_t eax_13;
        int32_t edx_10;
        edx_10 = HIGHD(temp0_3 * arg3);
        eax_13 = LOWD(temp0_3 * arg3);
        int32_t edx_11 = edx_10 + eax_11;

        if (edx_10 + eax_11 < edx_10 || edx_11 > arg2)
            eax_13 -= arg3;
        else if (edx_11 >= arg2 && eax_13 > arg1)
            eax_13 -= arg3;

        result = eax_13 - arg1;

        if (edi - 1 < 0)
            result = -(result);
    }
    else
    {
        result = COMBINE(COMBINE(0, arg2) % arg3, arg1) % arg3;

        if (edi - 1 >= 0)
            result = -(result);
    }

    return result;
}

void __convention("regparm") __aullshr(int32_t arg1, int32_t arg2, char arg3) __pure
{
    return;
}

int32_t __convention("regparm") __allshl(int32_t arg1, int32_t arg2, char arg3) __pure
{
    if (arg3 >= 0x40)
        return 0;

    if (arg3 >= 0x20)
        return 0;

    return arg1 << (arg3 & 0x1f);
}

int32_t __convention("regparm") __alloca_probe_16(void* arg1)
{
    void arg_4;
    void* ecx_1 = (&arg_4 - arg1) & 0xf;
    /* tailcall */
    return sub_415440((arg1 + ecx_1) | (ecx_1 - ecx_1));
}

int32_t __convention("regparm") sub_4153a6(void* arg1)
{
    void arg_4;
    void* ecx_1 = (&arg_4 - arg1) & 7;
    /* tailcall */
    return sub_415440((arg1 + ecx_1) | (ecx_1 - ecx_1));
}

uint32_t __stdcall __aullrem(int32_t arg1, uint32_t arg2, int32_t arg3, uint32_t arg4) __pure
{
    uint32_t result;

    if (arg4)
    {
        uint32_t i = arg4;
        int32_t ebx_1 = arg3;
        uint32_t edx_4 = arg2;
        int32_t eax_4 = arg1;

        do
        {
            ebx_1 = RRCD(ebx_1, 1, i & 1);
            uint32_t temp4_1 = edx_4;
            edx_4 u>>= 1;
            eax_4 = RRCD(eax_4, 1, temp4_1 & 1);
            i u>>= 1;
        } while (i);

        uint32_t temp0_3 = COMBINE(edx_4, eax_4) / ebx_1;
        int32_t eax_6 = temp0_3 * arg4;
        int32_t eax_8;
        int32_t edx_5;
        edx_5 = HIGHD(temp0_3 * arg3);
        eax_8 = LOWD(temp0_3 * arg3);
        int32_t edx_6 = edx_5 + eax_6;

        if (edx_5 + eax_6 < edx_5 || edx_6 > arg2)
            eax_8 -= arg3;
        else if (edx_6 >= arg2 && eax_8 > arg1)
            eax_8 -= arg3;

        result = -((eax_8 - arg1));
    }
    else
        result = COMBINE(COMBINE(0, arg2) % arg3, arg1) % arg3;

    return result;
}

void* const __convention("regparm") sub_415440(int32_t arg1)
{
    void** ecx_1 = (&__return_addr - arg1) & ~(arg1 - arg1);
    int32_t __saved_ecx;
    void* eax_2 = &__saved_ecx & 0xfffff000;

    while (ecx_1 < eax_2)
    {
        eax_2 -= 0x1000;
        *eax_2;
    }

    void* const result = __return_addr;
    *ecx_1 = result;
    return result;
}

void j_j___free_base(int32_t arg1)
{
    /* tailcall */
    return j___free_base(arg1);
}

char* _strrchr(char* arg1, char arg2)
{
    int32_t temp0 = data_41eae8;

    if (temp0 < 1)
    {
        char* edi_2 = arg1;
        int32_t i = 0xffffffff;

        while (i)
        {
            bool cond:0_1 = 0 != *edi_2;
            edi_2 = &edi_2[1];
            i -= 1;

            if (!cond:0_1)
                break;
        }

        int32_t i_1 = -((i + 1));
        void* edi_3 = edi_2 - 1;

        while (i_1)
        {
            bool cond:1_1 = arg2 != *edi_3;
            edi_3 -= 1;
            i_1 -= 1;

            if (!cond:1_1)
                break;
        }

        if (*(edi_3 + 1) == arg2)
            return edi_3 + 1;

        return nullptr;
    }

    char* i_4 = arg1;

    if (temp0 <= 1)
    {
        uint32_t edx = arg2;
        int64_t xmm3_1 = _mm_shufflelo_epi16(edx << 8 | edx, 0);
        void* ecx_1 = 0xf & i_4;
        int32_t eax_1 = 0xffffffff << (ecx_1 & 0x1f);
        int128_t* edi = i_4 - ecx_1;
        void* edx_3 = nullptr;
        int32_t ecx_3;
        char xmm1_2[0x10];

        while (true)
        {
            char xmm1_1[0x10] = *edi;
            char xmm2_1[0x10] = _mm_cmpeq_epi8({0}, xmm1_1);
            xmm1_2 = _mm_cmpeq_epi8(xmm1_1, xmm3_1 | xmm3_1 << 0x40);
            ecx_3 = _mm_movemask_epi8(xmm2_1) & eax_1;

            if (ecx_3)
                break;

            int32_t ecx_5 = _mm_movemask_epi8(xmm1_2) & eax_1;
            int32_t eflags_1;
            void* eax_2;
            eax_2 = _bit_scan_reverse(ecx_5);

            if (ecx_5)
                edx_3 = eax_2 + edi;

            eax_1 = 0xffffffff;
            edi = &edi[1];
        }

        int32_t ecx_6 = ecx_3 << 1;
        int32_t ecx_9 = ((ecx_6 & (0 - ecx_6)) - 1) & _mm_movemask_epi8(xmm1_2) & eax_1;
        int32_t eflags_2;
        void* eax_5;
        eax_5 = _bit_scan_reverse(ecx_9);

        if (!ecx_9)
            return edx_3;

        return eax_5 + edi;
    }

    uint32_t edx_4 = arg2;

    if (!edx_4)
    {
        char (* eax_7)[0x10] = 0xfffffff0 & i_4;
        uint32_t i_2;
        char xmm0_3[0x10];

        for (i_2 =
            _mm_movemask_epi8(__pcmpeqb_xmmdq_memdq({0}, *eax_7)) & 0xffffffff << (i_4 & 0xf); !i_2;
            i_2 = _mm_movemask_epi8(xmm0_3))
        {
            xmm0_3 = __pcmpeqb_xmmdq_memdq({0}, eax_7[1]);
            eax_7 = &eax_7[1];
        }

        int32_t eflags_4;
        int32_t edx_6;
        edx_6 = _bit_scan_forward(i_2);
        return &(*eax_7)[edx_6];
    }

    char* i_5 = nullptr;

    while (i_4 & 0xf)
    {
        uint32_t ecx_10 = *i_4;

        if (ecx_10 == edx_4)
            i_5 = i_4;

        if (!ecx_10)
            return i_5;

        i_4 = &i_4[1];
    }

    char* i_3;

    do
    {
        i_3 = i_4;
        i_4 = &i_4[0x10];
        int32_t eflags_3;
        int32_t ecx_11;
        ecx_11 = __pcmpistri_xmmdq_memdq_immb(edx_4, *(i_4 - 0x10), 0x40);

        if (i_3 < 0xfffffff0)
            i_5 = &i_4[ecx_11 - 0x10];
    } while (i_3 != 0xfffffff0);
    return i_5;
}

int32_t sub_4155c0(int32_t arg1 @ mxcsr, int32_t arg2)
{
    int32_t ecx;
    int32_t var_8 = ecx;

    if (data_41eae8 >= 1 && (arg2 == 0xc00002b4 || arg2 == 0xc00002b5))
    {
        int32_t eax_2 = arg1 ^ 0x3f;

        if (!(eax_2 & 0x81))
            return 0xc0000090;

        if (!(eax_2 & 0x204))
            return 0xc000008e;

        if (!(eax_2 & 0x102))
            return 0xc0000090;

        if (!(eax_2 & 0x408))
            return 0xc0000091;

        if (!(eax_2 & 0x810))
            return 0xc0000093;

        if (!(eax_2 & 0x1020))
            return 0xc000008f;
    }

    return arg2;
}

int32_t sub_415650(void* arg1 @ 0x8)
{
    sub_402910(*(arg1 - 0x14) ^ (arg1 + 0xc));
    /* tailcall */
    return sub_404920(0x41ca7c);
}

int32_t sub_41566d(void* arg1 @ 0x8)
{
    sub_402910(*(arg1 - 0x34) ^ (arg1 + 0xc));
    sub_402910(*(arg1 - 4) ^ (arg1 + 0xc));
    /* tailcall */
    return sub_404920(0x41cb38);
}

int32_t sub_415694(void* arg1 @ 0x8)
{
    sub_402910(*(arg1 - 0x10) ^ (arg1 + 0xc));
    /* tailcall */
    return sub_404920(0x41cb6c);
}

int32_t sub_4156b1(void* arg1 @ 0x8)
{
    sub_402910(*(arg1 - 0x1c) ^ (arg1 + 0xc));
    /* tailcall */
    return sub_404920(0x41cb38);
}

int32_t sub_4156ce(void* arg1 @ 0x8)
{
    sub_402910(*(arg1 - 0xc) ^ (arg1 + 0xc));
    /* tailcall */
    return sub_404920(0x41cb90);
}

int32_t sub_4156eb(void* arg1 @ 0x8)
{
    sub_402910(*(arg1 - 0x20) ^ (arg1 + 0xc));
    /* tailcall */
    return sub_404920(0x41cc1c);
}

int32_t sub_415708(void* arg1 @ 0x8)
{
    sub_402910(*(arg1 - 0x10) ^ (arg1 + 0xc));
    /* tailcall */
    return sub_404920(0x41cc1c);
}

int32_t sub_415725(void* arg1 @ 0x8)
{
    sub_402910(*(arg1 - 0x80) ^ (arg1 + 0xc));
    sub_402910(*(arg1 - 4) ^ (arg1 + 0xc));
    /* tailcall */
    return sub_404920(0x41cb90);
}

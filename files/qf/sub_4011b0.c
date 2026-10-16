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

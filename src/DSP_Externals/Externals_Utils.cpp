// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
    // by Boguœ
    template<typename T>
    int Ext_ReadStatArray()
    {
        auto const par = zCParser::GetParser();
        int idx; par->GetParameter(idx);
        static T ele; ele = T{};
        if (idx < 0)
        {
            par->SetReturn(ele);
            return 0;
        }
        const auto array = reinterpret_cast<T*>(par->PopVarAddress());
        if (array)
            ele = array[idx];
        par->SetReturn(ele);
        return 0;
    }

    // by Boguœ
    template<typename T>
    int Ext_WriteStatArray()
    {
        auto const par = zCParser::GetParser();
        T value; par->GetParameter(value);
        int idx; par->GetParameter(idx);
        if (idx < 0) return 0;
        auto array = reinterpret_cast<T*>(par->PopVarAddress());
        if (array)
            array[idx] = value;
        return 0;
    }
}
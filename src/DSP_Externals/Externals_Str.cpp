// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
    int Str_Upper()
    {
        static zSTRING result = "";
        auto const par = zCParser::GetParser();
        zSTRING str;
        par->GetParameter(str);
        result = (zSTRING&)str.Upper();
        par->SetReturn(result);
        return 0;
    }

    int Str_Lower()
    {
        static zSTRING result = "";
        auto const par = zCParser::GetParser();
        zSTRING str;
        par->GetParameter(str);
        result = (zSTRING&)str.Lower();
        par->SetReturn(result);
        return 0;
    }

    int Str_Capitel()
    {
        static zSTRING result = "";
        auto const par = zCParser::GetParser();
        zSTRING str;
        par->GetParameter(str);
        result = (zSTRING&)str.UpperFirstLowerRest();
        par->SetReturn(result);
        return 0;
    }
}
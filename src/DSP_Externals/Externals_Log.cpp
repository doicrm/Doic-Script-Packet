// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
    int Log_GetTopicStatus()
    {
        auto const par = zCParser::GetParser();
        zSTRING value;
        par->GetParameter(value);
        oCLogManager& logs = oCLogManager::GetLogManager();

        auto* list = &logs.m_lstTopics;
        while (list)
        {
            auto const topic = list->GetData();
            if (topic && topic->m_strDescription == value)
            {
                par->SetReturn(topic->m_enuStatus);
                return 0;
            }
            list = list->GetNextInList();
        }

        par->SetReturn(static_cast<int>(oCLogTopic::zELogTopicStatus_Free));
        return 0;
    }
}
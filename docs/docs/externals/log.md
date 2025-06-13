# Log functions

## Log_GetTopicStatus

Returns the status of diary topic.

- `0` - Free
- `1` - Running
- `2` - Success
- `3` - Failure
- `4` - Obsolete

```dae
func int Log_GetTopicStatus(var string topic) {};
```

- `topic` - name of the topic
- `return` - topic status

```dae title="Example usage"
if (Log_GetTopicStatus(TOPIC_InnosEye) == LOG_SUCCESS)
{
    //...
};
```

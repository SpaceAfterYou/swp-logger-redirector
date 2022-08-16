namespace swp_logger_redirector
{
	void logs(void* _this, unsigned int level, char* format, ...)
	{
		if (NULL == format) return;

		va_list args;
		va_start(args, format);

		char buffer[4096]{};
		vsprintf_s(buffer, sizeof(buffer), format, args);

		spdlog::info(buffer);
	}
}

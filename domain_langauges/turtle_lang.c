typedef struct {
	char 	cmd;		/* the command letter */
	int	hasArg;		/* does it take an argument */
	void (*func)(int, int); /* routine to call */
} Command;

static Command cmds[] = {
	{'P', ARG,	doSelectPen },
	{'U', NO_ARG,	doPenUp },
	{'D', ARG,	doPenDown },
	{'N', ARG,	doPenDir },
	{'S', ARG,	doPenDir },		
	{'E', ARG,	doPenDir },		
	{'W', ARG,	doPenDir }		
};

Command *findCommand(int cmd) {
	int i;
	for (i = 0; i < ARRAY_SIZE(cmds); i++) {
		if (cmds[i].cmd == cmd) {
			return cmds + i;
		}
	}
	fprintf(stderr, "Unknown command '%c'\n", cmd);
	return 0;
}

int getArg(const char *buff, int *result) {
	return sscanf(buff, "%d", result) == 1
}

void main() {
	while (fgets(buff, sizeof(buff), stdin)) {
		
		Command *cmd = findCommand(*buff);

		if (cmd) {
			int arg = 0;
			if (cmd->hadArg && !getArg(buff+1, &arg)) {
				fprintf(stderr, "'%c' needs an argument\n", *buff);
				continue;
			}

			cmd->func(*buff, arg);
		}
	}
}

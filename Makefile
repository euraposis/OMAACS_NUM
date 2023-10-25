all:
	@$(MAKE) -C OMAACS_NUM tests

tests_show_fails:
	@$(MAKE) -C OMAACS_NUM tests | grep "FAIL"
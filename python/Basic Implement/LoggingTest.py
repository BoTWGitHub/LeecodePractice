import logging

class CustomFormatter(logging.Formatter):
    """Logging colored formatter, adapted from https://stackoverflow.com/a/56944256/3638629"""

    grey = '\x1b[38;21m'
    blue = '\x1b[38;5;39m'
    yellow = '\x1b[38;5;226m'
    red = '\x1b[38;5;196m'
    bold_red = '\x1b[31;1m'
    reset = '\x1b[0m'

    def __init__(self, fmt):
        super().__init__()
        self.fmt = fmt
        self.FORMATS = {
            logging.DEBUG: self.grey + self.fmt + self.reset,
            logging.INFO: self.blue + self.fmt + self.reset,
            logging.WARNING: self.yellow + self.fmt + self.reset,
            logging.ERROR: self.red + self.fmt + self.reset,
            logging.CRITICAL: self.bold_red + self.fmt + self.reset
        }

    def format(self, record):
        log_fmt = self.FORMATS.get(record.levelno)
        formatter = logging.Formatter(log_fmt)
        return formatter.format(record)

def main():
    test_logger: logging.Logger = logging.getLogger('test')
    test_logger.setLevel(logging.DEBUG)
    
    handler: logging.StreamHandler = logging.StreamHandler()
    handler.setFormatter(CustomFormatter('%(levelname)s:   %(asctime)s - %(name)s - %(message)s'))
    test_logger.addHandler(handler)
    
    test_logger.debug('debug msg')
    test_logger.info('info msg')
    test_logger.warning('warning msg')
    test_logger.error('error msg')
    test_logger.critical('debug msg')

if __name__=='__main__':
    main()
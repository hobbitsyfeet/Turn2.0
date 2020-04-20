
    #Helper Functions
def parse_input(filename, first_line=False):
    file = open(filename, 'r')
    
    if first_line is False:
        next(file) #skip first line. This is used for user

    parsed_lines = []

    lines = [line.rstrip() for line in file]
    for line in lines:

        #get rid of repeating tabs
        while "\t\t" in line:
            line = line.replace("\t\t", "\t")

        #split by single tabs into a list
        line = line.split('\t')

    
        parsed_lines.append(line)
    return parsed_lines
    
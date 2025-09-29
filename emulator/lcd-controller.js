
class LcdController {

    constructor(lcd) {
        this.input_states = {
            start: 1,
            write_text: 2,
            write_character: 3,
            set_cursor: 4,
            create_custom_character: 5,
            set_blink: 6,
        }

        this.lcd = lcd
        this.cursor_col = 0
        this.cursor_row = 0
        this.state = this.input_states.start
        this.parameters = []
    }


    //select wich command to process
    process_start(data) {
        switch (data) {
            //clear
            case 0x81:
                this.lcd.clear()
                break;
            //write text
            case 0x82:
                this.state = this.input_states.write_text
                break;
            //write character
            case 0x83:
                this.state = this.input_states.write_character
                break;
            //set cursor
            case 0x84:
                this.state = this.input_states.set_cursor
                this.parameters = []
                break;
            //create custom character
            case 0x85:
                this.state = this.input_states.create_custom_character
                this.parameters = []
                break;
            //set blink
            case 0x86:
                this.state = this.input_states.set_blink
                break;

            default:
                console.warn("unknown command or in bad state: " + data)
                break;
        }
    }

    //write data to lcd until \0 is received 
    process_write_text(data) {
        if (data == 0) {
            this.state = this.input_states.start
        } else {
            this.lcd.char(this.cursor_row, this.cursor_col, String.fromCharCode(data))
            this.cursor_col += 1;
        }
    }

    //write single character to lcd and advance cursor to the right
    process_write_character(data) {
        this.lcd.char(this.cursor_row, this.cursor_col, String.fromCharCode(data))
        this.cursor_col += 1;
        this.state = this.input_states.start
    }

    //set the cursor to the position
    process_set_cursor(data) {
        if (this.parameters.length == 1) {
            this.cursor_row = this.parameters[0]
            this.cursor_col = data
            this.state = this.input_states.start
        } else {
            this.parameters.push(data)
        }
    }

    //create a custom character
    process_create_custom_character(data) {
        if (this.parameters.length == 8) {
            this.parameters.push(data)
            this.lcd.font(this.parameters[0], this.parameters.slice(1, 9))
            this.state = this.input_states.start
        } else {
            this.parameters.push(data)
        }

    }

    //set if the cursor should blink
    process_set_blink(data) {
        console.log("TODO: blink " + data)
        this.state = this.input_states.start
    }


    process(data) {
        switch (this.state) {
            case this.input_states.start:
                this.process_start(data)
                break;
            case this.input_states.write_text:
                this.process_write_text(data)
                break;
            case this.input_states.write_character:
                this.process_write_character(data)
                break;
            case this.input_states.set_cursor:
                this.process_set_cursor(data)
                break;
            case this.input_states.create_custom_character:
                this.process_create_custom_character(data)
                break;
            case this.input_states.set_blink:
                this.process_set_blink(data)
                break;

            default:
                break;
        }
    }

}
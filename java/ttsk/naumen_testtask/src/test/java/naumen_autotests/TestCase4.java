package naumen_autotests;

/**
 * Created by az on 27.01.16.
 */

import static org.junit.Assert.assertThat;
import static org.hamcrest.CoreMatchers.equalTo;
import static org.hamcrest.core.IsNot.not;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class TestCase4 {

    private ContactPage page;

    @Before
    public void setUp() {
        page = new ContactPage();
    }

    @Test
    public void runCase() {
        String new_date = "Test123";

        page.getElementByRow(0).click();
        page.setInputDate(new_date);
        page.updateContactClick();
        page.getElementByRow(1).click();
        page.getElementByRow(0).click();
        assertThat(page.getFormDate(), not(equalTo(new_date)));

    }

    @After
    public void afterTests() {
        page.quit();
    }
}


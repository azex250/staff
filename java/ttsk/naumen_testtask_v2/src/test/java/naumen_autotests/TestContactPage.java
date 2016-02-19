package naumen_autotests;

/**
 * Created by az on 30.01.16.
 */

import naumen_autotests.pages.ContactPage;
import static org.junit.Assert.assertTrue;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class TestContactPage {
    private ContactPage page;

    @Before
    public void setUp() {
        page = new ContactPage();
    }

    @Test
    public void createNewContact() {
        String first_name = "Mr.";
        String last_name = "Smith";
        String birth = "January 20, 2016";
        String address = "Far far away";
        String expexted_name = first_name + " " + last_name;

        page.setInputFirstName(first_name);
        page.setInputLastName(last_name);
        page.setInputDate(birth);
        page.setInputAddress(address);
        page.createContactClick();
        page.scrollListToBottom();

        assertTrue("Create contact: Expectet that the last contact will is the new one",
                page.getElementNameByRow(page.getContactCount() - 1).equals(expexted_name));
    }

    @Test
    public void scrollDownListLoad() {
        int expected_bottom_border = page.getShownContactCount() + 20;
        page.scrollList();
        int bottom_border_after_scroll = page.getShownContactCount();

        assertTrue("Scroll down: Expected to load new 20 contacts or bottom border reaching",
               expected_bottom_border == bottom_border_after_scroll
               || bottom_border_after_scroll == page.getContactCount()
        );
    }

    @Test
    public void generateNew50Contacts() {
        int expected_contact_count = page.getContactCount() + 50;
        page.generateNew50Contacts();

        assertTrue("Generated 50 contacts: Expected to generate new 20 contacts",
                expected_contact_count == page.getContactCount());

    }

    @Test
    public void updateContactName() {
        String new_first_name = "Test123";
        String new_last_name = "Test321";
        String expected_new_name = new_first_name + " " + new_last_name;

        page.getElementByRow(1).click();
        page.setInputFirstName(new_first_name);
        page.setInputLastName(new_last_name);
        page.updateContactClick();

        assertTrue("Update name: Expected to change name of contact",
                page.getElementNameByRow(1).equals(expected_new_name));
    }

    @After
    public void afterTests() {
        page.quit();
    }
}

